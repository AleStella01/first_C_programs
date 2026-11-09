// Alunno: Stella Alessandro        Classe: 3B

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sc;
    int scelta;
    char risp;
    char sce;
    char rispo;
    float paghetta;
    float risparmio;
    float rispa;
    float differenza;
    float somma;
    float resto=differenza;
    float cinema=15.25;
    float ristorante=35.69;
    float sport=20.00;
    float vestiti=75.60;
    float sushi=35.99;

    do {
        printf ("Inserisci qui la paghetta: ");
        scanf ("%f",&paghetta);
        system ("CLS");
        printf ("Vuoi mettere soldi da parte?(S/N) ");
        fflush (stdin);
        scanf ("%c",&risp);
        if (risp=='S' || risp=='s'){
            do {
            printf ("Quanti soldi vuoi risparmiare? ");
            scanf ("%f",&risparmio);
            if (risparmio>paghetta)
                printf ("ERRORE");
            }while (paghetta<risparmio);
        } else {
            differenza=paghetta;
        }
        system ("CLS");
        printf ("Hai qualche risparimio precedente? (S/N) ");
        fflush (stdin);
        scanf ("%c",&rispo);
        if (rispo=='S' || rispo=='s'){
            printf ("Quanti soldi hai risparmiato? ");
            scanf ("%f",&rispa);
            somma=differenza+rispa;
        } else {
            somma=differenza;
        }
        resto=somma;
        do {
            system ("CLS");
            printf ("Scegli qui cosa fare:\n");
            printf ("1. Cinema: EURO %.2f \n",cinema);
            printf ("2. Ristorante: EURO %.2f \n",ristorante);
            printf ("3. Sport: EURO %.2f \n",sport);
            printf ("4. Vestiti: EURO %.2f \n",vestiti);
            printf ("5. Sushi: EURO %.2f \n",sushi);
            printf ("\nQuale scegli?");
            scanf ("%d",&scelta);
            switch (scelta) {
                case 1:
                        system ("CLS");
                        system ("COLOR 3b");
                        if (resto>=cinema) {
                            resto=differenza-cinema;
                            printf ("Acquisto confermato. Soldi rimasti: %.2f \n",resto);
                        } else {
                            printf ("ERRORE: NON HAI ABBASTANZA SOLDI\n");
                        }
                        system ("PAUSE");
                        break;
                case 2:
                        system ("CLS");
                        system ("COLOR 2a");
                        if (resto>=cinema) {
                            resto=differenza-cinema;
                            printf ("Acquisto confermato. Soldi rimasti: %.2f \n",resto);
                        } else {
                            printf ("ERRORE: NON HAI ABBASTANZA SOLDI\n");
                        }
                        system ("PAUSE");
                        break;
                case 3:
                        system ("CLS");
                        system ("COLOR 4a");
                        if (resto>=sport) {
                            resto=differenza-sport;
                            printf ("Acquisto confermato. Soldi rimasti: %.2f \n",resto);
                        } else {
                            printf ("ERRORE: NON HAI ABBASTANZA SOLDI\n");
                        }
                        system ("PAUSE");
                        break;
                case 4:
                        system ("CLS");
                        system ("COLOR 35");
                        if (resto>=vestiti) {
                            resto=differenza-vestiti;
                            printf ("Acquisto confermato. Soldi rimasti: %.2f \n",resto);
                        } else {
                            printf ("ERRORE: NON HAI ABBASTANZA SOLDI\n");
                        }
                        system ("PAUSE");
                        break;
                case 5:
                        system ("CLS");
                        system ("COLOR f0");
                        if (resto>=sushi) {
                            resto=differenza-sushi;
                            printf ("Acquisto confermato. Soldi rimasti: %.2f \n",resto);
                        } else {
                            printf ("ERRORE: NON HAI ABBASTANZA SOLDI\n");
                        }
                        system ("PAUSE");
                        break;

            }
            system ("COLOR 0f");
            system ("CLS");
            printf ("Vuoi effettuare altri acquisti? (S/N) ");
            fflush (stdin);
            scanf ("%c",&sc);
        }while (sc=='S' || sc=='s');
        system ("CLS");
        printf ("Vuoi cambiare importo? (S/N)");
        fflush (stdin);
        scanf ("%c",&sce);
    }while (sce=='S' || sce=='s');

    return 0;
}
