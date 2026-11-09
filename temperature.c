// Alunno: Stella Alessandro    Classe: 3B

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sc;
    char risp;
    int c=0;
    double media;
    double somma=0;
    double temperatura;

    system ("COLOR f0");
    do {
        printf ("Dalle temperature inserite, calcolare la temperatura media \n");
        do {
            printf ("Inserisci qui la temperatura: ");
            scanf ("%lf",&temperatura);
            somma+=temperatura;
            c++;
            printf ("Hai altre temperature? (S/N)");
            fflush (stdin);
            scanf ("%c",&sc);
            system ("CLS");
        } while (sc=='S' || sc=='s');
        media=somma/c;
        printf ("La temperatura media e': %.2lf *C", media);
        printf ("\nVuoi inserire altre temperature? (S/N)");
        fflush (stdin);
        scanf ("%c",&risp);
    }while (risp=='S' || risp=='s');
    system ("CLS");
    printf ("Grazie e alla prossima");
}
