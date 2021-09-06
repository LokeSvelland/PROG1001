#include <stdio.h>
#include <stdlib.h>

int main() {
    int postnummer  = 2801,                                 //Helstalls variabler
        mobilnummer = 95558305,
        alder       = 19;

    char navn[]    = "Loke Svelland";                        //char arrays med tekst
    char adresse[] = "Ibsensgate 15";
    char sted[]    = "Gjøvik";

    printf("Navn: \t\t%s\n", navn);                         //printer ut svar
    printf("Adresse: \t%s\n", adresse);                     //la inn char array 6.9.21
    printf("Sted: \t\t%s %i\n", sted, postnummer);            
    printf("Mobilnr: \t%i\n", mobilnummer);
    printf("Alder: \t\t%i\n", alder);

    return 0;
}