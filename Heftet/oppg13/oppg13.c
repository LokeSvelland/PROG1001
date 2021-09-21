#include <stdio.h>
#include <stdbool.h>

                        // Oppgave ikke ferdi, da jeg ikke forstår 
                        //oppgaven helt

const int height = 4;   //konstant høyde 

const int PI = 3.14;    //konstant PI

int main() {

    int radie,          //tomme int til innleste verdier
        volum;

    do {
    printf("Skriv inn radien til sylinderet mellom 5 og 20: ");
    scanf(" %i", &radie);
    }  while (          //Leser inn tall mellom 5-20
        radie != 5 && radie !=6 && radie != 7 && radie != 8 && radie != 9 &&
        radie != 10 && radie !=11 && radie != 12 && radie != 13 && radie != 14
        && radie != 15 && radie !=16 && radie != 17 && radie != 18 &&
        radie != 19 && radie != 20
    );                  // skriver ut radien
    printf("\nRadien til sylinderet: %i\n", radie);

    volum = (4*PI*radie^2) * height;
    printf("Volumet til sylinderet: %i", volum);

    return 0;

}
