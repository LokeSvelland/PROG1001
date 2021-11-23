#include <stdio.h>   // printf, FILE
#include <stdlib.h>  // sizeof, malloc
#include <string.h>  // strcpy, strlen
#include <stdbool.h> // bool, true, false
#include "LesData.h" // Verktøykasse for lesing av diverse data

#define MAXGJENSTANDER 300 ///< Max. antall gjenstander.
const int STRLEN = 60;     ///< Max. tekstlengde.

/**
 * Kategori (ulike kategorier/statuser for en gjenstand).
 */
enum Kategori
{
    Ubestemt,           // nr. 0
    Fjernet,            // nr. 1
    Hentes,             // nr. 2
    Lagres,             // nr. 3
    Selges,             // nr. 4
    Gratis              // nr. 5
};

/**
 * Gjenstand (med navn, hvem skal ha den og status for den).
 */
struct Gjenstand
{
    char *navn;           // Gjenstandens navn/beskrivelse.
    char *hvem;           // Hvem skal ha den/hvor skal den sendes.
    enum Kategori status; // Status for gjenstanden.
};

void skrivMeny();
void nyGjenstand();                                             // Oppgave 2A
void gjenstandLesData(struct Gjenstand *g);                     // Oppgave 2A
void skrivAlleGjenstandene();                                   // Oppgave 2B
void gjenstandSkrivData(const struct Gjenstand *g);             // Oppgave 2B
void skrivAlleIKategori();                                      // Oppgave 2C
char lesKategori();                                             // Oppgave 2C
enum Kategori konverterTilKategori(const char tegn);            // Oppgave 2C
enum Kategori gjenstandHentStatus(const struct Gjenstand *g);   // Oppgave 2C
void settHvem();                                                // Oppgave 2D
void gjenstandSettHvem(struct Gjenstand *g);                    // Oppgave 2D
void endreKategori();                                           // Oppgave 2E
void gjenstandEndreKategori(struct Gjenstand *g);               // Oppgave 2E
void skrivTilFil();                                             // Oppgave 2F
void gjenstandSkrivTilFil(FILE *ut, const struct Gjenstand *g); // Oppgave 2F
void lesFraFil();                                               // Oppgave 2G
void gjenstandLesFraFil(FILE *inn, struct Gjenstand *g);        // Oppgave 2G

int gAntallGjenstander;               ///< Antall gjenstander hittil registrert.
struct Gjenstand *gGjenstander[MAXGJENSTANDER]; ///< Alle gjenstandene.

/**
 * Hovedprogrammet:
 */
int main()
{

    char kommando;

    lesFraFil(); // Oppgave 2G

    skrivMeny();

    kommando = lesChar("\nØnske");

    while (kommando != 'Q')
    {
        switch (kommando)
        {
        case 'N':
            nyGjenstand();              break; // Oppgave 2A
        case 'A':
            skrivAlleGjenstandene();    break; // Oppgave 2B
        case 'K':
            skrivAlleIKategori();       break; // Oppgave 2C
        case 'H':
            settHvem();                 break; // Oppgave 2D
        case 'E':
            endreKategori();            break; // Oppgave 2E
        default:
            skrivMeny();                break;
        }

        kommando = lesChar("\nØnske");
    }

    skrivTilFil(); // Oppgave 2F

    return 0;
}
/**
 * Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny()
{
    printf("\nFØLGENDE KOMMANDOER ER LOVLIG:\n");
    printf("\tN = Ny gjenstand\n");
    printf("\tA = skriv Alle gjenstandene\n");
    printf("\tK = skriv gjenstandene i en Kategori\n");
    printf("\tH = endre/sett til Hvem/Hvor en gjenstand skal\n");
    printf("\tE = Endre/sett kategori-tilhørighet\n");
    printf("\tQ = Quit/avslutt\n");
}


/**
 * Oppgave 2A - Legger inn (om mulig) en ny gjenstand i datastrukturen.
 *
 * @see gjenstandLesData(...)
 */
