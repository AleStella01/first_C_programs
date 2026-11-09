//Alunno: Stella Alessandro     Classe:3B       Data:08/11/2017
// MCD

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,mcd;

    printf ("Questo programma calcola MCD di due numeri interi\n");
    do {
        system ("cls");
        printf ("\n Inserisci qui il primo numero: ");
        scanf ("%d",&a);
    }while (a==0); //Non si può fare il MCD con 0
    do{
        system ("cls");
        printf ("\nInserisci qui il secondo numero: ");
        scanf ("%d",&b);
    } while (b==0);
    a=abs(a);
    b=abs(b);
    do {
        if (a>b)
            a=a-b;
        else
            b=b-a;
    }while (a!=b);
    mcd=a; // Associo l'ultimo valore del ciclo alla variabile mcd
    system ("cls");
    printf ("MCD = %d",mcd);
    return 0;
}
