//Alunno: Stella Alessandro         Classe: 3B          Data:17/1/2018
//Smistamento numeri

#include <stdio.h>
#include <stdlib.h>
#define MAX 40

//Prototipi
void menu(int*);
void carica(float*,int*);
void visualizza(float*,int,int);
void smista(float*,int,float*,int*,float*,int*);

int main()
{
    int s,n1,n2=0,n3=0,c;
    float vet1[MAX];
    float vet2[MAX];
    float vet3[MAX];

    do{
        menu(&s);
        switch (s){
            case 1:
                system ("cls");
                carica(vet1,&n1);
                system ("pause");
                break;
            case 2:
                system ("cls");
                c=0;
                if (n1!=0)
                    visualizza(vet1,n1,c);
                else
                    printf ("Non sono stati inseriti i numeri!\n");
                system ("pause");
                break;
            case 3:
                system ("cls");
                if (n1!=0)
                    smista(vet1,n1,vet2,&n2,vet3,&n3);
                else
                    printf ("Non sono stati inseriti numeri!\n");
                break;
            case 4:
                system ("cls");
                if (n2!=0){
                    c=1;
                    printf("Numeri positivi:\n");
                    visualizza(vet2,n2,c);
                    printf("\n");
                    printf("Numeri negativi:\n");
                    c=2;
                    visualizza(vet3,n3,c);
                    system ("pause");
                }
                else
                    printf("Non sono stati smistati i valori!\n");
                break;
            system ("cls");
        }
    }while(s!=0);
    printf ("----->Grazie e alla prossima<-----");
    return 0;
}

void menu (int *s){

    printf ("Tra le seguenti azioni:\n");
    printf ("1. Caricare il vettore\n");
    printf ("2. Visualizzare i numeri inseriti\n");
    printf ("3. Smistare i numeri\n");
    printf ("4. Visualizzare i numeri smistati\n");
    printf ("0. ESCI\n");
    do {
        printf ("\nCosa vuoi fare? ");
        scanf ("%d",s);
        if (*s<0 || *s>4){
            printf ("Errore: Scelta non accettabile!!\n");
        }
    }while (*s<0 || *s>4);
}

void carica (float vet[], int*n){
    int i;
    do{
        printf ("Quanti numeri vuoi caricare? ");
        scanf ("%d",n);
    }while (*n<1 || *n>MAX);
    for (i=0;i<*n;i++){
        printf ("Inserisci il %d valore",i+1);
        scanf ("%f",&vet[i]);
    }
}
void visualizza (float vet[],int n,int c){
    int i;
    if (n==0){
        if (c==1)
            printf ("Non sono presenti numeri positivi!");
        else
            printf ("Non sono presenti numeri negativi!");
    }
    else
        for (i=0;i<n;i++){
            printf ("%.2f\n",vet[i]);
        }
}

void smista (float vet1[], int n1, float vet2[], int*n2, float vet3[], int*n3){
    int i,p,t;
    p=0;
    t=0;
    for (i=0;i<n1;i++){
        if (vet1[i]>0){
            vet2[p]=vet1[i];
            p++;
        }
        else
            if (vet1[i]<0){
               vet3[t]=vet1[i];
               t++;
            }
    }
    *n2=p;
    *n3=t;
}

