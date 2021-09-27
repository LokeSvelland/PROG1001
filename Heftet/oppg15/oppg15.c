#include <stdio.h>

/*
*stopper uansett hva som skrives inn i (J/n)
*/

int main()
{

    int heltall1,
        heltall2,
        addert,
        subtrahert,
        multiplisert;

    char svar;

    printf("Skriv inn to heltall: \n");
    scanf("%d %d", &heltall1, &heltall2);

    addert = heltall1 + heltall2;
    printf("\nTallene addert:\t\t %d + %d = %d\n\n",
           heltall1, heltall2, addert);

    subtrahert = heltall2 - heltall1;
    printf("Tallene subtrahert:\t %d - %d = %d\n\n",
           heltall2, heltall1, subtrahert);

    multiplisert = heltall1 * heltall2;
    printf("Tallene multiplisert:\t %d * %d = %d\n\n",
           heltall1, heltall2, multiplisert);
    printf("Kjøre programmet igjen? (J/n): \n");
    scanf("%c", &svar);
    getchar();

    //  Så lenge ønsker (IKKE svart 'N'):
    while (svar != 'N' && svar != 'n')
    {
        return 0;
    }
}
