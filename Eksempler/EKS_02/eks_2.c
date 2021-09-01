#include <stdio.h>                             //printf

//hovedprogram
int main() {
    int value1, value2 = 10, sum;             //3 helltallsvariabler - initierer den ene 

//  Eller:
//     int value1;
//     int value2 = 10;
//     int sum;
//
//  Eller:
//     int value1,
//         value2 = 10,
//         sum;

    printf("The sum of %i and %i is %i\n", value1, value2, sum);  //utskift hvor 2x variabler er søppel

    value1 = 20;
    
    sum = value1 + (value2 * 3);
    printf("The sum of %i and %i*3 is %i\n", value1, value2, sum);

    sum = (value1 / 3) + (value2 * 3);
    printf("The sum of %i/3 and %i*3 is %i\n", value1, value2, sum);

    sum = value1 / 3 + value2 * 3;
    printf("The sum of %i/3 and %i*3 is %i\n", value1, value2, sum);

    sum = (value1 / 3 + value2) * 3;
    printf("The sum of (%i/3 and %i)*3 is %i\n", value1, value2, sum);

    printf("\n\n\t\tInnrykket tekst over");
    printf("\nflere\n\tlinjer\n\n!!!!\n---\n\n");

                          //  Eller EKSAKT ALT det samme i EN setning:
    printf("\n\n\t\tInnrykket tekst over\nflere\n\tlinjer\n\n!!!!\n---\n\n");

    return 0;
}