// Alunno: Stella Alessandro        Classe: 3B

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c=0;
    int n;
    float prezzo;
    float somma=0;
    char sc;

    do {
        system ("COLOR f0");
        printf ("Qual'e' il numero della merce?");
        scanf ("%d",&n);
        do {
            system ("CLS");
            c=c+1;
            printf ("Inserisci qui il prezzo della %d * merce: EURO ",c);
            scanf ("%f",&prezzo);
            somma=somma+prezzo;
        }while (c<n);
        system ("CLS");
        printf ("Il prezzo totale e': %.2f EURO",somma);
        printf ("\nContinuare? (S/N)");
        fflush (stdin);
        scanf ("%c", &sc);
    }while (sc=='S' || sc=='s');
    system ("CLS");
    printf ("        Grazie e a domani");

    return 0;
}
