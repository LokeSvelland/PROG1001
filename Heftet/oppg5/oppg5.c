#include <stdio.h>                                 //printf

int main() {

    int lengde = 16,                               //lager 3 heltalls-variabler
        bredde = 12,
        hoyde = 8,
        sum;
    
    int arstall = 19600406;
    
    sum = (lengde * bredde * hoyde);               //formelen for volum av kloss L*B*H
    printf("Volumet til klossen er: %i\n", sum);

    return 0;
}
