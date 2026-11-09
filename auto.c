//Alunno: Alessandro Stella     Classe:3B       Data:14/04/2018
//Gestione Auto

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct {
    char matricola[18];
    char targa[8];
    char prod[25];
    char modello[25];
    float prezzo;
    int cilindrata;
}tipoauto;

//prototipi
int menu();
void converti(char*);
bool contrm(char*);
bool controlla(char*);
void registra();
void visualizza();
float prezzomedio();
void visualizza_prod();

int main()
{
    int s;
    float m;
    char tel[18];
    bool trova;

    do{
        s=menu();
        system ("cls");
        switch(s){
            case 1:
                registra();
                system("pause");
                break;
            case 2:
                visualizza();
                system("pause");
                break;
            case 3:
                m=prezzomedio();
                if(m==0)
                    printf("Non esiste File/Auto!\n");
                else
                    printf ("Il prezzo medio e': %.2f\n",m);
                system ("pause");
                break;
            case 4:
                visualizza_prod();
                system("pause");
                break;
            case 5:
                cerca();
                system("pause");
                break;
            case 6:
                printf("Inserisci il numero di telaio dell'auto da immatricolare: ");
                do{
                    fflush(stdin);
                    scanf("%s",&tel);
                }while(contrm(tel));
                converti(tel);
                immatricola(tel);
                break;
            case 7:
               trova=copia();
               if(trova)
                    visualizzaimm();
               break;
        }
        system ("cls");
    }while(s!=0);
    return 0;
}

int menu(){
    int s;
    do{
    printf ("Tra le seguenti opzioni:\n");
    printf ("1. Caricare le auto\n");
    printf ("2. Visualizzare i dati relativi alle auto\n");
    printf ("3. Calcolare il prezzo medio\n");
    printf ("4. Inserire una casa produttrice per visualizzare i dati delle auto presenti\n");
    printf ("5. Cercare un'auto tramite numero telaio\n");
    printf ("0. ESCI\n\n");
    printf ("\nQuale operazione vuoi eseguire? ");
    scanf("%d",&s);
    if(s<0 || s>5){
        system("cls");
        printf("Errore: Scelta non accettabile!");
    }
    }while(s<0 || s>5);
    return s;
}

void registra(){
    FILE*fauto;//puntatore al file
    tipoauto autom;//buffer
    char risp;
    fauto=fopen("auto.dat","ab");
    do{
        do{
            printf ("Inserisci il numero del telaio: ");
            fflush(stdin);
            gets(autom.matricola);
        }while(contrm(autom.matricola));
        converti(autom.matricola);
        do{
            printf ("Inserisci la casa produttrice: ");
            fflush(stdin);
            gets(autom.prod);
        }while(controlla(autom.prod));
        converti(autom.prod);
        do{
            printf("Inserisci il modello: ");
            fflush(stdin);
            gets(autom.modello);
        }while(controlla(autom.modello));
        converti(autom.modello);
        printf ("Inserisci il prezzo: ");
        scanf("%f",&autom.prezzo);
        printf ("Inserisci la cilindrata: ");
        scanf("%d",&autom.cilindrata);
        printf ("Auto usata? (S/N)");
        fflush(stdin);
        scanf ("%c",&risp);
        if (risp=='S' || risp=='s'){
            printf ("Inserisci la targa: ");
            fflush(stdin);
            gets(autom.targa);
            converti(autom.targa);
        }
        else
            strcpy(autom.targa," ");//Con le stringhe non si può scrivere autom.targa==' '
        fwrite(&autom,sizeof(tipoauto),1,fauto);
        printf ("Vuoi continuare? (S/N) ");
        fflush(stdin);
        scanf("%c",&risp);
    }while(risp=='S' || risp=='s');
    fclose(fauto);
}
bool contrm(char stringa[]){
    bool x=false;
    int i;
    if(!(stringa[0]>='0' && stringa[0]<='9')){
        x=true;
        return x;
    }
    if(!((stringa[1]>='a' && stringa[1]<='z')||(stringa[1]>='A' && stringa[1]<='Z'))){
        x=true;
        return x;
    }
    if(!(stringa[2]>='0' && stringa[2]<='9')){
        x=true;
        return x;
    }
    for (i=3;i<5;i++)
           if(!((stringa[i]>='a' && stringa[i]<='z')||(stringa[i]>='A' && stringa[i]<='Z'))){
            x=true;
            return x;
        }
    for (i=5;i<7;i++)
            if(!(stringa[i]>='0' && stringa[i]<='9')){
                x=true;
                return x;
            }
    if(!((stringa[7]>='a' && stringa[7]<='z')||(stringa[7]>='A' && stringa[7]<='Z'))){
        x=true;
        return x;
    }
    if(!(stringa[8]>='0' && stringa[8]<='9')){
        x=true;
        return x;
    }
    for (i=9;i<11;i++)
        if(!((stringa[i]>='a' && stringa[i]<='z')||(stringa[i]>='A' && stringa[i]<='Z'))){
            x=true;
            return x;
    }
    for (i=11;i<17;i++)
        if(!(stringa[i]>='0' && stringa[i]<='9')){
            x=true;
            return x;
        }
    return x;
}

