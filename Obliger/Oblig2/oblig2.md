Brukeren tilbys hele tiden disse valgene:
L – Legge til bane
S – Se alle baner
Q – Avslutt

Disse kommandoene skal virke som følgende:

L: Hvis det allerede er lagt til MAXBANER, skrives det ut en beskjed om dette, og ingen
baner kan legges til. I motsatt fall leses den nye banens lengde (0 eller et positivt tall).
Skriver bruker 0 (null), legges ingen bane til allikevel. Det kommer da bare en egen
beskjed, og det gås tilbake til hovedmenyen. Ellers lagres den nye banens lengde.
Par (lovlige verdier: 2-8), OB (lovlige verdier: ‘J’/’N’) og beskrivelse for banen leses
deretter. Det skal altså sikres (vha. looping) at tall (lengde og par) og bokstaver (OB)
er i lovlige intervaller/lovlig tegn. Husk å oppdatere antallBaner korrekt.

S: Alle banene som er registrert for øyeblikket skal skrives på skjermen med alle sine
data (nummer, beskrivelse, lengde, par og om OB eller ei).
Til slutt skrives nåværende antall baner og totalt antall kast for å havne på par
(summen av alle de nåværende banenes par).

Q: Når programmet avsluttes, skrives en egen melding om at det avsluttes.
Det kommer en egen melding dersom bruker skriver ulovlig menyvalg.
Programmet skal også håndtere at bruker skriver små bokstaver for menyvalgene/OB.


hovedprogram;
    menyvalg;

        når L {
            hvis maxbaner > i {
                maxbaner lagt til
                stopp
            } ellers {
                banelengde (i > 0) {
                    hvis i<=0 {
                        ikke legg til bane
                        PRINT ikke lagt til bane
                        returner hovedmeny
                    }
            
                }
            }
        }


Første utkast, prøver noe nytt

/**
 * @file oblig2.c
 * @author Loke Svelland
 *
 * I denne oppgaven skal jeg lage ett program som leser inn nye og viser gamle
 * Frisbeegolf baner, og forteller litt om terrenget i banen og lengde
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h> //  Håndtering av char-arrayer/tekster/strenger

const int MAXBANER = 18; ///< Maks antall baner.
const int STRLEN = 100;  ///< Maks tekstlengde.

/**
 * Hovedprogram
 */
int main()
{

    char baneBeskrivelse[MAXBANER][STRLEN]; // Beskrivelse av banene.
    int baneLengde[MAXBANER];               // Banenes lengde (i meter).
    int banePar[MAXBANER];                  // Forventet antall kast (par)
                                            // for hver enkelt bane.
    bool baneOB[MAXBANER];                  // Har banene OB eller ei
    int antallBaner = 0,                    // Antall baner pr.nå.
        i,                                  // Hvilken bane vi er på
        svarI;                              // tar imot int svar fra bruker
    char svar,                              // tar imot char svar fra bruker
        valg;

    //Bane 1
    baneLengde[0] = 62;
    banePar[0] = 3;
    baneOB[0] = true;
    baneBeskrivelse[0][STRLEN] = "Bane med mange trær og kratt";
    antallBaner++;

    //Bane 2
    baneLengde[1] = 94;
    banePar[1] = 3;
    baneOB[1] = false;
    baneBeskrivelse[1][STRLEN] = "Flatt terreng gjennom hele banen";
    antallBaner++;

    do
    {
        svar = 0;
        printf("Meny:\nL - Legge til bane\nS - Se alle baner\nQ - Avslutt\n");
        scanf("%c", &valg);
        valg = toupper(valg); // Leser innn brukers svar

        if (valg == 'L')
        {
            if (antallBaner > MAXBANER) // Skjekker om Max antall baner
            {                           // er lagt til
                printf("Max antall baner lagt til\n");
                return;
            }
            else
            {                  // legger til en bane om den er
                antallBaner++; // mindre enn MAXBANER
            }
            for (i = antallBaner; i < MAXBANER; i++);
            // Leser inn lengde på banen
            printf("Hvor lang er den %i.Banen: ", antallBaner);
            scanf(" %i", &svarI);
            if (svarI <= 0)
            {
                printf("Ugyldig lengde, returnerer til meny.\n\n");
            }
            // finner hvilken lomme i arrayet
            // den skal ligge i

            baneLengde[i] = svarI;

            svarI = 0;
            printf("Par på banen (2-8): ");
            scanf(" %i", &svarI);
            while (svarI < 2 || svarI > 8)
            {
                printf("Ugyldig mengde par.\n");
                printf("Skriv tall innenfor (2-8): ");
                scanf(" %i", &svarI);
            }
            banePar[i] = svarI;

            svar = 0;
            printf("Har banen OB (J/N): ");
            scanf(" %c", &svar);
            toupper(svar);
            if (svar == 'J')
            {
                svar = atoi(1);
            }
            else if (svar == 'N')
            {
                svar = atoi(0);
            }
            baneOB[i] = svar;

            getchar();

            svar = 0;
            printf("Bane beskrivelse: ");
            scanf("%s", &svar);
            baneBeskrivelse[i][STRLEN] = svar;
        }

        if (valg == 'S')
        {
            for (i = 0; i < antallBaner; i++)
            {
                printf("\nBane %i: \n", i + 1);
                printf("\tLengde: %i\n", baneLengde[i]);
                printf("\tPar: %i\n", banePar[i]);
                if (baneOB[i] == 1)
                {
                    printf("\tMed OB\n");
                }
                else if (baneOB[i] == 0)
                {
                    printf("\tUten OB\n");
                }
                printf("\tBeskrivelse: %s\n", baneBeskrivelse[i]);
                printf("Antall baner: %i\n", antallBaner);
                printf("For å havne på par brukes: %i kast.", )
            }
        }

        if (svar == 'Q')
        {
            printf("Program avsluttes.");
            return 0;
        }
    } while (svar != 'L' || svar != 'S' || svar != 'Q');
}


