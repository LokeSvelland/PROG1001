#include <stdio.h>
#include <stdbool.h>

int main()
{

    int sum = 0, // variabler + arrays som brukes i programmet
        i,
        tall[10],
        snitt = 0;

    do
    {
        printf("Skriv inn kun positive tall: \n");
        scanf("%d", &tall[10]);
    } while (tall[10] > 0);
    do
    {
        sum = 0;
        (float) snitt = 0;
        printf("negativt tall eller 0 skrevet inn, program stopper\n");
        printf("alle innskrevne tall: %d\n", tall[10]);
        printf("summen av alle tallene: %d\n", sum);
        printf("gjennomsnitt av alle tallene: %.2f\n", snitt);
        return 0;
    } while (tall[10] == 0 || -tall[10]);
}
