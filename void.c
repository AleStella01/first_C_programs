// Alunno: Stella Alessandro        Classe:3B       Data: 2/11/2017
// Calcolatrice

#include <stdio.h>
#include <stdlib.h>

//prototipi di funzione
int menu();
int inserisci();
void somma();
void differenza();
void prodotto();
void quoziente();

int a,b,c,
    g=0;

int main()
{
    int s, ris;
    char sc;

    do {
        system ("cls");
        s=menu();
        switch (s){
            case 1: system ("cls");
                    a=inserisci();
                    b=inserisci();
                    break;
            case 2: system ("cls");
                    somma();
                    break;
            case 3: system ("cls");
                    differenza();
                    break;
            case 4: system ("cls");
                    prodotto();
                    break;
            case 5: system ("cls");
                    quoziente();
                    break;
        }
        system ("cls");
        //printf ("Vuoi effettuare altre operazioni? (S/N)");
        fflush (stdin);
        //scanf ("%c",&sc);
    }while (s!=0);
    return 0;
}

int menu(){

    int x;

    printf ("\n1.Inserire gli operandi");
    printf ("\n2.Somma");
    printf ("\n3.Differenza");
    printf ("\n4.Prodotto");
    printf ("\n5.Quoziente");
    printf ("\n\n0.Esci dal programma\n");
    do {
        printf ("\n\nInserisci la scelta:");
        scanf ("%d",&x);
    } while (x<0 || x>5);
    return (x);
}

int inserisci(){
    int x;

    printf ("Inserisci l'operando:");
    scanf ("%d",&x);
    return (x);
}

void somma(){
    int x;

    x=a+b;
    printf("\n\n%d+%d=%d\n\n",a,b,x);
    system ("pause");
}

void differenza(){
    int x;

    x=a-b;
    printf ("\n\n%d-%d=%d\n\n",a,b,x);
    system ("pause");
}

void prodotto() {
    int x;

    x=a*b;
    printf ("\n\n%dX%d=%d\n\n",a,b,x);
    system ("pause");
}

void quoziente(){
    float x;

    if (a!=0 && b==0){
        printf ("Non e' possibile dividere un numero per zero!\n");
        system ("pause");
    }
    else
        x=a/b;
    printf ("\n\n%d/%d=%d\n\n",a,b,x);
    system ("pause");
}
