#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct rowData{
    int row;
    int *numbers;
    int m;
    double average;

}rowData;

void *calculate_average(void *arg){
    rowData *data = (rowData*) arg;
    int sum = 0;
    for(int i=0; i<data->m; i++){
        sum += data->numbers[i];
    }
    data->average = (double)sum / data->m;

    return NULL;
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    rowData rows[n];

    for(int i= 0; i<n; i++){
        char tmp[4];
        scanf("%s %d", tmp, &(rows[i].row));

        rows[i].numbers = (int*)malloc(m*sizeof(int));
        rows[i].m = m;

        for(int j=0; j<m; j++){
            scanf("%d", &(rows[i].numbers[j]));
        }
    }

    char filename[100];
    scanf("%s",filename);

    FILE *file = fopen(filename, "r");
    if(file){
        printf("File already exist.\n");
        fclose(file);

        return 1;
    }

    pthread_t threads[n];
    for(int i=0; i<n; i++){
        pthread_create(&threads[i],NULL,calculate_average,&rows[i]);
    }
    for(int i=0; i<n; i++){
        pthread_join(threads[i],NULL);
    }


    file = fopen(filename, "w");
    for(int i=0; i<n; i++){
        fprintf(file,"ROW %d %.3lf\n", rows[i].row, rows[i].average);
        free(rows[i].numbers);
    }
    fclose(file);
    
    return 0;
}