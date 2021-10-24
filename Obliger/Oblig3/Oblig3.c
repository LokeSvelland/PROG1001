/**
 *  Obligatorisk oppgave 3
 *
 * @file    Oblig3.c
 * @author  Loke Svelland
 *
 * I dette programmet skal vi lage ett 3 på rad spill.
 * Spillet skal finne vinner, nullstille brettet og skjekke om trekk er gyldig.
 *
 */


#include <stdio.h>          //  printf, scanf
#include <stdbool.h>        //  bool
#include <ctype.h>          //  toupper


#define  ANTRUTER    9      ///<  Antall ruter på brettet
const int STRLEN  = 80;     ///<  Tekstlengde

void nullstillBrett();
bool sjekkBrett(const int n);
bool sjekkVinner();
void skrivBrett();
int  spillSpillet();


char gBrett[ANTRUTER];     ///<  Spillebrettet.


/**
 * Hovedprogrammet.
 */
int main() {
    char spiller1[STRLEN];           //  Begge spillernes navn.
    char spiller2[STRLEN];
    char nyttSpill;                  //  Kjøre programmet/spillet EN gang til.
	int  vinner;                       //  Evt. spillernummer som har vunnet.

    do  {
      nullstillBrett(); 

      skrivBrett();

      printf("\n\nNavn på spiller 1:  ");     gets(spiller1);
      printf("Navn på spiller 2:  ");         gets(spiller2);  printf("\n");

      vinner = spillSpillet();

      if      (vinner == 1) printf("\nGratulerer %s!!\n\n", spiller1);
      else if (vinner == 2) printf("\nGratulerer %s!!\n\n", spiller2);
                                     //  'vinner' == 0:
      else    printf("\nIngen vinner denne gangen dessverre.\n\n");

      printf("\n\nEn ny runde (N/j):  ");
      scanf(" %c", &nyttSpill);  nyttSpill = toupper(nyttSpill);
      getchar();

    }  while (nyttSpill == 'J');

    return 0;
}


/**
 *  Nullstiller/blanker ut alle brettets ruter.
 */
void nullstillBrett() {
                        // Setter alle rutene som ' '
for (int i = 0; i < ANTRUTER; i++) {
  gBrett[i] = ' ';
}
}


/**
 *  Finner ut om et trekk er gyldig eller ei.
 *
 *  @param    n   - Ruten (0-8) det forsøkes å sette en brikke i
 *  @return	  Om det var mulig å sette brikken der (true) eller ei (false)
 */
bool sjekkBrett(const int n) {

if(gBrett[n] == ' ')    // sjekker om ruten er tom, og gir true eller false
{return true;}
else {return false;}
}


/**
 *  Sjekker om noen har tre på rad i en eller annen retning.
 *
 *  @return   Om noen har tre på rad (true) eller ei (false) i noen retning
 */
bool sjekkVinner() {
                        // Her testes alle de mulige vinner kombinasjonene
  if(gBrett[0] == gBrett[1] && gBrett[0] == gBrett[2] && gBrett[0] != ' ')
    {return true;}
  else if(gBrett[3] == gBrett[4] && gBrett[3] == gBrett[5] && gBrett[3] != ' ')
    {return true;}
  else if(gBrett[6] == gBrett[7] && gBrett[6] == gBrett[8] && gBrett[6] != ' ')
    {return true;}
  else if(gBrett[0] == gBrett[3] && gBrett[0] == gBrett[6] && gBrett[0] != ' ')
    {return true;}
  else if(gBrett[1] == gBrett[4] && gBrett[1] == gBrett[7] && gBrett[1] != ' ')
    {return true;}
  else if(gBrett[2] == gBrett[5] && gBrett[2] == gBrett[8] && gBrett[2] != ' ')
    {return true;}
  else if(gBrett[0] == gBrett[5] && gBrett[0] == gBrett[8] && gBrett[0] != ' ')
    {return true;}
  else if(gBrett[2] == gBrett[4] && gBrett[2] == gBrett[6] && gBrett[2] != ' ')
    {return true;}
    else {return false;}
}


/**
 *  Skriver ut spillebrettet.
 */
void skrivBrett() {

  printf("Spillbrett\n");
  printf("---1-----2-----3---\n");
  printf("|  %c  |  %c  |  %c  |\n", gBrett[0], gBrett[1], gBrett[2]);
  printf("---4-----5-----6---\n");
  printf("|  %c  |  %c  |  %c  |\n", gBrett[3], gBrett[4], gBrett[5]);
  printf("---7-----8-----9---\n");
  printf("|  %c  |  %c  |  %c  |\n", gBrett[6], gBrett[7], gBrett[8]);
  printf("-------------------\n");
}


/**
 *  Lar spillerne sette brikker, og finner evt en vinner.
 *
 *  @return   Spillernummeret som har vunnet (1, 2), evt. 0 (ingen vinner)
 *  @see      sjekkBrett(...)
 *  @see      skrivBrett(...)
 *  @see      sjekkVinner(...)
 */
int spillSpillet() {
  int svar = 0;         // nullstiller hjelpevariabel

  for (int i = 0; i < 9; i++) 
  {                     // forløkke som velger hvem sitt trekk det er
    skrivBrett();
    if (i % 2 == 0)     // hvis i % 2 == 0 er det spiller 1 sin tur
    {
      printf("Spiller 1, ditt trekk: ");
      scanf(" %i", &svar);
      if (sjekkBrett(svar-1) == true)
      {                 // her sjekkes det om ruten er ledig
        gBrett[svar - 1] = 'X';
      }
      else if (sjekkBrett(svar-1) == false)
      {
        printf("Rute ikke ledig\n");
        printf("Spiller 1, ditt trekk: ");
        scanf(" %i", &svar);
      }
    }
    else if (i % 2 != 0)// Hvis i % 2 != 0 så er det spiller 2 sin tur
    {
      printf("Spiller 2, ditt trekk: ");
      scanf(" %i", &svar);
      if (sjekkBrett(svar-1) == true)
      {                 // sjekker om rute er ledig
        gBrett[svar - 1] = 'O';
      }
      else if (sjekkBrett(svar-1) == false)
      {
        printf("Rute ikke ledig\n");
        printf("Spiller 2, ditt trekk: ");
        scanf(" %i", &svar);
      }
    }
    if(sjekkVinner() == true && gBrett[i] == 'X') {
      return 1;         // her sjekkes vinner
    } else if(sjekkVinner() == true && gBrett[i] == 'O') {
      return 2;
    }
  }
}

