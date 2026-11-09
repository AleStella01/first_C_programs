//Alunno: Stella Alessandro     Classe: 3B      Data: 14/12/2017
// Terna Pitagorica

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,n3,a,b,c,d;
    char sc;

    do{
        system ("cls");
        system ("color 8c");
        printf ("Questo programma ti permette di sapere se i tre numeri formano una TERNA PITAGORICA\n");
        printf ("Inserisci qui il primo numero: ");
        scanf ("%d",&n1);
        printf ("Inserisci qui il secondo numero: ");
        scanf ("%d",&n2);;
        printf ("Inserisci qui il terzo numero: ");
        scanf ("%d",&n3);
        if (n2>n3){
            d=n2;
            n2=n3;
            n3=d;
        }
        if (n1>n2){
            d=n1;
            n1=n2;
            n2=d;
        }
        if (n1>n3) {
            d=n1;
            n1=n3;
            n3=d;
        }
        a=n1*n1;
        b=n2*n2;
        c=n3*n3;
        if (a+b==c){
            printf ("%d + %d = %d",a,b,c);
            printf ("\nI numeri costituiscono una Terna Pitagorica\n");
        }
        else {
            printf ("%d + %d != %d",a,b,c);
            printf ("\nI numeri non costituiscono una Terna Pitagorica\n");
        }
        printf ("\n\nVuoi uscire? (S/N)");
        fflush (stdin);
        scanf ("%c",&sc);
    } while (sc=='N' || sc=='n');
    printf ("\n\n\n\n>>>>>> Grazie e alla prossima <<<<<<\n\n\n\n");
    return 0;
}
