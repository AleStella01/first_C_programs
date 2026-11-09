//Alunno: Stella Alessandro     Classe: 3B      Data:20/12/2017
// Gestione Voti

#include <stdio.h>
#include <stdlib.h>

#define MAX 35  //Numero di elementi massimo da poter inserire
float voti[MAX];
int n=0;  //Numero di voti effettivamente presenti

//PROTOTIPI
int menu();
void carica();
void visualizza();
void sufficienze();
void alto();
void basso();
void media();

int main()
{
    int scelta;

        do {
            system ("cls");
            scelta=menu();
            switch (scelta) {
                case 1 :
                        carica();
                        break;
                case 2 :
                        if (n!=0)
                            visualizza();
                        else
                            printf ("Non sono stati inseriti voti!\n");
                        system ("pause");
                        break;
                case 3 :
                        if (n!=0)
                            sufficienze();
                        else
                            printf ("Non sono stati inseriti voti!\n");
                        system ("pause");
                        break;
                case 4 :
                        if (n!=0)
                            alto();
                        else
                            printf ("Non sono stati inseriti voti!\n");
                        system ("pause");
                        break;
                case 5 :
                        if (n!=0)
                            basso();
                        else
                           printf ("Non sono stati inseriti voti!\n");
                        system ("pause");
                        break;
                case 6 :
                        if (n!=0)
                            media();
                        else
                            printf ("Non sono stati inseriti voti!\n");
                        system ("pause");
                        break;
                }
        }while (scelta!=0);
        printf ("\n=========>GRAZIE E ALLA PROSSIMA<============");
    return 0;
}

int menu (){
    int x;

    do {
        printf ("\nCosa vuoi fare: \n");
        printf ("1. Carica voti \n");
        printf ("2. Visualizzare i voti \n");
        printf ("3. Visualizzare il numero di sufficienze \n");
        printf ("4. Visualizzare quale e' il voto piu' alto \n");
        printf ("5. Visualizzare quale e' il voto piu' basso \n");
        printf ("6. Visualizzare la media del compito \n");
        printf ("0. ESCI\n");
        printf ("\nQuale scegli?");
        scanf ("%d", &x);
        if (x<0 || x>6){ //La scelta non deve essere maggiore di sei
            system ("CLS");
            printf ("ERRORE: SCELTA NON ACCETTABILE\n\n\n");
        }
    } while (x<0 || x>5);
    return x;
}

void carica (){
    int i;
    printf ("Quanti voti devi inserire? ");
    scanf ("%d",&n);
    for (i=0;i<n;i++){
            do {
                printf ("Inserisci qui il voto dello studente %d :",i+1);
                scanf ("%f",&voti[i]);
                if (voti[i]<0 || voti[i]>10)
                    system ("cls");
            } while (voti[i]<0 || voti[i]>10);
    }
}
void visualizza (){
    int i;

    for (i=0;i<n;i++)
        printf ("Voto dell'alunno %d: %.1f \n",i+1,voti[i]);
}

void sufficienze (){
    int i,c=0;

    for (i=0;i<n;i++){
        if (voti[i]>=6)
            c++;
    }
    printf ("Il numero di sufficienze e': %d",c);
}

void alto (){
    int i=0,x,c=0;

    x=voti[i];
    for (i=0;i<n;i++){
            if (voti[i]>x)
                x=voti[i];
            if (voti[i]==x)
                c++;
    }
    printf ("Il voto piu' alto e': %d\n",x);
    printf ("Il voto si e' ripetuto %d volte",c);
}

void basso (){
    int i=0,x,c=0;

    x=voti[i];
    for (i=0;i<n;i++){
            if (voti[i]<x)
                x=voti[i];
            if (voti[i]==x)
                c++;
    }
    printf ("Il voto piu' basso e': %d\n",x);
    printf ("Il voto si e' ripetuto %d volte",c);
}

void media (){
    int i;
    float x=0;

    for (i=0;i<n;i++){
        x+=voti[i];
    }
    x=x/i;
    printf ("La media del compito e': %.2f",x);
}
