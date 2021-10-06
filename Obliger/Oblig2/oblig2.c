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
         valg,
         svars[STRLEN];


    
    //Bane 1
    baneLengde[0] = 62;
    banePar[0] = 3;
    baneOB[0] = true;
    baneBeskrivelse[0][STRLEN] = {"Bane med mange trær og kratt"};
    antallBaner++;

    //Bane 2
    baneLengde[1] = 94;
    banePar[1] = 3;
    baneOB[1] = false;
    baneBeskrivelse[1][STRLEN] = {"Flatt terreng gjennom hele banen"};
    antallBaner++;

    do
    {
        printf("\n\nMeny:\nL - Legge til bane\nS - Se alle baner\nQ - Avslutt\n");
        scanf("%c", &valg);   // Leser innn brukers svar
        valg = toupper(valg); //Gjør om svar til uppercase

        getchar(); 

        if (valg == 'L' && 0 < antallBaner < MAXBANER)
        {
            printf("Hvor lang er den %i. Banen: ", antallBaner + 1);
            scanf("%i", &svarI);
            if (svarI > 0)
            {
             baneLengde[antallBaner] = svarI;
            } else {
                printf("Ugyldig banelengde.\n\n");
                ;
            }

            svarI = 0;
            printf("Par på banen (2-8): ");
            scanf("%i", &svarI);
            while(svarI < 2 || svarI > 8) {
                printf("Ugyldig mengde par.\n");
                printf("Skriv inn gyldig mengde: ");
                scanf("%i", &svarI);
            }
            banePar[antallBaner] = svarI;
            

            do {
                printf("Har banen OB (J/N): ");
                scanf(" %c", &svar);
                svar = toupper(svar);
                if(svar == 'J') {
                    baneOB[antallBaner] = true;
                } else if (svar == 'N') {
                    baneOB[antallBaner] = false;
                }
            } while(svar != 'J' && svar != 'N');

            getchar();

            printf("Bane beskrivelse: "); gets(svars);
            baneBeskrivelse[antallBaner][STRLEN] = svars;

            antallBaner++;
        }
        else if(antallBaner >= MAXBANER)
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
                else {
                    printf("\tUten OB\n");
                }
                printf("\tBeskrivelse: %s\n", baneBeskrivelse[i]);
            }
                printf("\nAntall baner: %i\n", antallBaner);
                sum += banePar[i];
                printf("For å havne på par brukes: %i kast.\n", sum);
        }
        if (valg == 'Q')
        {
            printf("Program avsluttes.");
            return 0;
        }
    } while (svar != 'L' && svar != 'S' && svar != 'Q');
}
