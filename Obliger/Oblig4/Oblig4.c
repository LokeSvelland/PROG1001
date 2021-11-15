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
#include "LesData.h"

#define MAXPRODUSENTER 50   ///< Max antall produsenter
#define MAXPRODUKTER 20     ///< Max antall produkter hos hver produsent
const int STRLEN = 100;     ///< Max tekstlengde
const int MAXPRIS = 100000; ///< Max pris

/**
 *  Produsent (med navn, by, antallprodukter, og array med produktene).
 */
struct Produsent
{
    char *navn, *by;
    int antallProdukter;
    struct Produkt *produktene[MAXPRODUKTER];
};

/**
 *  Produkt (med navn, beskrivelse, pris).
 */
struct Produkt
{
    char *navn, *beskrivelse;
    int pris;
};

struct Produkt *finnProdukt(const struct Produsent *produsent, const char *navn);
struct Produsent *finnProdusent(const char *navn);
void fjernAllkokerteData();
void leggTilEttProdukt();
void nyProdusent();
void produktLesData(struct Produkt *produkt, const char *navn);
void produktSkrivData(const struct Produkt *produkt);
void produktSlettData(struct Produkt *produkt);
void produsentLesData(struct Produsent *produsent, const char *navn);
void produsentNyttProdukt(struct Produsent *produsent, const char *navn);
void produsentSkrivData(const struct Produsent *produsent);
void produsentSlettData(struct Produsent *produsent);
void skrivAbsoluttAlt();
void skrivMeny();

struct Produsent *gProdusentene[MAXPRODUSENTER]; ///< Alle produsentene.
int gAntallProdusenter = 0;                      ///< Antall produsenter registrert hittil.

/**
 *  Hovedprogrammet.
 */
int main()
{
    char kommando;

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q')
    {
        switch (kommando)
        {
        case 'N':
            nyProdusent();
            break;
        case 'L':
            leggTilEttProdukt();
            break;
        case 'A':
            skrivAbsoluttAlt();
            break;
        default:
            skrivMeny();
            break;
        }
        kommando = lesChar("\nKommando");
    };

    fjernAllkokerteData();

    return 0;
}

/**
 *  Returnerer (om mulig) peker til en navngitt produsent.
 *
 *  @param    navn   - Navnet til produsenten
 *  @return   Peker til produsenten eller NULL
 */
struct Produsent *finnProdusent(const char *navn)
{                       // går gjennom alle produsenter opp til antall lagt inn
    for (int i = 0; i < gAntallProdusenter; i++)
    {                   // sammenligner registrert med innlest
        if (!strcmp(gProdusentene[i]->navn, navn))
                        // returnerer pointer til registrert navn
            return gProdusentene[i];
    }
    return NULL;
}

/**
 *  Returnerer (om mulig) peker til et navngitt produkt hos en produsent.
 *
 *  @param    produsent  - Produsenten for produktet
 *  @param    navn       - Navnet til produktet
 *  @return   Peker til produktet eller NULL
 */
struct Produkt *finnProdukt(const struct Produsent *produsent, const char *navn)
{
    for (int i = 0; i < produsent->antallProdukter; i++)
    {                   // går gjennom alle produsenter og produkter registrert
        if (!strcmp(produsent->produktene[i]->navn, navn))
                        // returnerer pointer til produktet
            return produsent->produktene[i];
    }
    return NULL;
}

/**
 *  Fjerner ALLE allokerte data fra minnet/memory.
 *
 *  @see   produsentSlettData(...)
 */
void fjernAllkokerteData()
{

    printf("\n\n\tFrigir all allokert/avsatt memory .....\n\n");
    for (int i = 0; i < gAntallProdusenter; i++)
    {                   // går gjennom alle produsenter og frigir memory
        produsentSlettData(gProdusentene[i]);
    }
}

/**
 *  Legger til (om mulig) ETT nytt produkt hos en produsent.
 *
 *  @see   finnProdusent(...)
 *  @see   finnProdukt(...)
 *  @see   produsentNyttProdukt(...)
 */
void leggTilEttProdukt()
{
    char levNavn[STRLEN]; // navn på produsent
    char *prodNavn;       // Nytt produkt
    if (0 < gAntallProdusenter < MAXPRODUSENTER)
    {                   // leser inn navn på produsent
        lesText("\tProdusentens navn", levNavn, STRLEN);
        if (finnProdusent(levNavn) != NULL)
        {               // sjekker om produsent er registrert eller ikke
            prodNavn = lagOgLesText("\tProduktets navn");
                        // leser inn nytt navn til produkt
            if (finnProdukt(gProdusentene[gAntallProdusenter], prodNavn) == NULL)
            {           // hvis produkt allerede finnes returneres melding
                produsentNyttProdukt(gProdusentene[gAntallProdusenter], prodNavn);
            }
            else
            {
                printf("\tprodukt finnes allerede\n");
            }
        }
        else
        {
            printf("\tProdusent finnes ikke\n");
        }
    }
    else
    {
        printf("\tIngen/alle produsenter registrert.\n");
    }
}

/**
 *  Legger inn (om mulig) en ny produsent.
 *
 *  @see   finnProdusent(...)
 *  @see   produsentLesData(...)
 */
