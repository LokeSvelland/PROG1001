#include <stdio.h>
#include <stdlib.h>

int main () {

    char tegn1 = 'F',
         tegn2 = 'H',
         tegn3 = 'b';

    float flyt1 = 17.52,
          flyt2 = 451.87;

    int heltall1,
        heltall2,
        tegnHeltall1,
        tegnHeltall2;

    printf("verdiene baklengs ift. definisjons-rekkefølge; tegn %c, %c; Tall: %f, %f\n", tegn2, tegn1, flyt2, flyt1);
    printf("flyt2 på eksponesiell form: %e\n", flyt2);

    heltall1 = flyt1;
    heltall2 = flyt2;
    printf("flytallene(%f, %f) som heltall: %i, %i\n", flyt1, flyt2, heltall1, heltall2);

    tegnHeltall1 = (int) tegn1;
    printf("%c castet som int: %i\n", tegn1, tegnHeltall1);

    tegnHeltall2 = (int) tegn3;
    printf("%c castet som int: %i\n", tegn3, tegnHeltall2);

    return 0;
}