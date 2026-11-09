//Alunno: Stella Alessandro         Classe:3B       Data: 06/11/2017
// Quandrato di n

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c=0,
        g=0,
        somma=0,
        n,a;


        printf ("Inserisci il numero:");
        scanf ("%d",&n);
        if (n<0){
            a=n;
            n=n*(-1);
        }
        if (n!=0){
            do {
                c++;
                if (c%2!=0) {
                    g++;
                    somma+=c;
                }
            }while (g<n);
        }
        else
            a=0;
        system ("cls");
        printf ("Il quadrato di %d e': %d",a,somma);
    return 0;
}
