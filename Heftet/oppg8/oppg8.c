#include <stdio.h>
#include <stdlib.h>

int main() {
    const int ANTALL = 17;

    int tall1 = 10, tall2 = 20, tall3 = 30, svar;

    // regnestykker med (+,-,*,/)
    svar = tall1 + tall2;
    printf("svaret er: %i\n", svar);

    svar = tall2 * tall3;
    printf("svaret er: %i\n", svar);

    svar  = tall3/tall1;
    printf("svaret er: %i\n", svar);

    svar = ANTALL - tall3;
    printf("svaret er: %i\n", svar);

    //regnestykker med (+=,-=,*=,/=)
    svar = tall1 += tall2;
    printf("svaret nå er: %i\n", svar);

    svar = tall2 * tall3;
    printf("svaret nå er: %i\n", svar);

    svar  = tall3/=tall1;
    printf("svaret nå er: %i\n", svar);

   tall2 += ANTALL;
   printf("Øker %i med %i\n", ANTALL, tall2);

    return 0;
}