void nyGjenstand()
{
char *ny;

    if(gAntallGjenstander < MAXGJENSTANDER) {
        printf("\nNy gjenstand:\n\n");
        gGjenstander[gAntallGjenstander] = (struct Gjenstand*) malloc(sizeof(struct Gjenstand));
        gjenstandLesData(gGjenstander[gAntallGjenstander]);
        gAntallGjenstander++;
    } else {
        printf("ikke plass til flere gjenstander\n");
    }
}


/**
 * Oppgave 2A - Leser inn relevante data og nullstiller andre.
 *
 * @param g - Gjenstanden som får innlest/initiert sine data
 */
void gjenstandLesData(struct Gjenstand *g)
{
    g->navn = lagOgLesText("\tNavn");
    g->hvem = lagOgLesText("\n\tHvem");
    printf("\n\tStatus: %d", g->status = Ubestemt);
}


/**
 * Oppgave 2B - Skriver ALT om ALLE gjenstander.
 *
 * @see gjenstandSkrivData(...)
 */
void skrivAlleGjenstandene()
{
    for(int i = 0; i < gAntallGjenstander; i++) {
        gjenstandSkrivData(gGjenstander[i]);
    }
}


/**
 * Oppgave 2B - Skriver ALT om EN gjenstand ut på skjermen.
 *
 * @param g - Gjenstanden som skrives ut
 *
 * ! printf til status fungerer, men er laget på en janky måte
 * ! MÅ SES PÅ
 */
void gjenstandSkrivData(const struct Gjenstand *g)
{
    printf("\n\tNavn: %s", g->navn);
    printf("\n\tHvem: %s", g->hvem);
    if(g->status == 0) {
    printf("\n\tStatus: UBESTEMT\n");
    } else if(g->status == 1) {
        printf("\n\tStatus: FJERNET\n");
    } else if(g->status == 2) {
        printf("\n\tStatus: HENTES\n");
    } else if(g->status == 3) {
        printf("\n\tStatus: LAGRES\n");
    } else if(g->status == 4) {
        printf("\n\tStatus: SELGES\n");
    } else if(g->status == 5) {
        printf("\n\tStatus: GRATIS\n");
    }
}



/**
 * Oppgave 2C - Skriver ALT om ALLE gjenstander med EN GITT status.
 *
 * @see lesKategori()
 * @see konverterTilKategori(...)
 * @see gjenstandHentStatus(...)
 * @see gjenstandSkrivData(...)
 */
void skrivAlleIKategori()
{
    char tegn,
         kategori;

    while (tegn != lesKategori())
    {
        tegn = lesChar("\n\tKatogori");
        if(lesKategori() == tegn) {
            toupper(tegn);
            kategori = konverterTilKategori(tegn);
            for(int i = 0; i < gAntallGjenstander; i++) {
            gjenstandSkrivData(gGjenstander[i]);
            }

        } else {
            printf("\n\tUlovlig verdi");
    }
    }
}


/**
 * Oppgave 2C - Leser LOVLIG kategori ('U', 'F', 'H', 'L', 'S', 'G').
 *
 * @return Forbokstaven i en LOVLIG kategori
 */
char lesKategori()
{
    char tegn;
    if ('U') {
        return tegn = 'U';
    } else if ('F') {
        return tegn = 'F';
    } else if ('H') {
        return tegn = 'H';
    } else if ('L') {
        return tegn = 'L';
    } else if ('S') {
        return tegn = 'S';
    } else if ('G') {
        return tegn = 'G';
    }
}


/**
 * Oppgave 2C - Gjør om en (lovlig) bokstav til kategori, returnerer dette.
 *
 * @param tegn - Bokstaven som skal gjøres om til en kategori/enum-verdi
 * @return Kategori/enum-verdi
 */
enum Kategori konverterTilKategori(const char tegn)
{
    if (tegn == 'U') {
        return Ubestemt;
    } else if (tegn == 'F') {
        return Fjernet;
    } else if (tegn == 'H') {
        return Hentes;
    } else if (tegn == 'L') {
        return Lagres;
    } else if (tegn == 'S') {
        return Selges;
    } else if (tegn == 'G') {
        return Gratis;
    }
}


