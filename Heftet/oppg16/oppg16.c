#include <stdio.h>
#include <ctype.h>

const int MINVERDI = 1;     // Minste verdi
const int MAXVERDI = 10000; // Største verdi

int main()
{

    int innlestInt[5], // int array med 5 elementer
        i,
        heltall;

    char innlestChar[10]; // char array med 10 elementer

    for (i = 0; i < 5; i++)
    {
        printf("Skriv inn 5 heltall mellom 1 og 1000: \n");
        scanf("%d", &heltall);
        innlestInt[i] = heltall;
    }
 
    for (i = 0; i < 5; i++)
    {
        printf("%d ", innlestInt[i]);
    }
}