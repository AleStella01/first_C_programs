//Alunno: Stella Alessandro     Classe:3B       Data:22/11/2017
//Equazioni di secondo grado

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prototipi
int MCD (int,int);
void carica(int*,int*,int*);
void primo (int,int,int);
void pura (int,int,int);
void spuria (int,int,int);
void monomia (int,int);
void equazione (int,int,int,int);


int main()
{
    int a,b,c,s;
    char sc;

    system ("color 9f");
    do {
        system ("cls");
        do{
            do{
               carica (&a,&b,&c);
               if (a==0 && b==0 && c==0)
                    system ("cls");
                if (a==0 && b==0){
                    system ("cls");
                    printf ("Non e' un equazione\n");
                }
            }while (a==0 && b==0);
        } while (a==0 && b==0 && c==0);
        printf ("Tra i seguenti segni:\n");
        printf ("1. =\n");
        printf ("2. <\n");
        printf ("3. >\n");
        printf ("4. <=\n");
        printf ("5. >=\n");
        do{
            printf ("\n\nQuale scegli?");
            scanf ("%d",&s);
        }while (s>5 || s<1);
            if (a==0)
                primo (b,c,s);
            else
                if (b==0)
                    pura (a,c,s);
                else
                    if (c==0)
                        spuria (a,b,s);
                    else
                        if (b==0 && c==0)
                            monomia(a,s);
                        else
                            equazione(a,b,c,s);
    printf ("\nVuoi continuare?(S/N)");
    fflush (stdin);
    scanf ("%c",&sc);
    } while (sc=='S' || sc=='s');
    printf ("\n\n\n======>Grazie e alla prossima<======");
    return 0;
}

int MCD (int a,int b){

    int x;
        a=abs(a);
        b=abs(b);

        do {
        if (a>b)
            a=a-b;
        else
            if (b>a)
                b=b-a;
    }while (a!=b);
    x=a;
    return x;
}
void carica(int*a,int*b,int*c){

    printf ("Inserisci qui il valore di a: ");
    scanf ("%d",a);
    printf ("Inserisci qui il valore di b: ");
    scanf ("%d",b);
    printf ("Inserisci qui il valore di c: ");
    scanf ("%d",c);

}


void primo (int b,int c,int s){

    int d,e=0;
    float x;

    d=MCD(b,c);
    b=b/d;
    c=c/d;
    x=-c/b;
    switch (s){
        case 1:
            printf ("Tipo: Equazione\n");
            printf ("Grado equazione: Primo\n");
            printf ("Forma normale: %d x + %d =0\n",b,c);
            printf ("X= %.2f",x);
            break;
        case 2:
            printf ("Tipo: Disequazione\n");
            printf ("Grado equazione: Primo\n");
            if (e==0){
                printf ("Forma normale: %d x + %d < 0\n",b,c);
                printf ("X < %.2f\n",x);
            }
            else{
               printf ("Forma normale: %d x + %d > 0\n",b,c);
               printf ("X > %.2f\n",x);
            }
            break;
        case 3:
            printf ("Tipo: Disequazione\n");
            printf ("Grado equazione: Primo\n");
            if (e==1){
                printf ("Forma normale: %d x + %d < 0\n",b,c);
                printf ("X < %.2f\n",x);
            }
            else{
               printf ("Forma normale: %d x + %d > 0\n",b,c);
               printf ("X > %.2f\n",x);
            }
            break;
        case 4:
            printf ("Tipo: Disequazione\n");
            printf ("Grado equazione: Primo\n");
            if (e==0){
                printf ("Forma normale: %d x + %d <= 0\n",b,c);
                printf ("X <= %.2f\n",x);
            }
            else{
               printf ("Forma normale: %d x + %d >= 0\n",b,c);
               printf ("X >= %.2f\n",x);
            }
            break;
        case 5:
            printf ("Tipo: Disequazione\n");
            printf ("Grado equazione: Primo\n");
            if (e==1){
                printf ("Forma normale: %d x + %d <= 0\n",b,c);
                printf ("X < %.2f\n",x);
            }
            else{
               printf ("Forma normale: %d x + %d >= 0\n",b,c);
               printf ("X > %.2f\n",x);
            }
    }
}

