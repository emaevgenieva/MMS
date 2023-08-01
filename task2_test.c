#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Car{
    char model[20];
    uint8_t maxspeed;
    double price;
}Car;

int compare_Model_inc(const void *p1, const void *p2){
    const struct Car* car1 = (const struct Car*)p1;
    const struct Car* car2 = (const struct Car*)p2;
    return strcmp(car1->model,car2->model);
}

int compare_Model_dec(const void *p1, const void *p2){
    const struct Car* car1 = (const struct Car*)p1;
    const struct Car* car2 = (const struct Car*)p2;
    return -strcmp(car1->model,car2->model);
}

int compare_Speed_inc(const void *p1, const void *p2){
    const struct Car* car1 = (const struct Car*)p1;
    const struct Car* car2 = (const struct Car*)p2;
    return car1->maxspeed - car2->maxspeed;
}

int compare_Speed_dec(const void *p1, const void *p2){
    const struct Car* car1 = (const struct Car*)p1;
    const struct Car* car2 = (const struct Car*)p2;
    return car2->maxspeed - car1->maxspeed;
}

int compare_Price_inc(const void *p1, const void *p2){
    const struct Car* car1 = (const struct Car*)p1;
    const struct Car* car2 = (const struct Car*)p2;
    if(car1->price < car2->price){
        return -1;
    }
    else if(car1->price > car2->price){
        return 1;
    }
    else{
        return 0;
    }
}

int compare_Price_dec(const void *p1, const void *p2){
    const struct Car* car1 = (const struct Car*)p1;
    const struct Car* car2 = (const struct Car*)p2;
    if(car1->price > car2->price){
        return -1;
    }
    else if(car1->price < car2->price){
        return 1;
    }
    else{
        return 0;
    }
}

int (*getcomparator(int n))(const void*,const void*){
    switch(n){
        case 1:
            return compare_Model_inc;
        case 2:
            return compare_Model_dec;
        case 3:
            return compare_Speed_inc;
        case 4:
            return compare_Speed_dec;
        case 5:
            return compare_Price_inc;
        case 6:
            return compare_Price_dec;

        default:
            return NULL;
    }
}

int main(int argc, char* argv[]){
    int n = 4;
    int (*comparator)(const void*, const void*) = getcomparator(n);

    struct Car cars[]={
                        {"Opel",200,45678928},
                        {"BMW",200,48963.20},
                        {"Citroen",250,78963}};
    size_t numCars = sizeof(cars) / sizeof(cars[0]);
    qsort(cars, numCars, sizeof(struct Car), compare_Price_inc);
    printf("Sorrted by prize inc: \n");
    for(size_t i=0; i<numCars; i++){
        printf("Model: %s\n, MaxSpeed: %u\n,Price: %.2f\n ", cars[i].model, cars[i].maxspeed, cars[i].price);
    }
    return 0;
}