void nyProdusent()
{
    char *navn;         // Ny produsent navn
    if (gAntallProdusenter < MAXPRODUSENTER)
    {                   // leser inn ny produsent navn
        navn = lagOgLesText("\tNy produsent");
        if (finnProdusent(navn) == NULL)
        {               // allokerer plass til ny produsent
            gProdusentene[gAntallProdusenter] = (struct Produsent *)malloc(sizeof(struct Produsent));
            produsentLesData(gProdusentene[gAntallProdusenter], navn);
            gAntallProdusenter++; // legger til en ny produsent
        }
        else
        {
            printf("\tProdusent allerede registrert");
        }
    }
    else
    {
        printf("\tKan ikke legge til flere produsenter.\n");
    }
}

/**
 *  Leser inn ALLE dataene om ETT produkt.
 *
 *  @param   produkt  - Produktet som fÃ¥r sine data lest inn
 *  @param   navn     - Hittil innlest produktnavn
 */
void produktLesData(struct Produkt *produkt, const char *navn)
{
    produkt->navn = navn;
    produkt->beskrivelse = lagOgLesText("\tKort beskrivelse");
    produkt->pris = lesInt("\tPris", 0, MAXPRIS);
}

/**
 *  Skriver ALLE et produkts data pÃ¥ skjermen.
 *
 *  @param   produkt  - Produktet hvis alle data skrives ut.
 */
void produktSkrivData(const struct Produkt *produkt)
{
    printf("\tNavn             : %s\n", produkt->navn);
    printf("\tBeskrivelse      : %s\n", produkt->beskrivelse);
    printf("\tPris             : %i\n\n", produkt->pris);
}

/**
 *  Sletter ALLE et produkts allokerte data fra minnet.
 *
 *  @param   produkt  - Produktet som får slettet sine allokerte data
 */
void produktSlettData(struct Produkt *produkt)
{
    free(produkt->navn);
    free(produkt->beskrivelse);
    free(produkt->pris);
}

/**
 *  Leser inn en produsents data, inkl initielle produkter.
 *
 *  @param   produsent  - Produsenten som det leses inn data til
 *  @param   navn       - Navnet til produsenten
 *  @see     finnProdukt(...)
 *  @see     produsentNyttProdukt(...)
 */
void produsentLesData(struct Produsent *produsent, const char *navn)
{
    char kommando;
    char *produkt;
                        // lagrer vekk navn og tar imot ny info
    produsent->navn = navn;
    produsent->by = lagOgLesText("\tByen produsent er allokert i");
    produsent->antallProdukter = 0;
    do                  // så lenge svar er J så legges nytt produkt til
    {
                        // leser inn nytt produkt navn
        produkt = lagOgLesText("\tNavn på produkt");
        if (finnProdukt(gProdusentene[gAntallProdusenter], produkt) == NULL)
        {               // hvis produkt ikke finnes leses inn data
            produsentNyttProdukt(produsent, produkt);
        }
        else
        {
            printf("\tProdukt allerede registrert");
        }
        kommando = lesChar("\n\tFlere produkter (n/J)?");
    } while (kommando == 'J');
}

/**
 *  Legger enn ETT nytt produkt hos en produsent.
 *
 *  @param   produsent  -  Produsenten Ã¥ legge inn nytt produkt hos
 *  @param   navn       -  Nytt produkts navn
 *  @see     produktLesData(...)
 */
void produsentNyttProdukt(struct Produsent *produsent, const char *navn)
{
                        // allokerer plass til nytt produkt
    produsent->produktene[produsent->antallProdukter] = (struct Produkt *)malloc(sizeof(struct Produkt));
                        // leser inn data til produktet
    produktLesData(produsent->produktene[produsent->antallProdukter], navn);
                        // teller opp nytt produkt
    produsent->antallProdukter++;
}

/**
 *  Skriver ALLE en produsents data ut på skjermen.
 *
 *  @param    produsent  - Produsenten hvis alle data skrives ut.
 *  @see      produktSkrivData(...)
 */
void produsentSkrivData(const struct Produsent *produsent)
{
    printf("\tProdusentens navn:  %s\n", produsent->navn);
    printf("\tProdusentens by  :  %s\n", produsent->by);
    printf("\tAntall produkter :  %i\n", produsent->antallProdukter);
    for (int i = 0; i < produsent->antallProdukter; i++)
    {
        produktSkrivData(produsent->produktene[i]);
    }
}

/**
 *  Sletter ALLE en produsents allokerte data fra minnet.
 *
 *  @param   produsent  - Produsenten som får slettet sine allokerte data
 *  @see     produktSlettData(...)
 */
void produsentSlettData(struct Produsent *produsent)
{
    free(produsent->navn);
    free(produsent->by);
    free(produsent->antallProdukter);
    produktSlettData(produsent->produktene[produsent->antallProdukter]);
}

/**
 *  Skriver alt om alle produsenter.
 *
 *  @see   produsentSkrivData(...)
 */
void skrivAbsoluttAlt()
{
    if (gAntallProdusenter > 0)
    {
        printf("Alle produsenter: \n\n");
        for (int i = 0; i < gAntallProdusenter; i++)
        {               // teller opp antall produsenter og går gjennom alle
                        // og skriver ut deres data
            produsentSkrivData(gProdusentene[i]);
        }
    }
    else
    {
        printf("\n\tIngen Produsenter registrert\n\n");
    }
}

/**
 *  Skriver alle kommandoene tilgjengelig i programmet.
 */
void skrivMeny()
{
    printf("\nProgrammets kommandoer:");
    printf("\n\tN - Ny produsent (og produkter)");
    printf("\n\tL - Legg til ett produkt hos en produsent");
    printf("\n\tA - skriv Alle produsenter og alle deres produkter");
    printf("\n\tQ - Quit/avslutt\n");
}
