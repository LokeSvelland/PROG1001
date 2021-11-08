/**
 *  Obligatorisk Oppgave 4
 *
 *  Det er mulig Ã¥:
 *     - legge inn nye produsenter
 *     - legge inn nytt produkt hos en produsent
 *     - skrive ALLE produsenter
 *     - skrive ALLE produkter hos/for EN produsent
 *     - skrive ALLE produkter
 *     - slette ALLE produsenter og deres produkter
 *
 *  @file    Oblig4.c
 *  @author  Loke Svelland
 */


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//  #include "LesData.h"     //   Ligger pÃ¥ emnets EKSEMPLER-katalog.


#define MAXPRODUSENTER  50      ///< Max antall produsenter
#define MAXPRODUKTER    20      ///< Max antall produkter hos hver produsent
const int STRLEN  =    100;     ///< Max tekstlengde
const int MAXPRIS = 100000;     ///< Max pris


/**
 *  Produkt (med navn, beskrivelse, pris).
 */
struct Produkt {
    char  *navn, *beskrivelse;
    int   pris;
};


/**
 *  Produsent (med navn, by, antallprodukter, og array med produktene).
 */
struct Produsent {
    char   *navn, *by;
    int    antallProdukter;
    struct Produkt* produktene[MAXPRODUKTER];
};


struct Produkt* finnProdukt(const struct Produsent* produsent, const char* navn);
struct Produsent* finnProdusent(const char* navn);
void   fjernAllkokerteData();
void   leggTilEttProdukt();
void   nyProdusent();
void   produktLesData(struct Produkt* produkt, const char* navn);
void   produktSkrivData(const struct Produkt* produkt);
void   produktSlettData(struct Produkt* produkt);
void   produsentLesData(struct Produsent* produsent, const char* navn);
void   produsentNyttProdukt(struct Produsent* produsent, const char* navn);
void   produsentSkrivData(const struct Produsent* produsent);
void   produsentSlettData(struct Produsent* produsent);
void   skrivAbsoluttAlt();
void   skrivMeny();


struct Produsent* gProdusentene[MAXPRODUSENTER];    ///< Alle produsentene.
int gAntallProdusenter = 0;         ///< Antall produsenter registrert hittil.


/**
 *  Hovedprogrammet.
 */
int main() {
    char kommando;

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q')  {
        switch (kommando) {
            case 'N': nyProdusent();         break;
            case 'L': leggTilEttProdukt();   break;
            case 'A': skrivAbsoluttAlt();    break;
            default:  skrivMeny();           break;
        }
        kommando = lesChar("\nKommando");
    };

    fjernAllkokerteData();

return 0;
}


/**
 *  Returnerer (om mulig) peker til et navngitt produkt hos en produsent.
 *
 *  @param    produsent  - Produsenten for produktet
 *  @param    navn       - Navnet til produktet
 *  @return   Peker til produktet eller NULL
 */
struct Produkt* finnProdukt(const struct Produsent* produsent, const char* navn) {

    while (*produsent->navn)
    {
        printf("Hvilket produkt ser du etter: ");
        scanf(" %c", &navn);
        return *navn; 
    }
    return NULL;
}


/**
 *  Returnerer (om mulig) peker til en navngitt produsent.
 *
 *  @param    navn   - Navnet til produsenten
 *  @return   Peker til produsenten eller NULL
 */
struct Produsent* finnProdusent(const char* navn) {

while (*navn)
{
    printf("Hvilken produsent leter du etter: ");
    scanf(" %c", &navn);
    return *navn;
}
return NULL;
}


/**
 *  Fjerner ALLE allokerte data fra minnet/memory.
 *
 *  @see   produsentSlettData(...)
 */
void fjernAllkokerteData() {

//     Lag innmaten
}


/**
 *  Legger til (om mulig) ETT nytt produkt hos en produsent.
 *
 *  @see   finnProdusent(...)
 *  @see   finnProdukt(...)
 *  @see   produsentNyttProdukt(...)
 */
void leggTilEttProdukt()  {

//     Lag innmaten
}


/**
 *  Legger inn (om mulig) en ny produsent.
 *
 *  @see   finnProdusent(...)
 *  @see   produsentLesData(...)
 */
void nyProdusent()  {

//     Lag innmaten
}


/**
 *  Leser inn ALLE dataene om ETT produkt.
 *
 *  @param   produkt  - Produktet som fÃ¥r sine data lest inn
 *  @param   navn     - Hittil innlest produktnavn
 */
void produktLesData(struct Produkt* produkt, const char* navn){

//     Lag innmaten
}


/**
 *  Skriver ALLE et produkts data pÃ¥ skjermen.
 *
 *  @param   produkt  - Produktet hvis alle data skrives ut.
 */
void produktSkrivData(const struct Produkt* produkt) {

//     Lag innmaten
}


/**
 *  Sletter ALLE et produkts allokerte data fra minnet.
 *
 *  @param   produkt  - Produktet som fÃ¥r slettet sine allokerte data
 */
void produktSlettData(struct Produkt* produkt) {

//     Lag innmaten
}


/**
 *  Leser inn en produsents data, inkl initielle produkter.
 *
 *  @param   produsent  - Produsenten som det leses inn data til
 *  @param   navn       - Navnet til produsenten
 *  @see     finnProdukt(...)
 *  @see     produsentNyttProdukt(...)
 */
void produsentLesData(struct Produsent* produsent, const char* navn){

//     Lag innmaten
}


/**
 *  Legger enn ETT nytt produkt hos en produsent.
 *
 *  @param   produsent  -  Produsenten Ã¥ legge inn nytt produkt hos
 *  @param   navn       -  Nytt produkts navn
 *  @see     produktLesData(...)
 */
void produsentNyttProdukt(struct Produsent* produsent, const char* navn)  {

//     Lag innmaten
}


/**
 *  Skriver ALLE en produsents data ut pÃ¥ skjermen.
 *
 *  @param    produsent  - Produsenten hvis alle data skrives ut.
 *  @see      produktSkrivData(...)
 */
void produsentSkrivData(const struct Produsent* produsent) {

//     Lag innmaten
}


/**
 *  Sletter ALLE en produsents allokerte data fra minnet.
 *
 *  @param   produsent  - Produsenten som fÃ¥r slettet sine allokerte data
 *  @see     produktSlettData(...)
 */
void produsentSlettData(struct Produsent* produsent) {

//     Lag innmaten
}


/**
 *  Skriver alt om alle produsenter.
 *
 *  @see   produsentSkrivData(...)
 */
void skrivAbsoluttAlt()  {

//     Lag innmaten
}


/**
 *  Skriver alle kommandoene tilgjengelig i programmet.
 */
void skrivMeny() {
  printf("\nProgrammets kommandoer:");
  printf("\n\tN - Ny  produsent (og produkter)");
  printf("\n\tL - Legg til ett produkt hos en produsent");
  printf("\n\tA - skriv Alle produsenter og alle deres produkter");
  printf("\n\tQ - Quit/avslutt\n");
}