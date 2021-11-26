/**
 *   Skjelett kontinuasjonseksamen i GrProg (i C), august 2021, oppgave 2.
 *
 *   Programmet holder orden på ulike rakfisk- og pultostprodukter,
 *   og hvem som har produsert disse.
 *
 *   @file     EX_S21_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen, strstr
#include <stdbool.h>             //  bool, true, false
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXPRODUKTER  200      ///<  Max. antall produkter.
#define   ANTPRODUSENTER  5      ///<  Max. antall produsenter.
const int STRLEN   =     80;     ///<  Max. tekstlengde.
const int MAXKILO  = 100000;     ///<  Max. antall kilo årlig produsert.


/**
 *  Type (et produkt er enten 'Rakfisk' eller 'Pultost').
 */
enum Type { Rakfisk,  Pultost };


/**
 *  Produkt (med navn, produkttype, produsentens nr/indeks og årlige kilo).
 */
struct Produkt {
    char* navn;                  //  Produktets navn/beskrivelse.
    enum Type type;              //  Produkttype:  Rakfisk eller Pultost.
    int produsentNr;             //  Produsentens nr (navn)  - 0 til 4.
    int antallKg;                //  Ca. antall kilo i årlig produksjon.
};


void skrivMeny();
enum Type lesType();
void skrivAlleProduktene();                                    //  Oppgave 2A
void produktSkrivData(const struct Produkt* p);                //  Oppgave 2A
void nyttProdukt();                                            //  Oppgave 2B
void produktLesData(struct Produkt* p);                        //  Oppgave 2B
void skrivAlleAvType();                                        //  Oppgave 2C
bool produktErType(const struct Produkt* p, enum Type t);      //  Oppgave 2C
void endreKilo();                                              //  Oppgave 2D
void produktEndreKilo(struct Produkt* p);                      //  Oppgave 2D
void skrivAlleMedNavn();                                       //  Oppgave 2E
bool produktMedSubtekst(const struct Produkt* p,const char* nvn);  // Oppg.2E
void skrivTilFil();                                            //  Oppgave 2F
void produktSkrivTilFil(FILE* ut, const struct Produkt* p);    //  Oppgave 2F
void lesFraFil();                                              //  Oppgave 2G
void produktLesFraFil(FILE* inn, struct Produkt* p);           //  Oppgave 2G


int    gAntallProdukter;             ///<  Antall produkter hittil registrert.
struct Produkt* gProdukter[MAXPRODUKTER];  ///<  Alle produktene.
char*  gProdusent[ANTPRODUSENTER] =        ///<  Aktuelle produsentnavn.
         { "LofossBakken", "TineRøn", "WangenFinden",
           "HaademHolen", "SynnøveNoraker" };


/**
 *  Hovedprogrammet:
 */
