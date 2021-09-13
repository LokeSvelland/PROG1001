/**
 *   Obligatorisk oppgave nr.1
 *
 *   @file     Oblig1.c
 *   @author   Loke Svelland
 */

#include <ctype.h>      //  Håndtering av enkelt-tegn(/bokstaver)
#include <stdio.h>      //  printf, scanf, fil-håndtering
#include <stdlib.h>	    //  Memory-håndtering, streng-konvertering, mer .....
#include <string.h>	    //  Håndtering av char-arrayer/tekster/strenger

const int STRLEN = 15;

int main() {

    char bok1[STRLEN],  // Lager 2 arrays til bok navn
         bok2[STRLEN];

    char sjanger[2];    // array for sjanger, sidetall, sum og antall bøker
    int  sideTall[2];
    int  sum,
         antallBoker;

                        //Her legges inn info til første bok
    printf("Bok 1:\n");
    printf("\tNavn: ");           gets(bok1);
    printf("\tAntall sider: ");   scanf("%i", &sideTall[0]);  getchar();
    printf("\tsjanger (T - Fiksjon, T - Thriller, B - Biografi): ");
    scanf("%c", &sjanger[0]);

    getchar();          //getchar() for å hoppe over den /n som henger igjen
                        //fra scanf

                        // Her legges inn info til bok nr 2
    printf("\nBok 2:\n");
    printf("\tNavn: ");         gets(bok2);
    printf("\tAntall sider: ");   scanf("%i", &sideTall[1]);  getchar();
    printf("\tsjanger (T - Fiksjon, T - Thriller, B - Biografi): ");
    scanf("%c", &sjanger[1]);

                        // printer ut navn og sjanger bok 1
    printf("\nNavn:    \t%s\n", bok1);
    printf("Sjanger:   \t%c\n", sjanger[0]);

                        // printer ut navn og sjanger bok 2
    printf("\nNavn:    \t%s\n",   bok2);
    printf("Sjanger:   \t%c\n",   sjanger[1]);
                        // plusser antall elementer i hver av arrayene så deler
                        // på størrelsen til 1 array, STRLEN er 15 i begge
                        // derfor kan jeg dele på 15 og finne hvor mange
                        // bøker som er lagt til
    antallBoker = (sizeof(bok1) + sizeof(bok2)) / 15;
    printf("\nBøker lest:        %i\n", antallBoker);
                        // summerer sidetall
    sum = sideTall[0] + sideTall[1];
    printf("Sider lest totalt: %i\n", sum);


    return 0;
}