2. utkast, alt fungerer bortsett fra break viss banelengde = 0, og hardkode inn banelengde på bane 1 og 2:

/**
 * @file oblig2.c
 * @author Loke Svelland
 *
 * I denne oppgaven skal jeg lage ett program som leser inn nye og viser gamle
 * Frisbeegolf baner, og forteller litt om terrenget i banen og lengde
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h> //  Håndtering av char-arrayer/tekster/strenger

const int MAXBANER = 18; ///< Maks antall baner.
const int STRLEN = 100;  ///< Maks tekstlengde.

/**
 * Hovedprogram
 */
int main()
{

    char baneBeskrivelse[MAXBANER][STRLEN]; // Beskrivelse av banene.
    int baneLengde[MAXBANER];               // Banenes lengde (i meter).
    int banePar[MAXBANER];                  // Forventet antall kast (par)
                                            // for hver enkelt bane.
    bool baneOB[MAXBANER];                  // Har banene OB eller ei
    int antallBaner = 0,                    // Antall baner pr.nå.
        i,                                  // Hvilken bane vi er på
        sum = 0,                            // summere Par
        svarI;                              // tar imot int svar fra bruker
    char svar,                              // tar imot char svar fra bruker
        valg;

    //Bane 1
    baneLengde[0] = 62;
    banePar[0] = 3;
    baneOB[0] = true;
    baneBeskrivelse[0][STRLEN] = "Bane med mange trær og kratt";
    antallBaner++;

    //Bane 2
    baneLengde[1] = 94;
    banePar[1] = 3;
    baneOB[1] = false;
    baneBeskrivelse[1][STRLEN] = "Flatt terreng gjennom hele banen";
    antallBaner++;

    do
    {
        printf("Meny:\nL - Legge til bane\nS - Se alle baner\nQ - Avslutt\n");
        scanf(" %c", &valg);  // Leser innn brukers svar
        valg = toupper(valg); //Gjør om svar til uppercase

        getchar();

        if (valg == 'L' && 0 < antallBaner < MAXBANER)
        {
            printf("Hvor lang er den %i. Banen: ", antallBaner + 1);
            scanf("%i", &svarI);
            if (svarI > 0)
            {
                baneLengde[antallBaner] = svarI;
            }
            else
            {
                printf("Ugyldig banelengde.\n\n");
                ;
            }

            svarI = 0;
            printf("Par på banen (2-8): ");
            scanf("%i", &svarI);
            while (svarI < 2 || svarI > 8)
            {
                printf("Ugyldig mengde par.\n");
                printf("Skriv inn gyldig mengde: ");
                scanf("%i", &svarI);
            }
            banePar[antallBaner] = svarI;

            do
            {
                printf("Har banen OB (J/N): ");
                scanf(" %c", &svar);
                svar = toupper(svar);
                if (svar == 'J')
                {
                    baneOB[antallBaner] = true;
                }
                else if (svar == 'N')
                {
                    baneOB[antallBaner] = false;
                }
            } while (svar != 'J' && svar != 'N');

            getchar();

            printf("Bane beskrivelse: ");
            gets(baneBeskrivelse[antallBaner]);

            antallBaner++;
        }
        else if (antallBaner >= MAXBANER)
        {
            printf("Max baner lagt til\n\n");
        }

        if (valg == 'S')
        {
            for (i = 0; i < antallBaner; i++)
            {
                printf("\nBane %i: \n", i + 1);
                printf("\tLengde: %i\n", baneLengde[i]);
                printf("\tPar: %i\n", banePar[i]);
                if (baneOB[i] == 1)
                {
                    printf("\tMed OB\n");
                }
                else
                {
                    printf("\tUten OB\n");
                }
                printf("\tBeskrivelse: %s\n", baneBeskrivelse[i]);
                sum += banePar[i];
            }
            printf("\nAntall baner: %i\n", antallBaner);

            printf("For å havne på par brukes: %i kast.\n", sum);
        }
        if (valg == 'Q')
        {
            printf("Program avsluttes.");
            return 0;
        }
    } while (svar != 'L' && svar != 'S' && svar != 'Q');
}
