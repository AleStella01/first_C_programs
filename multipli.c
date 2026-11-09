// Alunno: Stella Alessandro        Classe: 3b

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max,
        min,
        num,
        somma=0;

        printf ("Inserisci qui l'estremo minore: ");
        scanf ("%d",&min);
        system ("cls");
        printf ("Inserisci l'estremo maggiore: ");
        scanf ("%d",&max);
        if (max<min){
            num=max;
            max=min;
            min=num;
        }
        do {
            if (min%5==0){
                somma+=min;
            }
            min++;
        } while (min<=max);
        system ("cls");
        printf ("La somma di tutti i multipli di 5 compresi tra gli estremi e': %d",somma);
    return 0;
}