void pura (int a,int c,int s){

    float x1,x2;
    int d,p;

    if (c<0){
        d=MCD(a,c);
        a=a/d;
        c=c/d;
        x1=-sqrt(-c/a);
        x2=sqrt(-c/a);
        if (x2<x1){
            p=x1;
            x1=x2;
            x2=p;
        }
        switch (s){
            case 1:
                printf ("Tipo: Equazione\n");
                printf ("Grado equazione: Secondo\n");
                printf ("Tipo equazione: Pura\n");
                printf ("Forma normale: %d X^2 + %d =0",a,c);
                printf ("\nDelta: %d",d);
                printf ("\nX1=%.2f || X2=%.2f",x1,x2);
                break;
            case 2:
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo\n");
                printf ("Tipo equazione: Pura\n");
                printf ("Delta: %d\n",d);
                if (a<0){
                    printf ("Forma normale: %d X^2 + %d > 0\n",a,c);
                    if (d>0)
                        printf ("X < %.2f V X > %.2f",x1,x2);
                    else
                        if (d==0)
                            printf ("VX != %.2f",x1);
                        else
                            printf ("VX e R");
                }
                else{
                    printf ("Forma normale: %d X^2 + %d < 0\n",a,c);
                if (d>0)
                    printf ("%.2f < X < %.2f",x1,x2);
                else
                    if (d<=0)
                        printf ("Non esistono X appartenenti ad R");
                }
                break;
            case 3:
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo\n");
                printf ("Tipo equazione: Pura\n");
                printf ("Delta: %d\n",d);
                if (a>0){
                    printf ("Forma normale: %d X^2 + %d > 0\n",a,c);
                    if (d>0)
                        printf ("X < %.2f V X > %.2f",x1,x2);
                    else
                        if (d==0)
                            printf ("VX != %.2f",x1);
                        else
                            printf ("VX e R");
                }
                else
                    printf ("Forma normale: %d X^2 + %d < 0\n",a,c);
                if (d>0)
                    printf ("%.2f < X < %.2f",x1,x2);
                else
                    if (d<=0)
                        printf ("Non esistono X appartenenti ad R");
                break;
            case 4:
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo\n");
                printf ("Tipo equazione: Pura\n");
                printf ("Delta: %d\n",d);
                if (a<0){
                    printf ("Forma normale: %d X^2 + %d >= 0\n",a,c);
                    if (d>0)
                        printf ("X <= %.2f V X >= %.2f",x1,x2);
                    else
                        if (d==0)
                            printf ("VX != %.2f",x1);
                        else
                            printf ("VX e R");
                }
                else{
                    printf ("Forma normale: %d X^2 + %d <= 0\n",a,c);
                if (d>0)
                    printf ("%.2f <= X <= %.2f",x1,x2);
                else
                    if (d<=0)
                        printf ("Non esistono X appartenenti ad R");
                }
                break;
            case 5:
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo\n");
                printf ("Tipo equazione: Pura\n");
                printf ("Delta: %d\n",d);
                if (a>0){
                    printf ("Forma normale: %d X^2 + %d >= 0\n",a,c);
                    if (d>0)
                        printf ("X <= %.2f V X >= %.2f",x1,x2);
                    else
                        if (d==0)
                            printf ("VX != %.2f",x1);
                        else
                            printf ("VX e R");
                }
                else
                    printf ("Forma normale: %d X^2 + %d <= 0\n",a,c);
                if (d>0)
                    printf ("%.2f <= X <= %.2f",x1,x2);
                else
                    if (d<=0)
                        printf ("Non esistono X appartenenti ad R");
                break;
        }
    }
    else
        printf ("Il risultato non e' reale");

}

