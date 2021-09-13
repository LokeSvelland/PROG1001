#include <ctype.h>      //  Håndtering av enkelt-tegn(/bokstaver)
#include <stdbool.h>    //  'bool' med 'true'/'false'  (istedet for '_Bool')
#include <stdio.h>      //  printf, scanf, fil-håndtering
#include <stdlib.h>	    //  Memory-håndtering, streng-konvertering, mer .....
#include <string.h>	    //  Håndtering av char-arrayer/tekster/strenger

const int STRLEN = 15;

int main() {

    char bok1[STRLEN],
         bok2[STRLEN];

    char sjanger[2];
    int  sideTall[2];
    int  sum,
         antallBoker;

    printf("Navn: ");           gets(bok1);
    printf("Antall sider: ");   scanf("%i", &sideTall[0]);  getchar();   //  NB !
    printf("sjanger (T - Fiksjon, T - Thriller, B - Biografi): "); scanf("%c", &sjanger[0]);

    printf("\nInnleste verdier fra Bok nr 1\n");
    printf("\tNavn:         %s\n", bok1);
    printf("\tAntall sider: %i\n", sideTall[0]);
    printf("\tSjanger:      %c\n", sjanger[0]);

    getchar();

    printf("\nNavn: ");         gets(bok2);
    printf("Antall sider: ");   scanf("%i", &sideTall[1]);  getchar();   //  NB !
    printf("sjanger (T - Fiksjon, T - Thriller, B - Biografi): "); scanf("%c", &sjanger[1]);

    printf("\nInnleste verdier fra Bok nr 2\n");
    printf("\tNavn:         %s\n", bok2);
    printf("\tAntall sider: %i\n", sideTall[1]);
    printf("\tSjanger:      %c\n", sjanger[1]);

    printf("\nNavn:    %s\n", bok1);
    printf("Sjanger:   %c\n", sjanger[0]);

    printf("\nNavn:    %s\n",   bok2);
    printf("Sjanger:   %c\n",   sjanger[1]);

   // antallBoker = bok1 + bok2;
    printf("\nBøker lest:        %i\n", antallBoker);
    sum = sideTall[0] + sideTall[1];
    printf("Sider lest totalt: %i\n", sum);


    return 0;
}
