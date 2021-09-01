//#include <stdio.h>                      //gir tilgang til printf

//Hovedprogrammet
int main() {

    int value1, value2, sum;            //3 heltallsvariabler 


    value1 = 50;                        // definerer verdi av variablene
    value2 = 25;
    sum = value1 + value2;              // regner sum av variabler

    value1 = 100;                       //blir fortsatt samme svar som før, fordi den er lagt etter sum er definert
                                        // viss vi legger inn sum = value1 + value2; her så vil svar endre seg

    printf("The sum of %i and %i is %i\n", value1, value2, sum);    //%i angir at det skal erstattes med en int

    return 0;                           //avlsutter programmet
}
