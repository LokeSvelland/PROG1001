#include <stdio.h>               //  printf
#include <stdbool.h>             //  bool  - Denne SKAL vi bruke/include i
                                 //          dette emnet for å bruke boolean.
                                 //          Vi bruker IKKE  _Bool

int main() {

    int   heltall   = 19940212;
    float flyttall  = 304.312;
    char  tegn      = 'M';
    _Bool OK        = 1;          // _Bool-variable er '0' eller '1'
    bool  feil      = false;      // Bool er 'false' eller 'true'


    printf("heltall:  %i\n", heltall);
    printf("flyttall: %f\n", flyttall);
    printf("tegn:     %c\n", tegn);
    printf("OK:       %i\n", OK);
    printf("feil:     %i\n", feil);
    printf("\n\n");

                                  //  Alternative måter å skrive ut float på:
    printf("flyttall:  %e\n", flyttall);        //  Eksponensielt
    printf("flyttall:  %g\n", flyttall);        //  Maskinen "velger" ..  :-)
    printf("flyttall:  %g\n", flyttall*100);    //  Maskinen "velger" ..  :-)
    printf("flyttall:  %g\n", flyttall*1000);   //  Maskinen "velger" ..  :-)
    printf("flyttall:  %g\n", flyttall*10000);  //  Maskinen "velger" ..  :-)

}