bool controlla(char stringa[]){
    int i=0,n;
    bool x=false;

    n=strlen(stringa);
    if (stringa[i]==' ' || stringa[i]==39)
        x=true;
    for (i=1;i<n && !x;i++){
            if (!((stringa[i]>='A' && stringa[i]<='Z' )||(stringa[i]>='a' && stringa[i]<='z')||(stringa[i]==' ')||(stringa[i]==39)))
                x=true;
    }
    return x;
}

void converti(char stringa[]){
    int i,n;

    n=strlen(stringa);
    for(i=0;i<n;i++){
        if (stringa[i]>='a' && stringa[i]<='z')
            stringa[i]=stringa[i]-32;
    }
}

void visualizza(){
    FILE*fp;
    tipoauto autom;
    fp=fopen("auto.dat","rb");
    if(fp==NULL)
        printf("Il file non esiste!\n");
    else{
        fread(&autom,sizeof(tipoauto),1,fp);
        while(!feof(fp)){//se il file non è finito
            printf ("%s\t",autom.matricola);
            printf ("%s\t",autom.prod);
            printf ("%s\t",autom.modello);
            printf ("%d\t",autom.cilindrata);
            printf ("%.2f\t",autom.prezzo);
            if(strcmp(autom.targa," ")==0)
                printf("Auto non immatricolata\n");
            else
                printf("%s\n",autom.targa);
            fread(&autom,sizeof(tipoauto),1,fp);//si legge il successivo nel caso in cui sia finito, risalendo non esegue niente
        }
        fclose(fp);
    }
}

float prezzomedio(){
    FILE*fp;
    tipoauto autom;
    float m=0;
    int c=0;
    fp=fopen("auto.dat","rb");
    if(fp==NULL)
        printf("Il file non esiste\n");
    else{
        fread(&autom,sizeof(tipoauto),1,fp);
        while(!feof(fp)){
            if(strcmp(autom.targa," ")!=0){
                m=m+autom.prezzo;
                c++;
            }
            fread(&autom,sizeof(tipoauto),1,fp);
        }
        fclose(fp);
        if(c!=0)
            m=m/c;
        printf ("%d %f",c,m);
    }
    return m;
}

void visualizza_prod(){
    FILE*fp;
    tipoauto autom;
    char casa[25];
    fp=fopen("auto.dat","rb");
    if(fp==NULL)
        printf("Non esiste il file!\n");
    else{
        do{
            printf("Inserisci il nome della casa produttrice: ");
            fflush (stdin);
            gets(casa);
        }while(controlla(casa));
        converti(casa);
        fread(&autom,sizeof(tipoauto),1,fp);
        while(!feof(fp)){
            if(strcmp(autom.prod,casa)==0){
                printf("Il numero di telaio e': %s\t",autom.matricola);
                printf("Il modello e': %s\t",autom.modello);
                printf("Il prezzo e':%.2f\t",autom.prezzo);
                printf("La cilindrata e': %d\t",autom.cilindrata);
                if(strcmp(autom.targa," ")==0)
                    printf("Auto non immatricolata\n");
                else
                    printf("La targa e': %s\n",autom.targa);
            }
            fread(&autom,sizeof(tipoauto),1,fp);
        }
    }
    fclose(fp);
}

void cerca(){
    FILE*fp;
    tipoauto autom;
    char telaio[18];
    fp=fopen("auto.dat","rb");
    if(fp==NULL)
        printf("Non esiste il file\n");
    else{
        do{
            printf("Inserisci il numero di telaio: ");
            fflush(stdin);
            gets(telaio);
        }while(contrm(telaio));
        converti(telaio);
        fread(&autom,sizeof(tipoauto),1,fp);
        while (!feof(fp)){
            if(strcmp(autom.matricola,telaio)==0){
                printf("La casa produttrice e': %s\t",autom.prod);
                printf("Il modello e': %s\t",autom.modello);
                printf("Il prezzo e': %.2f\t",autom.prezzo);
                printf("La cilindrata e': %d\t",autom.cilindrata);
                if(strcmp(autom.targa," ")==0)
                    printf("Auto non immatricolata\n");
                else
                    printf("La targa e': %s\n",autom.targa);
            }
            fread(&autom,sizeof(tipoauto),1,fp);
        }
    }
    fclose(fp);
}