void spuria(int a,int b,int s){

    int d,p;
    float x1,x2;

    if (b<0){
        d=MCD(a,b);
        a=a/d;
        b=b/d;
        x1=-b/a;
        x2=0;
        if (x2<x1){
            p=x1;
            x1=x2;
            x2=p;
        }
        switch (s){
            case 1:
                printf ("Grado equazione: Secondo \n");
                printf ("Tipo equazione: Spuria \n");
                printf ("Forma normale: %d X^2 + %d X = 0 \n",a,b);
                printf ("Delta: %d\n",d);
                printf ("X1=%.2f || X2=%.2f",x1,x2);
                break;
            case 2:
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo\n");
                printf ("Tipo equazione: Pura\n");
                printf ("Delta: %d\n",d);
                if (a<0){
                    printf ("Forma normale: %d X^2 + %d X > 0\n",a,b);
                    if (d>0)
                        printf ("X < %.2f V X > %.2f",x1,x2);
                    else
                        if (d==0)
                            printf ("VX != %.2f",x1);
                        else
                            printf ("VX e R");
                }
                else{
                    printf ("Forma normale: %d X^2 + %d X < 0\n",a,b);
                if (d>0)
                    printf ("%.2f < X < %.2f",x1,x2);
                else
                    if (d<=0)
                        printf ("Non esistono X appartenenti ad R");
                }
                break;
            case 3:
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo\n");
                printf ("Tipo equazione: Pura\n");
                printf ("Delta: %d\n",d);
                if (a>0){
                    printf ("Forma normale: %d X^2 + %d X > 0\n",a,b);
                    if (d>0)
                        printf ("X < %.2f V X > %.2f",x1,x2);
                    else
                        if (d==0)
                            printf ("VX != %.2f",x1);
                        else
                            printf ("VX e R");
                }
                else
                    printf ("Forma normale: %d X^2 + %d < 0\n",a,b);
                if (d>0)
                    printf ("%.2f < X < %.2f",x1,x2);
                else
                    if (d<=0)
                        printf ("Non esistono X appartenenti ad R");
                break;
            case 4:
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo\n");
                printf ("Tipo equazione: Pura\n");
                printf ("Delta: %d\n",d);
                if (a<0){
                    printf ("Forma normale: %d X^2 + %d >= 0\n",a,b);
                    if (d>0)
                        printf ("X <= %.2f V X >= %.2f",x1,x2);
                    else
                        if (d==0)
                            printf ("VX != %.2f",x1);
                        else
                            printf ("VX e R");
                }
                else{
                    printf ("Forma normale: %d X^2 + %d <= 0\n",a,b);
                if (d>0)
                    printf ("%.2f <= X <= %.2f",x1,x2);
                else
                    if (d<=0)
                        printf ("Non esistono X appartenenti ad R");
                }
                break;
            case 5:
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo\n");
                printf ("Tipo equazione: Pura\n");
                printf ("Delta: %d\n",d);
                if (a>0){
                    printf ("Forma normale: %d X^2 + %d >= 0\n",a,b);
                    if (d>0)
                        printf ("X <= %.2f V X >= %.2f",x1,x2);
                    else
                        if (d==0)
                            printf ("VX != %.2f",x1);
                        else
                            printf ("VX e R");
                }
                else
                    printf ("Forma normale: %d X^2 + %d <= 0\n",a,b);
                if (d>0)
                    printf ("%.2f <= X <= %.2f",x1,x2);
                else
                    if (d<=0)
                        printf ("Non esistono X appartenenti ad R");
                break;
        }
    }
    else
        printf ("Il risultato non e' reale");
}

void monomia (int a,int s){

    switch (s){
        case 1:
            printf ("Tipo:Equazione\n");
            printf ("Grado equazione: Secondo\n");
            printf ("Tipo equazione: Monomia\n");
            printf ("Forma normale: %d X^2 = 0 \n",a);
            printf ("X1 = 0 || X2 = 0");
            break;
        case 2:
            printf ("Tipo:Equazione\n");
            printf ("Grado equazione: Secondo\n");
            printf ("Tipo equazione: Monomia\n");
            printf ("Forma normale: %d X^2 = 0 \n",a);
            printf ("X1 = X2 < 0");
            break;
        case 3:
            printf ("Tipo:Equazione\n");
            printf ("Grado equazione: Secondo\n");
            printf ("Tipo equazione: Monomia\n");
            printf ("Forma normale: %d X^2 = 0 \n",a);
            printf ("X1 = X2 > 0");
            break;
        case 4:
            printf ("Tipo:Equazione\n");
            printf ("Grado equazione: Secondo\n");
            printf ("Tipo equazione: Monomia\n");
            printf ("Forma normale: %d X^2 = 0 \n",a);
            printf ("X1 = X2 <= 0");
            break;
        case 5:
            printf ("Tipo:Equazione\n");
            printf ("Grado equazione: Secondo\n");
            printf ("Tipo equazione: Monomia\n");
            printf ("Forma normale: %d X^2 = 0 \n",a);
            printf ("X1 = X2 >= 0");
            break;
    }
}

