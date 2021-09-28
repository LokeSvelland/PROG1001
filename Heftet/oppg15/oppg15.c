#include <stdio.h>

int main()
{

    int heltall1,       // tomme heltall
        heltall2,
        addert,         // for å addere
        subtrahert,     // for å subtrahere
        multiplisert;   // for å multiplisere

    char svar;          // leser inn brukers svar (J/n)

                        //  Så lenge ønsker (IKKE svart 'N'):
    while (svar != 'N' && svar != 'n')
    {                   // leser inn to heltall fra bruker
        printf("Skriv inn to heltall: \n");
        scanf("%d %d", &heltall1, &heltall2);

                        // adderer heltallene
        addert = heltall1 + heltall2;
        printf("\nTallene addert:\t\t %d + %d = %d\n\n",
               heltall1, heltall2, addert);

                        // Subtraherer heltallene
        subtrahert = heltall2 - heltall1;
        printf("Tallene subtrahert:\t %d - %d = %d\n\n",
               heltall2, heltall1, subtrahert);

                        // Multipliserer heltallene
        multiplisert = heltall1 * heltall2;
        printf("Tallene multiplisert:\t %d * %d = %d\n\n",
               heltall1, heltall2, multiplisert);

                        // spør bruker om de vil kjøre program på nytt
        printf("Kjøre programmet igjen? (J/n): \n");
        scanf(" %c", &svar); // NB! mellomrom!
    }
    return 0;
}
