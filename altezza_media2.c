// Alunno: Stella Alessandro        Classe:3B

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c=0;
    int n;
    int num=0;
    int c1=0;
    double altezza;
    double somma=0;
    double media;
    char sc;

    do {
        system ("CLS");
        printf ("Quante altezze devi inserire? ");
        scanf ("%d",&n);
        do {
            c=c+1;
            system ("CLS");
            printf ("Inserisci qui l'altezza: ");
            scanf ("%lf",&altezza);
            if (altezza>=1.60 && altezza <=1.75) {
                somma=somma+altezza;
                num=num+1;
                media=somma/num;
            }
        } while (c<n);
        system ("CLS");
        printf ("La media delle altezze comprese tra 1.60 m e 1.75 m e':%.2lf m",media);
        printf ("\nVuoi inserire altre altezze? (S/N)");
        fflush (stdin);
        scanf ("%c",&sc);
    }while (sc=='S' || sc=='s');
    printf ("Grazie e alla prossima");
    return 0;
}