void equazione(int a,int b,int c, int s){

    int x,d;
    float x1,x2;

    x=MCD(MCD(a,b),c);
    a=a/x;
    b=b/x;
    c=c/x;
    d=pow(b,2)-(4*a*c);
    if (d==0)
         x2=(-b+sqrt(d))/(2*a);
    else
         if (d>0){
                x1=(-b-sqrt(d))/(2*a);
                x2=(-b+sqrt(d))/(2*a);
         }
    switch (s){
        case 1:
            if (d>0){
                printf ("Grado equazione: Secondo \n");
                printf ("Tipo equazione: Completa \n");
                printf ("Delta: %d\n",d);
                printf ("Forma normale: %d X^2 + %d X + %d = 0",a,b,c);
                printf ("Delta: %d\n",d);
                printf ("\nX1=%.2f || X2=%.2f",x1,x2);
            }
            else
                if (d==0) {
                        printf ("Grado equazione: Secondo \n");
                        printf ("Tipo equazione: Completa \n");
                        printf ("Delta: %d\n",d);
                        printf ("Forma normale: %d X^2 + %d X + %d = 0",a,b,c);
                        printf ("\nX1 = X2 = %.2f",x2);
                }
                else
                    if (d<0)
                        printf ("Non esistono X c R");
            break;
        case 2:
            if (d>0){
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo \n");
                printf ("Tipo equazione: Completa \n");
                printf ("Delta: %d\n",d);
                if (a>0){
                    printf ("Forma normale: %d X^2 + %d X + %d < 0\n",a,b,c);
                    printf ("%.2f < X < %.2f",x1,x2);
                }
                else {
                    printf ("Forma normale: %d X^2 + %d X + %d > 0\n",a,b,c);
                    printf ("\nX < %.2f V X > %.2f",x1,x2);
                }
            }
            else
                if (d==0) {
                        printf ("Tipo: Disequazione\n");
                        printf ("Grado equazione: Secondo \n");
                        printf ("Tipo equazione: Completa \n");
                        printf ("Delta: %d\n",d);
                        if (a>0){
                            printf ("Forma normale: %d X^2 + %d X + %d < 0",a,b,c);
                            printf ("Non esistono X appartenenti ad R");
                        }
                        else {
                            printf ("Forma normale: %d X^2 + %d X + %d > 0\n",a,b,c);
                            printf ("Vx != %.2f",x1);
                        }
                }
                else
                    if (d<0){
                        printf ("Tipo: Disequazione\n");
                        printf ("Grado equazione: Secondo\n");
                        printf ("Tipo equazione: Completa\n");
                        printf ("Delta: %d\n",d);
                        if (a>0){
                            printf ("Forma normale: %d X^2 + %d X + %d < 0\n",a,b,c);
                            printf ("Non esistono X appartenenti ad R");
                        }
                        else {
                            printf ("Forma normale: %d X^2 + %d X + %d > 0\n",a,b,c);
                            printf ("Vx c R");
                        }
                    }
            break;
        case 3:
            if (d>0){
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo \n");
                printf ("Tipo equazione: Completa \n");
                printf ("Delta: %d\n",d);
                if (a>0){
                    printf ("Forma normale: %d X^2 + %d X + %d > 0\n",a,b,c);
                    printf ("\nX < %.2f V X > %.2f",x1,x2);
                }
                else {
                    printf ("Forma normale: %d X^2 + %d X + %d < 0\n",a,b,c);
                    printf ("%.2f < X < %.2f",x1,x2);
                }
            }
            else
                if (d==0) {
                        printf ("Tipo: Disequazione\n");
                        printf ("Grado equazione: Secondo \n");
                        printf ("Tipo equazione: Completa \n");
                        printf ("Delta: %d\n",d);
                        if (a>0){
                            printf ("Forma normale: %d X^2 + %d X + %d > 0 \n",a,b,c);
                            printf ("Vx != %.2f",x1);
                        }
                        else {
                            printf ("Forma normale: %d X^2 + %d X + %d < 0 \n",a,b,c);
                            printf ("Non esistono X appartenenti ad R");
                        }
                }
                else
                    if (d<0){
                        printf ("Tipo: Disequazione\n");
                        printf ("Grado equazione: Secondo\n");
                        printf ("Tipo equazione: Completa\n");
                        printf ("Delta: %d\n",d);
                        if (a>0){
                            printf ("Forma normale: %d X^2 + %d X + %d > 0 \n",a,b,c);
                            printf ("Vx c R");
                        }
                        else {
                            printf ("Forma normale: %d X^2 + %d X + %d > 0 \n",a,b,c);
                            printf ("Non esistono X appartenenti ad R");
                        }
                    }
            break;
        case 4:
            if (d>0){
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo \n");
                printf ("Tipo equazione: Completa \n");
                printf ("Delta: %d\n",d);
                if (a>0){
                    printf ("Forma normale: %d X^2 + %d X + %d <= 0\n",a,b,c);
                    printf ("%.2f <= X <= %.2f",x1,x2);
                }
                else {
                    printf ("Forma normale: %d X^2 + %d X + %d >= 0 \n",a,b,c);
                    printf ("X <= %.2f V X >= %.2f",x1,x2);
                }
            }
            else
                if (d==0) {
                        printf ("Tipo: Disequazione \n");
                        printf ("Grado equazione: Secondo \n");
                        printf ("Tipo equazione: Completa \n");
                        printf ("Delta: %d\n",d);
                        if (a>0){
                            printf ("Forma normale: %d X^2 + %d X + %d <= 0\n",a,b,c);
                            printf ("Non esistono X appartenenti ad R");
                        }
                        else {
                            printf ("Forma normale: %d X^2 + %d X + %d >= 0\n",a,b,c);
                            printf ("Vx != %.2f",x1);
                        }
                }
                else
                    if (d<0){
                        printf ("Tipo: Disequazione\n");
                        printf ("Grado equazione: Secondo \n");
                        printf ("Tipo equazione: Completa \n");
                        printf ("Delta: %d\n",d);
                        if (a>0){
                            printf ("Forma normale: %d X^2 + %d X + %d <= 0\n",a,b,c);
                            printf ("Non esistono X appartenenti ad R");
                        }
                        else {
                            printf ("Forma normale: %d X^2 + %d X + %d >= 0\n",a,b,c);
                            printf ("Vx c R");
                        }
                    }
            break;
        case 5:
            if (d>0){
                printf ("Tipo: Disequazione\n");
                printf ("Grado equazione: Secondo \n");
                printf ("Tipo equazione: Completa \n");
                printf ("Delta: %d\n",d);
                if (a>0){
                    printf ("Forma normale: %d X^2 + %d X + %d >= 0\n",a,b,c);
                    printf ("X <= %.2f V X >= %.2f",x1,x2);
                }
                else {
                    printf ("Forma normale: %d X^2 + %d X + %d <= 0\n",a,b,c);
                    printf ("%.2f < X < %.2f",x1,x2);
                }
            }
            else
                if (d==0) {
                    printf ("Tipo: Disequazione\n");
                    printf ("Grado equazione: Secondo \n");
                    printf ("Tipo equazione: Completa \n");
                    printf ("Delta: %d\n",d);
                    if (a>0){
                        printf ("Forma normale: %d X^2 + %d X + %d >= 0\n",a,b,c);
                        printf ("Vx != %.2f",x1);
                    }
                    else {
                        printf ("Forma normale: %d X^2 + %d X + %d <= 0\n",a,b,c);
                        printf ("Non esistono X appartenenti ad R");
                    }
                }
                else
                    if (d<0){
                        printf ("Tipo: Disequazione\n");
                        printf ("Grado equazione: Secondo \n");
                        printf ("Tipo equazione: Completa \n");
                        printf ("Delta: %d\n",d);
                        if (a>0){
                            printf ("Forma normale: %d X^2 + %d X + %d >= 0\n",a,b,c);
                            printf ("Vx c R");
                        }
                        else {
                            printf ("Forma normale: %d X^2 + %d X + %d <= 0\n",a,b,c);
                            printf ("Non esistono X appartenenti ad R");
                        }
                    }
            break;

    }
}
