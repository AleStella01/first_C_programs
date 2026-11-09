// Alunno: Stella Alessandro    Classe: 3B

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c=0;
    int n;
    int eta;
    int somma=0;
    int media;
    char sc;

    do {
        printf ("Quante eta' devi inserire?");
        scanf ("%d",&n);
        do {
            c=c+1;
            system ("CLS");
            printf ("Inserisci qui l'eta': ");
            scanf ("%d",&eta);
            somma=somma+eta;
        } while (c<n);
        media=somma/n;
        printf ("L'eta' media e':%d \n",media);
        printf ("\nVuoi inserire altre eta'? (S/N)");
        fflush (stdin);
        scanf ("%c",&sc);
        system ("CLS");
    }while (sc=='S' || sc=='s');
    printf ("Grazie e alla prossima");
    return 0;
}
