//Alunno: Stella Alessandro     Classe: 3B      Data: 05/04/2018
//Esercizio  con i Record

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 30

typedef struct{
    int giorno;
    int mese;
    int anno;
}data;

typedef struct{
    char nome[25];
    char cognome[30];
    char codf[17];
    data nato;
    float media;
}typealunno;


//PROTOTIPI
int menu();
bool controlla(char*);
bool contrf(char*);
bool contrd(data*);
void carica(typealunno*,int*);
void converti(char*);
void stampanomi(typealunno*,int);
int contasuf(typealunno*,int);
float cercamax(typealunno*,int);
void stampamax(typealunno*,float,int);
bool cercains(typealunno*,int);

void main()
{
    typealunno vet[MAX];
    int n=0,s;
    do{
        s=menu();
        switch(s){
            case 1:
                carica(vet,&n);
                break;
            case 2:
                if(n!=0)
                    stampanomi(vet,n);
                else
                    printf ("ERRORE: NON SONO STATI CARICATI I DATI!\n");
                break;
            case 3:
                if (n!=0)
                    printf ("Il numero di alunni che hanno la media piu' alta e': %d\n",contasuf(vet,n));
        }
    }while (s!=0);
}

//SOTTOPROGRAMMI
int menu(){
    int s;

    do{
        printf ("Tra le seguenti funzioni:\n");
        printf ("1. Caricare i dati relativi agli alunni\n");
        printf ("2. Visualizzare i dati dei ragazzi che hanno il cognome che inizia con la M\n");
        printf ("3. Contare quanti sono gli alunni che hanno la media piu' alta\n");
        printf ("4. Visualizzare i dati degli alunni con la media piu' alta\n");
        printf ("5. Verificare se c'e' almeno un'insufficienza\n");
        printf (" 0. ESCI\n\n");
        printf ("Quale operazione vuoi eseguire? ");
        scanf ("%d",&s);
        if (s<0 || s>5){
            system ("cls");
            printf ("ERRORE: SCELTA NON ACCETTABILE \n");
        }
    }while (s<0 || s>5);
    return s;
}

void carica(typealunno vet[], int*n){
    int i,c;

    do{
        printf ("Quanti dati devi inserire? ");
        scanf ("%d", n);
        if (*n<0 || *n>MAX){
            system ("cls");
            printf ("ERRORE: SCELTA NON ACCETTABILE\n");
        }
    } while (*n<0 || *n>MAX);
    for (i=0;i<*n;i++){
        do {
            printf ("Inserisci il nome (%d): ",i);
            fflush (stdin);
            gets (vet[i].nome);
        } while (controlla(vet[i].nome));//Devono essere inserite sole lettere
        converti(vet[i].nome);
        do{
            printf ("Inserisci il cognome (%d): ",i);
            fflush (stdin);
            gets (vet[i].cognome);
        }while(controlla(vet[i].cognome));//devonp essere inserite sole lettere
        converti(vet[i].cognome);
        do{
            do{
                printf ("Inserisci il codice fiscale (%d): ",i);
                fflush (stdin);
                gets (vet[i].codf);
            }while (strlen(vet[i].codf)<16 || strlen(vet[i].codf)>16);//Il codice fiscale è di 16 caratteri
        }while(contrf(vet[i].codf));//Devono essere inseriti solo lettere e numeri
        converti(vet[i].codf);
        do{
            printf ("Inserisci la data di nascita (%d):\n");
            printf ("Inserisci il giorno: ");
            do{
                c=scanf ("%d",&vet[i].nato.giorno);
                if (c==0){
                    scanf ("%*[^\n]");
                    printf ("Attenzione: input non valido");
                }
            }while (c==0);
            printf ("Inserisci il mese: ");
            scanf
        }while (contrd (vet[i].nato));
        printf ("Iserisci la media: ");
        scanf ("%f",&vet[i].media);
    }
}

bool controlla(char stringa[]){
    int i=0,n;
    bool x=false;

    n=strlen(stringa);
    if (stringa[i]==' ' || stringa[i]==39)
        x=true;
    for (i=1;i<n && !x;i++){
            if (!((stringa[i]>'A' && stringa[i]<'Z' )||(stringa[i]>'a' && stringa[i]<'z')||(stringa[i]==' ')||(stringa[i]==39)))
                x=true;
    }
    return x;
}

bool contrf(char stringa[]){
    int i;
    bool x=false;

    for (i=0;i<6 && !x;i++)
        if (!((stringa[i]>='a' && stringa[i]<='z')||(stringa[i]>='A' && stringa[i]<='Z'))){ //Le prime sei posizioni devono contenere solo caratteri
            x=true;
            return x;
    }
    for (i=6;i<8 && !x;i++)
        if (!(stringa[i]>='0' && stringa[i]<='9')){
            x=true;
            return x;
        }
    if (!((stringa[8]>='a' && stringa[8]<='z')||(stringa[8]>='A'&&stringa[8]<='Z'))){
        x=true;
        return x;
    }
    for (i=9;i<11 && !x; i++)
        if (!(stringa[i]>='0' && stringa[i]<='9')){
            x=true;
            return x;
        }
    if (!((stringa[11]>='a'&&stringa[11]<='z')||(stringa[11]>='A'&&stringa[11]<='Z'))){
        x=true;
        return x;
    }
    for (i=12;i<15 && !x;i++)
        if (!(stringa[i]>='0'&&stringa[i]<='9')){
            x=true;
            return x;
        }
    if (!((stringa[15]>='a'&&stringa[15]<='z')||(stringa[i]>='A'&&stringa[i]<='Z'))){
        x=true;
        return x;
    }
}

bool contrd(data vet[]){
    x=false;
}

void converti(char stringa[]){
    int i,n;

    n=strlen(stringa);
    for(i=0,i<n,i++){
        if (stringa[i]>='a' && stringa[i]<='z')
            stringa[i]=stringa[i]-32;
    }
}

void stampanomi(typealunno vet[],int n){
    int i,

    for (i=0;i<n;i++){
        if (vet[i].cognome[0]=='M'){
            printf ("Il nome e': %s\t",vet[i].nome);
            printf ("Il cognome e': %s \t",vet[i].cognome);
            printf ("Il codice fiscale e':%s\t",vet[i].codf);
            printf ("La media e':%f\n",vet[i].media);
        }
    }
}

int contasuf(typealunno vet[],int n){
    int i,c=0;

    for(i=0;i<n;i++)
        if (vet[i].media>=6)
            c++;
    return c;
}

float cercamax(typealunno vet[],int n){
    int i;
    float m;

    m=vet[i].media;
    for(i=1;i<n;i++)
        if(vet[i].media>m)
            m=vet[i].media;
    return m;
}

void stampamax(typealunno vet[],float m,int n){
    int i;

    for(i=0;i<n;i++)
        if (vet[i].media==m){
            printf ("Nome: %s \t",vet[i].nome);
            printf ("Cognome: %s\t",vet[i].cognome);
            printf ("Codice fiscale:%s\n",vet[i].codf);
        }
}

bool cercains(typealunno vet[],int n){
    int i;
    bool x=false;

    for(i=0;i<n && !x;i++)
        if (vet[i].media<6)
            x=true;
    return x;
}
