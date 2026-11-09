// Alunno: Stella Alessandro        Classe: 3B

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c=0;
    int n;
    double somma=0;
    double altezza;
    double media;
    char sc;

    do {
        printf ("Quante altezze devi inserire? ");
        scanf ("%d",&n);
        do {
            c=c+1;
            system ("CLS");
            printf ("Inserisci qui l'altezza: ");
            scanf ("%lf",&altezza);
            somma=somma+altezza;
        } while (c<n);
        system ("CLS");
        media=somma/n;
        printf ("L'altezza media e':%.2lf",media);
        printf ("\nVuoi inserire altre altezze?(S/N)");
        fflush (stdin);
        scanf ("%c",&sc);
        system ("CLS");
    } while (sc=='S' || sc=='s');
    printf ("Grazie e alla prossima");
    return 0;
}
