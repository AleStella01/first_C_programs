// Alunno: Stella Alessandro    Classe:3b

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=10;
    int somma=0;

    system ("Color 3b");
    do {
        somma+=num;
        num+=5;
    }while (num<=100);
    printf ("La somma di tutti i multipli di cinque compresi tra 10 e 100 e': %d",somma);

    return 0;
}