/**
 * Oppgave 2C - Returnerer kun gjentandens status.
 *
 * @param g - Aktuell gjenstand å returnere 'status' for
 * @return Gjenstandens 'status'
 */
enum Kategori gjenstandHentStatus(const struct Gjenstand *g)
{
    for(int i = 0; i < gAntallGjenstander; i++)
    printf("%d", gGjenstander[i]->status);
}


/**
 * Oppgave 2D - Endrer (kanskje) EN aktuell gjenstands 'hvem'.
 *
 * @see gjenstandSettHvem(...)
 */
void settHvem()
{
    int nr;

    nr = lesInt("\n\tGjenstandsnummer", 0, MAXGJENSTANDER);
    if(nr < MAXGJENSTANDER) {
        if (nr < 0)
        {
            printf("\nIngenting skjer");
        } else {
            gjenstandSettHvem(gGjenstander[nr-1]);
        }
    }
}


/**
 * Oppgave 2D - Endrer en gjenstands til 'hvem/hvor' den skal.
 *
 * @param g - Aktuell gjenstand å endre 'hvem' for
 * @see gjenstandSkrivData(...)
 */
void gjenstandSettHvem(struct Gjenstand *g)
{
    g->hvem = lagOgLesText("\n\tHvem skal få gjenstanden");
    gjenstandSkrivData(g);
}


/**
 * Oppgave 2E - Endrer (kanskje) EN aktuell gjenstands kategori/status.
 *
 * @see gjenstandEndreKategori(...)
 */
void endreKategori()
{
    int nr;

    nr = lesInt("\n\tGjenstandsnummer", 0, MAXGJENSTANDER);
    if(nr < MAXGJENSTANDER) {
        if (nr < 0)
        {
            printf("\nIngenting skjer");
        } else {
            gjenstandEndreKategori(gGjenstander[nr-1]);
        }
    }
}



/**
 * Oppgave 2E - Endrer en gjenstands kategori/status.
 *
 * @param g - Aktuell gjenstand å endre status for
 * @see gjenstandSkrivData(...)
 * @see lesKategori()
 * @see konverterTilKategori(...)
 */
void gjenstandEndreKategori(struct Gjenstand *g)
{
    char tegn;
    enum Kategori Kategori;

    gjenstandSkrivData(g);
    while(tegn != lesKategori()) {
        tegn = lesChar("\n\tNy kategori");
        if(lesKategori() == tegn) {
            toupper(tegn);
            Kategori = konverterTilKategori(tegn);
            g->status = Kategori;
            gjenstandSkrivData(g);
        } else {
            printf("\n\tUlovlig tegn");
        }
    }
}


/**
 * Oppgave 2F - Skriver ALLE gjenstandene til fil.
 *
 * @see gjenstandSkrivTilFil(...)
 */
void skrivTilFil()
{
    /* LAG INNMATEN */
}


/**
 * Oppgave 2F - Alle EN gjenstands data skrives ut på fil.
 *
 * @param ut - Filen det skal skrives til
 * @param g - Gjenstanden som skrives til fil
 */
void gjenstandSkrivTilFil(FILE *ut, const struct Gjenstand *g)
{
    /* LAG INNMATEN */
}


/**
 * Oppgave 2G - Leser ALLE gjenstandene fra fil.
 *
 * @see gjenstandLesFraFil(...)
 */
void lesFraFil()
{
    /* LAG INNMATEN */
}


/**
 * Oppgave 2G - Leser ALT om EN gjenstand fra fil.
 *
 * @param inn - Filen det skal leses fra
 * @param g - Gjenstanden som får innlest sine data
 * @see konverterTilKategori(...)
 */
void gjenstandLesFraFil(FILE *inn, struct Gjenstand *g)
{
    /* LAG INNMATEN */
}
