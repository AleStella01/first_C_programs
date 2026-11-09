// Alunno: Stella Alessandro        Classe: 3B      Data.31/01/2018
//Gioco coi vettori
#include <stdio.h>
#include <stdlib.h>
//Prototipi
int menu();
void carica(int*,int*);
void visualizza(int*,int);
void asinistra (int*,int*,char);
void adestra(int*,int*,char);
void inv(int*,int);
#define MAX 50
int main(){
    int s,n=0;
    char sc;
    int vet[MAX];
    do{
        s=menu();
        system ("cls");
        switch (s){
            case 1:
                carica(vet,&n);
                break;
            case 2:
                if (n!=0)
                    visualizza(vet,n);
                else
                    printf ("Il vettore non e' stato caricato!\n");
                break;
            case 3:
                if (n!=0){
                    sc='s';
                    asinistra(vet,&n,sc);
                }
                else
                    printf ("Il vettore non e' stato caicato!\n");
                break;
            case 4:
                if (n!=0){
                    sc='s';
                    adestra(vet,&n,sc);
                }
                else
                    printf ("Il vettore non e' stato caricato!\n");
                break;
            case 5:
                if (n!=0){
                    sc='r';
                    asinistra(vet,&n,sc);
                }
                else
                    printf ("Non e' stato caricato il vettore!\n");
                break;
            case 6:
                if (n!=0){
                    sc='r';
                    adestra(vet,&n,sc);
                }
                else
                    printf ("Non e' stato caricato il vettore!\n");
                break;
            case 7:
                if (n!=0)
                    inv(vet,n);
                else
                    printf ("Non sono stati inseriti i valori!\n");
        }
        system ("pause");
        system ("cls");
    }while (s!=0);
    printf (">>>>>Grazie e alla prossima!<<<<\n");
    return 0;
}

int menu(){
    int s;
    do{
        printf ("Tra le seguenti opzioni:\n\n");
        printf ("1. Caricare i valori\n");
        printf ("2. Visualizzare i valori inseriti\n");
        printf ("3. Eseguire uno shift sinistro\n");
        printf ("4. Eseguire uno shift destro\n");
        printf ("5. Eseguire una rotazione sinistra\n");
        printf ("6. Eseguire una rotazione destra\n");
        printf ("7. Eseguire un'inversione\n");
        printf ("0. ESCI\n\n");
        printf ("Cosa vuoi fare? ");
        scanf ("%d",&s);
        if (s<0 || s>7){
            system("cls");
            printf ("ERRORE: SCELTA NON ACCETTABILE!\n");
        }
    }while (s<0 || s>7);
    return s;
}

void carica (int vet[],int*n){
    int i;
    do{
        printf ("Quanti numeri devi inserire? ");
        scanf ("%d",n);
        if (*n<0 || *n>MAX){
            system ("cls");
            printf ("ERRORE: SCELTA NON ACCETTABILE!\n");
        }
    }while (*n<0 || *n>MAX);
    for (i=0;i<(*n);i++){
        printf ("Inserisci il %d valore: ",i+1);
        scanf ("%d",&vet[i]);
    }
}

void visualizza(int vet[],int n){
    int i;
    for (i=0;i<n;i++)
        printf ("%d: %d\n",i+1,vet[i]);
}

void asinistra(int vet[],int*n,char s){
    int i,t,x;
    do {
        printf ("Quale posizione vuoi eliminare? ");
        scanf ("%d",&i);
        if (i<0 || i>(*n)){
            system ("cls");
            printf ("ERRORE: SCELTA NON ACCETTABILE!\n");
        }
    }while (i<0 || i>(*n));
    x=i;
        if (i==(*n)-1){//Se vuole eseguire uno shift sull'ultima posizione, basta decrementare di 1 *n
            *n=*n-1;
            printf ("Ultima posizione eliminata!\n");
        }
        else {
            if (s=='s' || s=='S'){
                t=0;
                *n=*n-1;
            }
            else
                t=vet[i];
            for (;i<(*n);i++)
                vet[i]=vet[i+1];//La posizione attuale assume il valore della successiva
            if (s=='r'||s=='R')
                vet[x]=t;
            printf ("Shift eseguito!\n");
        }
}

void adestra(int vet[],int*n,char s){
    int i,t;
    if (s=='s'||s=='S'){
        do{
            printf ("Da quale posizione vuoi cominciare ad eseguire lo shift? ");
            scanf ("%d",&t);
            if (t<0 || t>(*n)){
                system ("cls");
                printf ("ERRORE: SCELTA NON ACCETTABILE!\n");
            }
        }while (t<0 || t>(*n));
    }
    if(s=='r'||s=='R')
        t=vet[*n-1];
    else
        t=0;
    for (i=(*n)-1;i>t;i--)
        vet[i+1]=vet[i];
    vet[0]=t;
    printf ("Operazione eseguita!\n");
    if (s=='s'||s=='S')
        *n=*n+1;
}

void inv(int vet[],int n){
    int i,x,p;
    for (i=0,p=n-1;i<(n/2);i++,p--){
        x=vet[i];
        vet[i]=vet[p];
        vet[p]=x;
    }
    printf ("Operazione eseguita!\n");
}
