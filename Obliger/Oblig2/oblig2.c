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

const int MAXBANER = 18; ///< Maks antall baner.
const int STRLEN = 100;  ///< Maks tekstlengde.

/**
 * Hovedprogram
 *
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
    // BaneOB[0] = "j";
    antallBaner++;

    //Bane 2
    baneBeskrivelse[1][STRLEN] = "Flatt terreng gjennom hele banen";
    baneLengde[1] = 94;
    banePar[1] = 3;
    //BaneOB[1] = "n";
    antallBaner++;

    printf("Meny:\nL - Legge til bane\nS - Se alle baner\nQ - Avslutt\n");
    scanf("%c", &svar); // Leser innn brukers svar

    do
    {
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
            scanf("%i", &svarI);
            if(svarI <= 0) {
                printf("Ugyldig lengde, returnerer til meny.\n");
            }
                                            // finner hvilken lomme i arrayet
                                            // den skal ligge i
            for (i = antallBaner - 1; i < baneLengde; i++);
            baneLengde[i] = svarI;          // Oppdaterer lommen

            // getchar();                   // Fjerner \n som ligger igjen

            svarI = 0;
            printf("Par på banen: \n");
            scanf("%i", &svarI);
            while (svarI < 2 || svarI > 8)
            {
                printf("Ugyldig mengde par.\n");
            }
            banePar[i] = svarI;
            
        } while (svar == 'L' || svar == 'l');

    } while (svar != 'Q' || svar != 'q');
}
