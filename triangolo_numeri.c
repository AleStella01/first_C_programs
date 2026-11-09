//Alunno: Stella Alessandro     Classe: 3B      Data: 11/12/2017
//Triangolo Numeri
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c=0, s=0, n;
    char sc;

    do {
        system ("color 2e");
        printf ("Questo programma crea un trinagolo con i numeri fino a quello da te inserito\n\n\n\n");
        printf ("ATTENZIONE: IL TRIANGOLO RIESCE FINO AL NUMERO 78\n\n");
        printf("Inserisci qui un numero:\n");
        scanf ("%d",&n);
        system ("cls");
        printf ("\n");
        if (n>0){
            while (s<n){
                s++;
                do {
                    c++;
                    printf ("%d",s);
                }while(c<s);
                c=0;
                printf ("\n");
            }
        }
        else
            if (n<0){
                while (s>n){
                s--;
                    do {
                        c--;
                        printf ("%d",s);
                    }while(c>s);
                c=0;
                printf ("\n");
            }
            }
        else
            printf ("0 \n");
        printf ("Vuoi riprovare? (S/N)");
        fflush (stdin);
        scanf ("%c",&sc);
        system ("cls");
    } while (sc!= 'N' && sc!='n');
    return 0;
}
