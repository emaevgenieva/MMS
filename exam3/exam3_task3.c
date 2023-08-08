#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Product{
     double old_price;
     double new_price;
     unsigned int id;
     char product_type;
     char product_name[20];
}Product;

double getRandomPrice(){
     return 4.99 + (rand() % 1000) / 100.0;
}

char getRandomProductType(){
     char prodTypes[] = {'A','B','C','D'};
     int idx = rand() % 4;
     return prodTypes[idx];
}

void generateRandomName(char* name){
     char* prodNames[] = {
                           "Product 1",
                           "Product 2",
                           "Product 3",
                           "Product 4",
                           "Product 5"};
     
     int idx = rand() % 5;
     strcpy(name, prodNames[idx]);
}

int cmp_price_inc(const void* a, const void* b){
     const Product* p1 = (Product*)a;
     const Product* p2 = (Product*)b;

     double inc_p1 = p1->new_price - p1->old_price;
     double inc_p2 = p2->new_price - p2->old_price;

     if(inc_p1 < inc_p2){
          return 1;
     }
     else if(inc_p1 > inc_p2){
          return -1;
     }
     else{
          if(p1->product_type != p2->product_type){
               return p2->product_type - p1->product_type;
          }
          else{
               int name_cmp = strcmp(p1->product_name, p2->product_name);
               if(name_cmp != 0){
                    return name_cmp;
               }
               else{
                    return p1->id - p2->id;
               }
          }
     }
}

// void writeProductsToFile(struct Product *products, size_t numProducts, const char *filename) {
//     FILE *file = fopen(filename, "wb");
//     if (!file) {
//         perror("Error while opening file");
//         exit(-1);
//     }

//     fwrite(products, sizeof(struct Product), numProducts, file);

//     fclose(file);
// }

int main(void){
     struct Product products[5];

     for(int i = 0; i < 5; i++){
        products[i].old_price = getRandomPrice();
        products[i].new_price = getRandomPrice();
        products[i].id = i + 1;
        products[i].product_type = getRandomProductType();
        generateRandomName(products[i].product_name);
     }

     printf("====Before sorting:====\n");
     printf("\n");
     for(int i = 0; i < 5; i++){
        printf("Product ID: %u\n", products[i].id);
        printf("Product type: %c\n", products[i].product_type);
        printf("Product name: %s\n", products[i].product_name);
        printf("Old price of the product: %.2f\n", products[i].old_price);
        printf("New price of the product: %.2f\n\n", products[i].new_price);
     }

     qsort(products, 5, sizeof(Product),cmp_price_inc);

     printf("======After sorting:=====\n");
     printf("\n");

     for(int i = 0; i < 5; i++){
        printf("Product ID: %u\n", products[i].id);
        printf("Product type: %c\n", products[i].product_type);
        printf("Product name: %s\n", products[i].product_name);
        printf("Old price of the product: %.2f\n", products[i].old_price);
        printf("New price of the product: %.2f\n\n", products[i].new_price);
     }
     
     //writeProductsToFile(products, 5, "my_products.bin");

    return 0;
}