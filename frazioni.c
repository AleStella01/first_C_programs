// Alunno: Stella Alessandro        Classe: 3B

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//prototipi di funzione
int mcm(int,int);//Serve per le operazioni di somma e differenza
int MCD(int,int);//Serve per semplificare la frazione
void carica(int*,int*,int*,int*);//Con puntatori perché deve modificare i valori
void somma(int,int,int,int);//Senza puntatori perché non modifica valori
void differenza(int,int,int,int);//Senza puntatori perché non modifica valori
void prodotto(int,int,int,int);//Senza puntatori perché non modifica valori
void quoziente(int,int,int,int);//Senza puntatori perché non modifica valori

int main()
{
    int scelta;
    int c=0;
    int n1;
    int n2;
    int d1;
    int d2;

    system ("color ce");
    do {
        do {
            printf ("\nCosa vuoi fare: \n");
            printf ("1. Caricare frazioni \n");
            printf ("2. Fare una somma \n");
            printf ("3. Fare una sottrazione \n");
            printf ("4. Fare una moltiplicazione \n");
            printf ("5. Fare la divisione \n");
            printf ("0. ESCI\n");
            printf ("\nQuale scegli?");
            scanf ("%d", &scelta);
            if (scelta<0 || scelta>5){ //La scelta non deve essere maggiore di cinque
                system ("CLS");
                printf ("ERRORE: SCELTA NON ACCETTABILE\n\n\n");
            }
        } while (scelta<0 || scelta>5);
        switch (scelta) {
            case 1 :
                    system ("cls");
                    c=1;//Diventa 1 per dimostrare che gli operandi sono stati inseriti
                    carica(&n1,&d1,&n2,&d2);
                    //printf("\n>>>>>>%d\t%d\t%d\t%d",n1,d1,n2,d2);
                    break;
            case 2 :if(c!=0){ //Se gli operandi non sono stati inseriti, non effettua nessuna operazione
                        system ("cls");
                        somma(n1,d1,n2,d2);
                    }
                    else{
                        system ("cls");
                        printf ("ERRORE 404: OPERANDI NON TROVATI");
                    }
                    break;
            case 3 :
                    if(c!=0){ //Se gli operandi non sono stati inseriti, non effettua nessuna operazione
                        system ("cls");
                        differenza(n1,d1,n2,d2);
                    }
                    else{
                        system ("cls");
                        printf ("ERRORE 404: OPERANDI NON TROVATI");

                    }
                    break;
            case 4 :
                    if(c!=0){//Se gli operandi non sono stati inseriti, non effettua nessuna operazione
                        system ("cls");
                        prodotto(n1,d1,n2,d2);
                    }
                    else{
                        system ("cls");
                        printf ("ERRORE 404: OPERANDI NON TROVATI");
                    }
                    break;
            case 5 :
                    if (c!=0){//Se gli operandi non sono stati inseriti, non effettua nessuna operazione
                        system ("cls");
                        quoziente(n1,d1,n2,d2);
                    }
                    else{
                        system ("cls");
                        printf ("ERRORE 404: OPERANDI NON TROVATI");
                    }
                    break;
        }
    } while (scelta!=0);//Se la scelta non è 0, non esce
    printf ("GRAZIE E ALLA PROSSIMA");
    return 0;
}

//sottoprogrammi per calcolare le frazioni

int mcm (int a, int b){
    int sa=a;
    int sb=b;

    if (sa==sb) //Se i numeratori sono uguali
        return sa; // Restituisce uno dei due
    else
        if (sa%sb==0) //Se il primo è multiplo del secondo
            return sa; // Restituisce il primo
        else
            if (sb%sa==0) //Se il secondo è multiplo del primo
                return sb; //Restituisce il secondo
            else {
                do { //Quando il primo e il secondo sono completamente diversi
                    if (sa<sb)
                        sa+=a;
                    else
                        sb+=b;
                } while (sa!=sb);//Fino a quando a&b non sono uguali
                return sa;
            }
}

int MCD(int a, int b){
    a=abs(a);
    b=abs(b);
     do {
        if (a>b)
            a=a-b;
        else
            b=b-a;
    }while (a!=b);

    return a;
}

void carica(int*a,int*b,int*c,int*d){
    printf ("Inserire di seguito le frazioni \n");
    printf ("Inserisci qui il primo numeratore: ");
    scanf ("%d",a);
    do {
        printf ("Inserisci qui il primo denominatore:");
        scanf ("%d",b);
        if (b==0)
            printf ("ERRORE, IL DENOMINATORE DEVE ESSERE SEMPRE MAGGIORE DI 0 \n");
    } while (b==0);
    printf ("Inserisci qui il secondo numeratore: ");
    scanf ("%d",c);
    do {
        printf ("Inserisci qui il secondo denominatore: ");
        scanf ("%d",d);
        if (d==0)
            printf ("ERRORE, IL DENOMINATORE DEVE ESSERE SEMPRE MAGGIORE DI 0");
    } while (d==0);
}
void somma(int n1,int d1,int n2,int d2){
    int prod,add,d;
        prod=mcm(d1,d2);
        add=(prod/d1)*n1+(prod/d2)*n2;
        d=MCD(prod,add);
        prod=prod/d;
        add=add/d;
        printf ("La somma tra %d/%d e %d/%d e': %d/%d\n\n\n",n1,d1,n2,d2,add,prod);

}
void differenza(int n1,int d1,int n2,int d2){
    int prod,sottr,d;
        prod=d1*d2;
        sottr=(prod/d1)*n1-(prod/d2)*n2;
        d=MCD(prod,sottr);
        prod=prod/d;
        sottr=sottr/d;
        printf ("La differenza tra %d/%d e %d/%d e': %d/%d\n\n\n",n1,d1,n2,d2,sottr,prod);
}
void prodotto(int n1,int d1,int n2,int d2) {
    int prod,molt,d;
        prod=d1*d2;
        molt=n1*n2;
        d=MCD(prod,molt);
        prod=prod/d;
        molt=molt/d;
        printf ("Il prodotto tra %d/%d e %d/%d e': %d/%d\n\n\n",n1,d1,n2,d2,molt,prod);

}
void quoziente(int n1,int d1,int n2,int d2){
    int prod,divs,d;
        prod=d1*n2;
        divs=n1*d2;
        d=MCD(prod,divs);
        prod=prod/d;
        divs=divs/d;
        printf ("Il quoziente tra %d/%d e %d/%d e': %d/%d\n\n\n",n1,d1,n2,d2,divs,prod);

}
