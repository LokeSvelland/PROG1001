#include <stdio.h>



const int hoyde = 4;     //konstant høyde
const int PI = 3.14;     //konstant PI
const int minVerdi = 5;  // min verdi som kan leses inn
const int maxVerdi = 20; // maks verdi som kan leses inn

int main()
{

    int volum, // tomme variabler
        radie;
                        // leser inn radie fra brukeren
    printf("Skriv inn verdi mellom 5 og 20: \n");
    scanf("%d", &radie);
                        // går gjennom og regner ut hvert volum opptil bruker
                        // sitt innleste tall
    for (int i = 1; i <= radie; i++)
    {
                        // regner volum og ganger for hver gang loopen går
        volum = 4 * PI * (i * radie ^ 2) * hoyde;
                        // printer ut svar
        printf("volum til sylinder: %i\n", volum);
    }
}
