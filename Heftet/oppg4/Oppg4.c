#include <stdio.h>
#include <stdlib.h>

int main() {
    int postnummer  = 2801,                                 //Helstalls variabler
        mobilnummer = 95558305,
        alder       = 19;


    printf("Navn: \t\tLoke Svelland\n");                    //printer ut svar, har lagt inn tekst her
    printf("Adresse: \tIbsensgate 15\n");                   //da jeg ikke får det til å fungere med
    printf("Sted: \t\tGjøvik %i\n", postnummer);            //char/int
    printf("Mobilnr: \t%i\n", mobilnummer);
    printf("Alder: \t\t%i\n", alder);

    return 0;
}