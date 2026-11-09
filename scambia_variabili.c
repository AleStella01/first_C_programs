//Alunno: Stella Alessandro         Classe:3B       Data:09/11/2017
// Scambia Variabili

#include <stdio.h>
#include <stdlib.h>

//prototipi di funzione
void carica();
void scambia();
void stampa();

int main()
{
    int a,b,c;

    carica(&a,&b,&c);
    if (a>b)
        scambia(&a,&b);
    if (a>c)
        scambia (&a,&c);
    if (b>c)
        scambia (&b,&c);
    stampa(&a,&b,&c);

    return 0;
}

void carica(int*a,int*b,int*c){

    printf ("Inserisci qui il primo numero: ");
    scanf ("%d",a);
    printf ("\n\nInserisci qui il secondo numero: ");
    scanf ("%d",b);
    printf ("\n\nInserisci qui il terzo numero: ");
    scanf ("%d",c);

}

void scambia(int*a,int*b){

int x;

    x=*a;
    *a=*b;
    *b=x;

}

void stampa(int*a,int*b,int*c){

    printf ("\n\n\nL'ordine dei numeri e': %d, %d, %d \n\n",*a,*b,*c);

}
