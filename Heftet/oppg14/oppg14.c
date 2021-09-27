#include <stdio.h>

int main()
{
    // oppgaven skal telle hvor mange ganger while løkken har loopet, så ta gjennomsnitt og sum

    int heltall,        // lager tomme variabler
        snitt,
        antall = 0,
        sum;

    while (heltall > 0) // leser inn positive heltall fra bruker
    {
        printf("Skriv inn et positivt heltall: \n");
        scanf("%d", &heltall);
        antall++;       // teller opp antall ganger det looper
                        // definerer at det skal være positve tall
        sum = heltall + antall;
    } while (heltall <= 0) {
        printf("antall ganger loopet: %i\n", antall);
        printf("sum totalt av alle innleste heltall: %i\n", sum);
        return 0;
    }
}
