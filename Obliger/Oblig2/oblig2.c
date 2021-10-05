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
#include <string.h>	    //  Håndtering av char-arrayer/tekster/strenger

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



    while (svar != 'Q')
    {
    printf("Meny:\nL - Legge til bane\nS - Se alle baner\nQ - Avslutt\n");
    scanf("%c", &valg);
    valg = toupper(valg); // Leser innn brukers svar
        while (valg == 'L')
        {
            if (antallBaner > MAXBANER) // Skjekker om Max antall baner
            {                           // er lagt til
                printf("Max antall baner lagt til\n");
                break;
            }
            else
            {                  // legger til en bane om den er
                antallBaner++; // mindre enn MAXBANER
            }
            // Leser inn lengde på banen
            printf("Hvor lang er den %i.Banen: ", antallBaner);
            scanf(" %i", &svarI);
            if (svarI <= 0)
            {
                printf("Ugyldig lengde, returnerer til meny.\n\n");
            }
            // finner hvilken lomme i arrayet
            // den skal ligge i
            for (i = antallBaner; i < MAXBANER; i++)
            {
                baneLengde[i] = svarI;
            } // Oppdaterer lommen

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
            scanf(" %d", &svar);
            toupper(svar);
            if(svar == 'J') {
                svar = atoi(1);
            } else if (svar == 'N') {
                svar = atoi(0);
            }
            baneOB[i] = svar;

            getchar();

            svar = 0;
            printf("Bane beskrivelse: ");
            scanf("%s", &svar);
            baneBeskrivelse[i][STRLEN] = svar;


            break;
        }

        while (valg == 'S')
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
                printf("\tBeskrivelse: %s\n", baneBeskrivelse[i][STRLEN]);
            }
            break;
        }
    }
    printf("\nProgram avsluttes.\n");
    return 0;
}