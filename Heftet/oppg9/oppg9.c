#include <stdio.h>
#include <stdlib.h>

int main()
{

    int totalSekunder = 312304,
        timer,
        minutter,
        sekunder;

    timer = totalSekunder / 60 / 60;
  //  minutter = ;
  //  sekunder = ;

    printf("312304 sekunder tilsvarer: %itime(r), %iminutt(er) og %isekunde(er)\n", timer, minutter, sekunder);

    return 0;
}