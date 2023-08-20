#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void write_numbers(const char* filename, uint64_t N){
    FILE *file = fopen(filename,"wb");
    if(!file){
        perror("Error while opening the file");
        exit(EXIT_FAILURE);
    }

    fwrite(&N, sizeof(uint64_t),1,file);
    fclose(file);
}

int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr,"Usage: %s <filename> <N> \n",argv[0]);
        return EXIT_FAILURE;
    }
    char* fileName = argv[1];
    uint64_t N = strtoull(argv[2],NULL,10);
    write_numbers(fileName,N);

    return EXIT_FAILURE;
}