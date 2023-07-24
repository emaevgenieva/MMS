#include <stdio.h>

/*Създайте следната функция:

void subseq(int arr[], int n, int dest[], int *new_n);

Функцията намира най-дългата последователна намаляваща подредица в масива arr. 
Намерената подредица се запазва в dest. 
Броят на елементите в dest се предава чрез указателя new_n.

От стандартния вход се прочита N и след това N на брой цели числа. 
Използвайте subseq, за да намерите най-дългата последователна намаляваща подредица. 
Изпечатайте подредицата и нейния размер на стандартния изход.

Примерен вход:
10
5 4 3 2 1 10 11 2 3 4
Примерен изход:
5
5 4 3 2 1
*/

void subseq(int arr[], int n, int dest[], int *new_n){
    int min_length = 1; 
    int current_length = 1;
    int max_index = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1]){
            current_length++;
        } 
        else{
            if(current_length > min_length){
                min_length = current_length;
                max_index = i - current_length; 
            }
            current_length = 1;
        }
    }

    if(current_length > min_length){
        min_length = current_length;
        max_index = n - current_length; 
    }

    for(int i = 0; i < min_length; i++){
        dest[i] = arr[max_index + i];
    }

    *new_n = min_length;
}

int main(void){
    // int array[] = {1,10,9,7,11};
    // int size = sizeof(array) / sizeof(array[0]);
    int array[100];
    int size;
    printf("Size of the array is:");
    scanf("%d",&size);
    printf("The elements of the array are: ");
    for(int i=0; i<size; i++){
        scanf("%d",&array[i]);
    }

    int dest[100];
    int new_n;

    subseq(array, size, dest, &new_n);

    int counter = 0;
    printf("Longest Descending Subsequence: ");
    for (int i = 0; i < new_n; i++) {
        counter++;
        printf("%d ", dest[i]);
        //counter++;
    }
    printf("The lenght is : %d\n",counter);

    return 0;
    
}
