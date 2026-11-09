// Alunno: Stella Alessandro        Classe: 3b

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c=0;
    int n=0;
    int p=0;
    int no;
    int eta;
    int max;

    system ("COLOR 3b");
    printf ("Quante eta' devi inserire?");
    scanf ("%d",&no);
    do {
            c++;
        do {
            system ("CLS");
            printf ("Inserisci qui l'eta': ");
            scanf ("%d",&eta);
        } while (eta<0);    //Controllo di accettabilità
        if (eta>=0){
            if (n==0){
                n=1;
                max=eta;
            }
            else {
                if (eta>max) {
                    max=eta;
                    p=1;
                }
                else {
                    if (eta==max)
                        p++;
                }

            }
        }
    }while (c<no);
    system ("CLS");
    if (n!=0) {
        printf ("L'eta' maggiore e': %d",eta);
        printf ("\nIl numero di persone che la hanno e':%d",p);
    }
    else
        printf ("Errore: Non ci sono eta' accettabili");
    return 0;
}
