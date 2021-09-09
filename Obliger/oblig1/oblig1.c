#include <ctype.h>      //  Håndtering av enkelt-tegn(/bokstaver)
#include <stdbool.h>    //  'bool' med 'true'/'false'  (istedet for '_Bool')
#include <stdio.h>      //  printf, scanf, fil-håndtering
#include <stdlib.h>	    //  Memory-håndtering, streng-konvertering, mer .....
#include <string.h>	    //  Håndtering av char-arrayer/tekster/strenger

const int STRLEN = 15;

int main() {

    char bok1[STRLEN] = "Doppler", 
         bok2[STRLEN] = "Min historie"; 

    char sjanger[] = {'B', 'F'};
    int sideTall[] = {158, 559};

    printf("Skriv inn navn på bok: ");   gets(bok1, bok2)

}