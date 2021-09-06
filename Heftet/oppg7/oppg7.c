#include <stdio.h>
#include <stdlib.h>


int main() {
    int tall1 = 4, tall2 = 5, tall3 = 3, sum, kvadratSum;      // lager 3 heltallsvariabler + sum og gjennomsintt
    float flyt1 = 5, flyt2 = 6, gjsnittSum, gjsnittKvadrat;    // lager 2 flyttallsvariabler + gjen.snittsum og gjen.snittkvadrat

    sum = tall1 + tall2 + tall3;

    gjsnittSum = sum/3.0;

    kvadratSum = (tall1*tall1) + (tall2*tall2) + (tall3*tall3);

    gjsnittKvadrat = kvadratSum/3.0;

    printf("tall1: %i, tall2: %i, tall3: %i, summen av tallene: %i\n", tall1, tall2, tall3, sum);
    printf("gjennomsnittet av summen til tall1-3 er lik: %f\n", gjsnittSum);
    printf("summen av alle heltallene kvadrert er: %i\n", kvadratSum);
    printf("Gjennomsnittet av summen kvardratene er: %f\n", gjsnittKvadrat);
    printf("gjennomsnitt av flyt1 og flyt2 er: %f", (flyt1+flyt2)/2.0);

    return 0;
}