int main()  {
    char kommando;

    lesFraFil();                                            //  Oppgave 2G

    skrivMeny();
    kommando = lesChar("\nØnske");

    while (kommando != 'Q') {
        switch (kommando) {
           case 'A': skrivAlleProduktene();         break;  //  Oppgave 2A
           case 'N': nyttProdukt();                 break;  //  Oppgave 2B
           case 'T': skrivAlleAvType();             break;  //  Oppgave 2C
           case 'E': endreKilo();                   break;  //  Oppgave 2D
           case 'I': skrivAlleMedNavn();            break;  //  Oppgave 2E
           default:  skrivMeny();                   break;
        }
        kommando = lesChar("\nØnske");
    }

    skrivTilFil();                                          //  Oppgave 2F

    return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
    printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tA   = skriv Alle produktene\n");
    printf("\tN   = Ny produkt\n");
    printf("\tT   = skriv produktene av en Type\n");
    printf("\tE   = Endre ca.antall kilo årlig produsert\n");
    printf("\tI   = skriv produktene Inneholdende tekst i navnet\n");
    printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Leser forbokstaven i 'Rakfisk/Pultost', og returnerer aktuell enum-verdi.
 *
 *  @return  Enum-verdi ut fra forbokstaven i enum-verdien
 */
enum Type lesType() {
  char tegn;
  do  {                                               //  Leser og sikrer kun
    tegn = lesChar("\tType (R(akfisk), P(ultost))");  //    bokstavene
  } while (tegn != 'R'  &&  tegn != 'P');             //    'R' og 'P'.
  return ((tegn == 'R') ? Rakfisk : Pultost);         //  Returnerer aktuell
}                                                     //    enum-verdi.


/**
 *  Oppgave 2A - Skriver ALT om ALLE produkter.
 *
 *  @see   produktSkrivData(...)
 */
void skrivAlleProduktene() {

    int i;

    for(i = 0; i < gAntallProdukter; i++) {
        printf("\n\tProdukt nr. %i", i + 1);
        produktSkrivData(gProdukter[i]);
    }
}


/**
 *  Oppgave 2A - Skriver ALT om ETT produkt ut på skjermen.
 *
 *  @param   p - Produktet som skrives ut
 */
void produktSkrivData(const struct Produkt* p)  {

    printf("\n\tNavn: %s", p->navn);
    switch (p->type) {
        case Rakfisk: printf("\n\tRakfisk");    break;
        case Pultost: printf("\n\tPultost");    break;
    }
    switch (p->produsentNr)  {               //  Gjør om 'produsentNr'
    case 0:
        printf("\n\tLofossBakken");         break;
    case 1:
        printf("\n\tTineRøn");              break;
    case 2:
        printf("\n\tWangenFinden");         break;
    case 3:
        printf("\n\tHaademHolen");          break;
    case 4:
        printf("\n\tSynnøveNoraker");       break;
    }
    printf("\n\tAntall KG: %i\n\n", p->antallKg);
}


/**
 *  Oppgave 2B - Legger inn (om mulig) et nytt produkt i datastrukturen.
 *
 *  @see   produktLesData(...)
 */
void nyttProdukt() {

    char *ny;

    if(gAntallProdukter < MAXPRODUKTER) {
        printf("\n\tNytt produkt nr. %i", gAntallProdukter + 1);
        gProdukter[gAntallProdukter] = (struct Produkt*) malloc(sizeof(struct Produkt));
        produktLesData(gProdukter[gAntallProdukter]);
        gAntallProdukter++;
    } else {
        printf("\n\tAllerede fult opp med %i prdukter", MAXPRODUKTER);
    }
}


/**
 *  Oppgave 2B - Leser inn alle relevante datamedlemmer.
 *
 *  @param   p -  Produktet som får innlest sine data
 */
void produktLesData(struct Produkt* p) {

    p->navn = lagOgLesText("\n\tNavn");
    p->produsentNr = lesInt("\n\t1 - LofossBakken, 2 - TineRøn, 3 - WangenFinden, 4 - HaademHolen, 5 - SynnøveNoraker", 1, 5);
    p->produsentNr - 1;
    p->type = lesInt("\n\tType", 0, 1);
    p->antallKg = lesInt("\n\tÅrlig kilo", 0, MAXKILO);
}


/**
 *  Oppgave 2C - Skriver (om mulig) ALT om ALLE produkter av EN GITT type.
 *
 *  @see   lesType()
 *  @see   produktErType(...)
 *  @see   produktSkrivData(...)
 */
void skrivAlleAvType() {
    if (gAntallProdukter > 0) {
        enum Type type = lesType();

        printf("\n\tAlle produktene av denne typen:\n");
        for(int i = 0; i < gAntallProdukter; i++) {
            if(produktErType(gProdukter[i], type) == true) {
                printf("\n\tnr.%3i:     ", i + 1);
                produktSkrivData(gProdukter[i]);
            }
        }
    } else {
        printf("\n\tIngen produkter registrert.\n\n");
    }
}


/**
 *  Oppgave 2C - Returnerer om produktet er av en gitt type.
 *
 *  @param    p  -  Aktuelt produkt å sjekke 'type' for
 *  @param    t  -  Aktuell enum-type å sjekke opp mot
 *  @return   Om produktet 'p' har 'type' lik 't' eller ei
 */
bool produktErType(const struct Produkt* p, enum Type t){

    if(p->type == t) {
        return true;
    } else {
        return false;
    }
}


/**
 *  Oppgave 2D - Endrer (om mulig) et produkts antall kilo årlig produsert.
 *
 *  @see   produktEndreKilo(...)
 */
void endreKilo() {

    int nr;

    if(gAntallProdukter > 0) {
        nr = lesInt("\n\tproduktnummer", 0, gAntallProdukter);
        if(nr == 0) {
            printf("\n\tgår tilbake til meny\n\n");
        } else {
            produktEndreKilo(nr-1);
        }
    } else {
        printf("\n\tIngen produkter registrert.\n\n");
    }

}


/**
 *  Oppgave 2D - Endrer et produkts antall kilo årlig produsert.
 *
 *  @param   p  -  Aktuell produkt å endre antall kilo for
 *  @see     produktSkrivData(...)
 */
void produktEndreKilo(struct Produkt* p) {

    printf("\n\tNåværende data om produkt:");
    produktSkrivData(p);

    p->antallKg = lesInt("\n\tNy antall KG", 0, MAXKILO);

    printf("\n\tNy data om produkt:\n");
    produktSkrivData(p);
}


/**
 *  Oppgave 2E - Skriver (om mulig) ALLE produkter med (sub)tekst i navnet.
 *
 *  @see   produktMedSubtekst(...)
 *  @see   produktSkrivData(...)
 */
void skrivAlleMedNavn() {

    if (gAntallProdukter > 0) {
        char *navn;

        lesText("\n\tNavn på produkt", navn, STRLEN),

        printf("\n\tAlle produktene med dette navnet:\n");
        for(int i = 0; i < gAntallProdukter; i++) {
            if(produktMedSubtekst(gProdukter[i], navn) == true) {
                printf("\n\tnr.%3i:     ", i + 1);
                produktSkrivData(gProdukter[i]);
            }
        }
    } else {
        printf("\n\tIngen produkter registrert.\n\n");
    }
}


/**
 *  Oppgave 2E - Returnerer om produktet innholder en tekst i navnet sitt.
 *
 *  @param    p    -  Aktuelt produkt å sjekke om inneholder subteksten 'nvn'
 *  @param    nvn  -  Aktuell tekst å sjekke om er (sub)tekst i 'p->navn'
 *  @return   Om produktet 'p' inneholder subteksten 'nvn' eller ei
 */
bool produktMedSubtekst(const struct Produkt* p, const char* nvn)  {

    if(strstr(p->navn, nvn)) {
        return true;
    } else {
        return false;
    }
}


/**
 *  Oppgave 2F - Skriver ALLE produktene til fil.
 *
 *  @see   produktSkrivTilFil(...)
 */
void skrivTilFil() {

    FILE *utfil;

    utfil = fopen("produkt.DTA", "w");

    if (utfil) {
        printf("\n\n\tSkriver til fil 'produkt.DTA'......\n\n");

        fprintf(utfil, "%i\n", gAntallProdukter);

        for(int i = 0; i < gAntallProdukter; i++) {
            produktSkrivTilFil(utfil, gProdukter[i]);
        }
    } else {
        printf("\n\tKunne ikke åpne fil 'produkt.DTA'......\n\n");
    }
}


/**
 *  Oppgave 2F - Alle dataene for ETT produkt skrives ut på fil.

 *
 *  @param   ut  - Filen det skal skrives til
 *  @param   p   - Produktet som skrives til fil
 */
void produktSkrivTilFil(FILE* ut, const struct Produkt* p) {

    fprintf(ut, "%s\n", p->navn);
    switch(p->type) {
        case Rakfisk: fprintf(ut, "R");     break;
        case Pultost: fprintf(ut, "P");     break;
    }
    fprintf(ut, " %i %i\n", p->produsentNr - 1, p->antallKg);
}


/**
 *  Oppgave 2G - Leser ALLE produktene fra fil.
 *
 *  @see     produktLesFraFil(...)
 */
void lesFraFil() {

    FILE *innfil = fopen("produkt.DTA", "r");

    if(innfil) {
        fscanf(innfil, "%i", &gAntallProdukter);
        getc(innfil);

        for(int i = 0; i < gAntallProdukter; i++) {
            gProdukter[i] = (struct Produkt*) malloc(sizeof(struct Produkt));
            produktLesFraFil(innfil, gProdukter[i]);
        }
        printf("\n\tProdukter lest inn fra fil 'produkt.DTA'!\n\n");
        fclose(innfil);
    } else {
        printf("\n\tFant ikke fil 'produkt.DTA'\n\n");
    }
}


/**
 *  Oppgave 2G - Leser ALT om ETT produkt fra fil.
 *
 *  @param  inn - Filen det skal leses fra
 *  @param  p   - Produktet som får innlest sine data
 */
void produktLesFraFil(FILE* inn, struct Produkt* p) {

    char buffer[STRLEN];
    char tegn;

    fgets(buffer, STRLEN, inn);
    buffer[strlen(buffer) - 1] = '\0';
    p->navn = (char *) malloc((strlen(buffer) + 1) * sizeof(char)); 
    strcpy(p->navn, buffer);

    fscanf(inn, "%c %i %i", &tegn, &p->produsentNr, &p->antallKg);
    getc(inn);

    p->type = (tegn == 'R') ? Rakfisk : Pultost;
}
