//Alunno: Stella Alessandro     Classe: 3B      Data: 08/11/2017
// mcm

#include <stdio.h>
#include <stdlib.h>

//prototipi di funzione
int mcm();

int main()
{
    int a,b,c;

    do {
        printf ("\n\nInserisci qui il primo numero: ");
        scanf ("%d",&a);
        if (a==0)
            system ("cls");
    } while(a==0);
    do {
        system ("cls");
        printf ("\n\nInserisci qui il secondo numero: ");
        scanf ("%d",&b);
        if (b==0)
            system ("cls");
    }while (b==0);
    c=mcm(a,b);
    system ("cls");
    printf ("Il mcm tra %d e %d e': %d",a,b,c);
    return 0;
}

int mcm (int a, int b){
    int sa=a;
    int sb=b;

    if (sa==sb)
        return sa;
    else
        if (sa%sb==0)
            return sa;
        else
            if (sb%sa==0)
                return sb;
            else {
                do {
                    if (sa<sb)
                        sa+=a;
                    else
                        sb+=b;
                } while (sa!=sb);
                return sa;
            }
}