void visualizza_matricola(){
    FILE*fp;
    tipoauto autom;
    fp=fopen("auto.dat","rb");
    if(fp==NULL)
        printf("Il file non esiste\n");
    else{
        fread(&autom,sizeof(tipoauto),1,fp);
        while(!feof(fp)){
            if(strcmp(autom.targa," ")!=0){
                printf("Il numero telaio e': %s\t",autom.matricola);
                printf("La targa e': %s\t",autom.targa);
                printf("La casa produttrice e': %s\t",autom.prod);
                printf("Il modello e': %s\t",autom.modello);
                printf("Il prezzo e': %.2f\t",autom.prezzo);
                printf("La cilindrata e': %d\n",autom.cilindrata);
            }
            fread(&autom,sizeof(tipoauto),1,fp);
        }
    }
    fclose(fp);
}

void immatricola(){
    FILE*fp;
    tipoauto autom;
    int l;
    bool trovo=false;
    fp=fopen("auto.dat","rb+");
    if (fp==NULL)
        printf("Non esiste il file!\n");
    else{
        fread(&autom,sizeof(tipoauto),1,fp);
        while(!feof(fp)){
            if(strcmp(tel,autom.matricola)==0){
                trovo=true;
                if(strcmp(autom.targa," ")==0){
                    printf("Auto da immatricolare:\n");
                    printf("Numero telaio: %s\t",autom.matricola);
                    printf("Casa produttrice: %s\t",autom.prod);
                    printf("Modello: %s\t",autom.modello);
                    printf("Cilindrata: %d\t",autom.cilindrata);
                    printf("Prezzo: %.2f euro\n",autom.prezzo);
                    printf("\n\nInserisci la targa per l'immatricolazione: ");
                    do{
                        fflush(stdin);
                        scanf("%s",&autom.targa);
                        l=strlen(autom.targa);
                        if(l!=7)
                            printf("\nInserisci una targa composta da 7 caratteri: ");
                    }while(l!=7);
                    converti(autom.targa);
                    fseek(fp,ftell(fp)-sizeof(tipoauto),SEEK_SET);
                    fwrite(&autom,sizeof(tipoauto),1,fp);
                }
                else
                    printf("\nL'auto e' gia' immatricolata");
                break;
            }
            fread(&autom,sizeof(tipoauto),1,fp);
        }
        if(!trovo)
            printf("\nNon ci sono auto con il numero di telaio inserito\n");
        fclose(fp);
    }
}

bool copia(){
    tipoauto autom;
    FILE *fp,*fi;
    bool trovo=false;
    fp=fopen("auto.dat","rb");
    fi=fopen("usato.dat","wb");;
    if(fp==NULL)
        printf("Non esiste il file!\n");
    else{
        fread(&autom,sizeof(tipoauto),1,fp);
        while(!feof(fp)){
            if(strcmp(autom.targa," ")!=0){
                fwrite(&autom,sizeof(tipoauto),1,fi);
                trovo=true;
            }
            fread(&autom,sizeof(tipoauto),1,fp);
        }
        if(!trovo)
            printf("\nNon ci sono auto immatricolate\n");
    }
    fclose(fi);
    fclose(fp);
    return trovo;
}

void visualizzaimm(){
    int i=0;
    FILE*fi;
    tipoauto autom;
    fi=fopen("usato.dat","rb");
    if(fi==NULL)
        printf("\nNon esiste il file\n");
    else{
        fread(&autom,sizeof(tipoauto),1,fi);
        while(!feof(fi)){
            printf("Auto immatricolata n%d\n",i+1);
            printf("Numero telaio: %s\t",autom.matricola);
            printf("Casa produttrice: %s\t",autom.prod);
            printf("Modello: %s\t",autom.modello);
            printf("Cilindrata: %d",autom.cilindrata);
            printf("Prezzo: %.2f euro\t", autom.prezzo);
            printf("Targa: %s\n",autom.targa);
            fread(&autom,sizeof(tipoauto),1,fi);
            i++;
        }
        fclose(fi);
    }
}
