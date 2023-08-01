#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encodedNum(const char* number){
    if(number == NULL || number[0]=='\n'){
        return NULL;
    }

    size_t len =strlen(number);

    if(len > 500){
        return NULL;
    }

    char *encoded = (char*)malloc((len +1)*sizeof(char));
    char str[10] = {'!', '#','/','~','=','`','+','>','.','-'};
    for(size_t i=0; i<len; i++){
            if(i % 2 == 0){
                encoded[i] = 'A' + (number[i] - '0');
            }
            else{
                encoded[i] = str[number[i] - '0'];
            }
    }

    encoded[len] = '\0';
    return encoded;
    
}



int main(int argc, char* argv[]){
    char str[500]="10296126782646987676234";
    char* strstr = encodedNum(str);
    printf("%s\n",strstr);
    

}