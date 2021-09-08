#include <stdio.h>
#include <stdlib.h>

int main()
{

    int totalSekunder = 312304,                                                                                     //her defineres og regnes ut timer/minutter/sekunder
        timer = totalSekunder / 60 / 60,
        minutter = (totalSekunder / 60) - (timer * 60),
        sekunder = totalSekunder - (minutter * 60) - (timer * 60 * 60);


    printf("312304 sekunder tilsvarer: %itime(r), %iminutt(er) og %isekunde(er)\n", timer, minutter, sekunder);     //skriver ut svar

    return 0;
}