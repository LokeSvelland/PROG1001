#include <stdio.h>

int main()
{

    int heltall,        // lager et tomt variabl
        snitt = 0,      // setter verdiene som 0 her
        antall = 0,     // oppdateres lenger nede i koden
        sum = 0;

    while (heltall > 0) // leser inn positive heltall fra bruker
    {
        printf("Skriv inn et positivt heltall: \n");
        scanf("%d", &heltall);
        antall++;       // teller opp antall ganger det looper
        sum += heltall;
                        // definerer at det skal være positve tall
                        // skver ut snitt, sum og antall ganger det har loopet
    } while (heltall <= 0) {
                        // fjerner 1 fra antall slik at den ikke teller
                        // med siste 0 / negative tall i loopen
        antall = antall - 1;
        printf("antall ganger loopet: %i\n", antall);
        printf("sum totalt av alle innleste heltall: %i\n", sum);
        snitt = sum / antall;
        printf("Gjennomsnittet av innleste tall: %.2f", (float)snitt);
        return 0;
    }
}
