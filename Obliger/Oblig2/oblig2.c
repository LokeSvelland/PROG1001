/**
 * 
 * Obligatorisk oppgave nr.2
 * 
 * @file    oblig2.c
 * @author  Loke Svelland
 * @version 1.0
 *
 * I denne oppgaven skal jeg lage ett program som leser inn nye og viser gamle
 * Frisbeegolf baner, og forteller litt om terrenget i banen og lengde
 *
 */

#include <ctype.h>      //  Håndtering av enkelt-tegn(/bokstaver)
#include <stdio.h>      //  printf, scanf, fil-håndtering
#include <stdlib.h>	    //  Memory-håndtering, streng-konvertering, mer .....
#include <string.h>	    //  Håndtering av char-arrayer/tekster/strenger
#include <stdbool.h>    //  Boolean

const int MAXBANER = 18;                    ///< Maks antall baner.
const int STRLEN = 100;                     ///< Maks tekstlengde.

/**
 * Hovedprogram
 */
int main()
{

    char baneBeskrivelse[MAXBANER][STRLEN]; // Beskrivelse av banene.
    char baneBeskrivelse1og2[][40] = {      // info til bane 1 og 2
        "Bane med mange trær og kratt",
        "Flatt terreng gjennom hele banen"
    };
    int baneLengde[MAXBANER];               // Banenes lengde (i meter).
    int banePar[MAXBANER];                  // Forventet antall kast (par)
                                            // for hver enkelt bane.
    bool baneOB[MAXBANER];                  // Har banene OB eller ei
    int antallBaner = 0,                    // Antall baner pr.nå.
        i,                                  // Hvilken bane vi er på
        sum = 0,                            // Summere Par
        svarI;                              // Tar imot int svar fra bruker
    char svar,                              // Tar imot char svar fra bruker
         valg;                              // Tar imot meny valg fra bruker

    //Bane 1
    baneLengde[0] = 62;
    banePar[0] = 3;
    baneOB[0] = true;
    strcpy(baneBeskrivelse[0], baneBeskrivelse1og2[0]);
    antallBaner++;

    //Bane 2
    baneLengde[1] = 94;
    banePar[1] = 3;
    baneOB[1] = false;
    strcpy(baneBeskrivelse[1], baneBeskrivelse1og2[1]);
    antallBaner++;

    do                                      // looper til den hører L/S/Q
    {
        printf("Meny:\nL - Legge til bane\nS - Se alle baner\nQ - Avslutt\n");
        scanf(" %c", &valg);                // Leser innn brukers svar
        valg = toupper(valg);               // Gjør om svar til uppercase

        switch (valg)                       // setter opp en switch case
        {                                   // for menyvalgene
        case 'L':
            if (antallBaner < MAXBANER)     // vil ikke kjøre utenfor parameter
            {
                printf("Hvor lang er den %i. Banen: ", antallBaner + 1);
                scanf("%i", &svarI);        // Tar imot banens lengde
                if (svarI > 0)
                {                           // oppdaterer lomme
                    baneLengde[antallBaner] = svarI;
                }
                else
                {                           // bryter om svar = 0 eller negativ
                    printf("Ugyldig banelengde.\n\n");
                    break;
                }

                svarI = 0;                  // nullstiller variabel
                printf("Par på banen (2-8): ");
                scanf("%i", &svarI);        // tar imot svar fra bruker
                while (svarI < 2 || svarI > 8)
                {                           // looper til svar innenfor 2-8
                    printf("Ugyldig mengde par.\n");
                    printf("Skriv inn gyldig mengde: ");
                    scanf("%i", &svarI);
                }                           // oppdaterer lomme
                banePar[antallBaner] = svarI;

                do
                {
                    printf("Har banen OB (J/N): ");
                    scanf(" %c", &svar);    // tar imot svar fra bruker
                    svar = toupper(svar);   // gjør svar til stor bokstav
                    if (svar == 'J')
                    {                       // hvis svar er J er lommen true
                        baneOB[antallBaner] = true;
                    }
                    else if (svar == 'N')   // hvis svar er N er lommen false
                    {
                        baneOB[antallBaner] = false;
                    }
                } while (svar != 'J' && svar != 'N');

                getchar();                  // fjerner \n som ligger igjen
                                            // etter scanf

                                            // tar imot beskrivelse fra bruker
                printf("Bane beskrivelse: ");
                gets(baneBeskrivelse[antallBaner]); 

                antallBaner++;              // oppdaterer antall baner
                break;              
            }
            else if (antallBaner > MAXBANER)
            {                               // kjører ikke L om antallbaner er 
                                            // større eller lik MAXBANER
                printf("Max baner lagt til\n\n");
                break;
            }

        case 'S':
                                            // for loop teller opp hvilken
                                            // lomme man befinner seg i
                for (i = 0; i < antallBaner; i++)
                {
                                            // skriver hvilken bane
                    printf("\nBane %i: \n", i + 1);
                                            // skriver ut banelengde
                    printf("\tLengde: %i\n", baneLengde[i]);
                                            // skriver hvor mange par på bane
                    printf("\tPar: %i\n", banePar[i]);
                                            // Gjør om tall til string
                                            // og skriver ut
                    if (baneOB[i] == 1)
                    {
                        printf("\tMed OB\n");
                    }
                    else
                    {
                        printf("\tUten OB\n");
                    }
                                            // Skriver ut beskrivelse
                    printf("\tBeskrivelse: %s\n", baneBeskrivelse[i]);
                    sum += banePar[i];      // summerer banepar
                }
                                            // skriver hvor mange baner totalt
                printf("\nAntall baner: %i\n", antallBaner);

                                            // Hvor mange slag for par totalt
                printf("For å havne på par brukes: %i kast.\n\n", sum);
                break;

        case 'Q':                           // avslutter program
                printf("Program avsluttes.\n");
                return 0;
        }
    } while (svar != 'L' && svar != 'S' && svar != 'Q');
}