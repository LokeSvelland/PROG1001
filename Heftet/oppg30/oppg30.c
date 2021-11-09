/**
*
* Oppgave 30
*
* @author Loke Svelland
*/

#include <stdio.h>      //  printf, scanf
#include <ctype.h>      //  toupper
#include <stdlib.h>     //  sizeof, malloc, free
#include <string.h>     //  strlen, strcpy
#include <stdbool.h>    //  Bool

struct Tralle
{
    bool utlaant;
    char navn[80];
    int tlfNr; 
};

struct Tralle gTraller[30]; // Array av Tralle-struct'er.
int gAntallUtlaant = 0;     // Antall traller som pt. er utlånt.
const int MAXTRALLER = 30;  ///< Max. antall traller til utlån.

void  oversikt();
void  ledige();
void  utlaan();
void  innleveing();
void  finnLaaner();
char  lesKommando();
float lesTall(const char tekst[], const int min, const int max);
void  lesTekst(const char ledetekst[], char tekst[]);

/**
 *  Hovedprogrammet:
 */
int main ()  {
    char kommando;

    skrivMeny();
    kommando = lesKommando();

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'O':  oversikt();     break;   //  Oversikt over utlånt traller.
          case 'L':  ledige();       break;   //  legger nummer på alle ledige.
          case 'U':  utlaan();       break;   //  lån ut en tralle.
          case 'I':  innlevering();  break;   //  lever inn tralle.
          case 'F':  finnLaaner();   break;   //  finn låner til tralle.
          default :  skrivMeny();    break;   //  Ikke-eksisterende menyvalg.
        }
        kommando = lesKommando();
    }

    printf("\n\n");
    return 0;
}

/**
 * går gjennom alle trallene, og skrivet ut alle trallene som er utlånt
 * 
 */
void oversikt() {

    while(gTraller <= 30) {
        for(int i = 0; i < 30; i++) {
            if (gTraller[i].utlaant == 1)
            {
                printf("Utlånt tralle nummer: %d\n, Kunde: %s\n, tlf: %d\n", 
                i+1, gTraller->navn, gTraller->tlfNr);
            }
            
        }
    }
    printf("Ignen traller utlånt.\n");
}

/**
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @return  Ett (upcaset) tegn.
 */
 char lesKommando()  {
     char tegn;
     printf("\nSkriv kommando:  ");
     scanf(" %c", &tegn);   getchar();
     return (toupper(tegn));
}


/**
 *  Leser og returnerer et tall mellom to gitte grenser.
 *
 *  @param   tekst  - Ledetekst til brukeren når ber om input/et tall
 *  @param   min    - Minimum for innlest og godtatt tallverdi
 *  @param   max    - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Godtatt verdi i intervallet 'min - 'max'
 */
float lesTall(const char tekst[], const int min, const int max)  {
   float tall;
   do  {
     printf("\t%s (%i-%i):  ", tekst, min, max);
     scanf("%f", &tall);     getchar();
   } while (tall < min  ||  tall > max);
   return tall;
}


/**
 *  Leser tekst inn i medsendt char-array/tekst/string.
 *
 *  @param   ledetekst  - Ledetekst som utskrift til brukeren om hva lese inn
 *  @param   tekst      - char-array som fylles med innlest tekst
 */
void lesTekst(const char ledetekst[], char tekst[])  {
  printf("\t%s:  ", ledetekst);
  gets(tekst);                    //  Oppdaterer ORIGINALEN/aktuell parameter.
}

/**
 *  Skriver programmets menyvalg/muligheter på skjermen.
 */
void skrivMeny()  {
   printf("\nFølgende kommandoer er tilgjengelig:\n");
   printf("\tO = Oversikt over utleverte traller\n");
   printf("\tL = Ledige traller\n");
   printf("\tU = Lån tralle\n");
   printf("\tI = Lever inn tralle\n");
   printf("\tF = Finn låner av tralle\n");
   printf("\tQ - Quit / avslutt\n");
}