#include <stdio.h>
#include <math.h>
#define PI 3.14159
/*Да се направи програма, която изчислява лицето на околната повърхнина и обемът на цилиндър по дадени радиус на основата r и височина h.

Да се създаде следната функция:
int cylinder(double r, double h, double* V, double* S);
При невалидни параметри (<= 0) функцията връща -1. При валидни параметри, функцията пресмята лицето и обема и ги запазва чрез указателите V и S.

Работата на програмата прочита по следния начин:
От стандартния вход се прочитат радиус и височината на цилиндъра (на един ред, разделени с интервали).
При некоректни данни се извежда съобщение за грешка на стандартния изход за грешки без да се прекратява програмата.
При коректни данни се изпечатват лицето на околната повърхнина и обемът на цилиндъра в стандартния изход.
*/

int cylinder(double r, double h, double* V, double* S){
    if(r <= 0 || h <= 0){
        printf("Invalid input");
        return -1;
    } 
    *V = PI * r * r * h;
    *S = 2 * PI * r * h;
    return 1;
}


int main(int argc, char* argv[]){
    double r,h;
    double V, S;

    printf("Radius and Height: ",r,h);
    scanf("%lf",&r);
    scanf("%lf",&h);

    int result = cylinder(r,h,&V,&S);
    if(result == 1){
        printf("V: %lf, S: %lf",V,S);
    }
    else{
        printf("Invalid!!!");
    }
}


