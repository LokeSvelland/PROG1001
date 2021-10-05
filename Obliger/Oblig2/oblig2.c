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
        svarI;                              // tar imot int var fra bruker
    char svar;                              // tar imot char svar fra bruker

    //Bane 1
    baneBeskrivelse[0][STRLEN] = "Bane med mange trær og kratt";
    baneLengde[0] = 62;
    banePar[0] = 3;
    baneOB[0] = true;
    antallBaner++;

    //Bane 2
    baneBeskrivelse[1][STRLEN] = "Flatt terreng gjennom hele banen";
    baneLengde[1] = 94;
    banePar[1] = 3;
    baneOB[1] = false;
    antallBaner++;

    getchar();                              // Fjerner \n som ligger igjen


    do
    {
    printf("Meny:\nL - Legge til bane\nS - Se alle baner\nQ - Avslutt\n");
    scanf("%c", &svar); svar = toupper(svar);// Leser innn brukers svar
    
        do
        {
            if (antallBaner > MAXBANER)     // Skjekker om Max antall baner
            {                               // er lagt til
                printf("Max antall baner lagt til\n");
                return 'Q';
            }
            else
            {                               // legger til en bane om den er
                antallBaner++;              // mindre enn MAXBANER
            }
                                            // Leser inn lengde på banen
            printf("Hvor lang er den %i.Banen: ", antallBaner);
            scanf(" %i", &svarI);
            if(svarI <= 0) {
                printf("Ugyldig lengde, returnerer til meny.\n\n");
            }
                                            // finner hvilken lomme i arrayet
                                            // den skal ligge i
            for (i = antallBaner - 1; i < MAXBANER; i++) {
            baneLengde[i] = svarI;   }       // Oppdaterer lommen

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
                baneOB[i] = true;
            } else if(svar == 'N') {
                baneOB[i] = false;
            }
            getchar();

            svar = 0;
            printf("Bane beskrivelse: ");
            scanf("%s", &svar);
            baneBeskrivelse[i][STRLEN] = svar;

            getchar();
        } while (svar = 'L');

        do {
            for(i = 0; i < antallBaner; i++) {
                printf("Bane %i: \n", i);
                printf("\tLengde: %i", baneLengde[i]);
                printf("\tPar: %i", banePar[i]);
                printf("\t%s", baneOB[i]);
                printf("\tBeskrivelse: %s", baneBeskrivelse[i]);
            }

        } while (svar = 'S');

    } while (svar != 'Q');
    printf("\nProgram avsluttes.\n");
    return 0;
}