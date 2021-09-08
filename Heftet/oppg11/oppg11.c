#include <stdlib.h>
#include <stdio.h>

int main () {

    int tall[5],
        tall2[] = {6, 2, 10, 12, 19, 3, 7};

    char tekst[5],
         navn[] = "Lars Hansen",
         adresse[] = "Ringgata 111";

    tall[0] = 13,
    tall[1] = 67;

    tall[2] = tall[0] + tall[1];                            //legger sammen de 2 første tallene i tall[]
    printf("%i + %i = %i\n", tall[0], tall[1], tall[2]);    

    printf("80 halvert er: %i\n", tall[2] / 2);             //halverer tall[2]

    tall[3] = tall2[0] + tall2[1] + tall2[2] + tall2[3];
    printf("%i + %i + %i + %i = %i\n", tall2[0], tall2[1], tall2[2], tall2[3], tall[3]);

    tall[4] = tall2[4] + tall2[5] + tall2[6];
    printf("%i + %i + %i = %i\n", tall2[4], tall2[5], tall2[6], tall[4]);

    printf("de 2 sist oppdaterte tallene: %i og %i\n", tall[3], tall[4]);

    ++tall[2], ++tall[2], ++tall[2], ++tall[2];
    printf("verdien nå: %i\n", tall[2]);

    tekst[1] = 'A',
    tekst[3] = 'E',
    tekst[0] = navn[5],
    tekst[2] = navn[0];

    printf("Kua har %s\n", tekst);
    
    printf("%c%c%c\n", adresse[9], adresse[10], adresse[11]);
    printf("%s\n%s\n", navn, adresse);

    return 0;
}
