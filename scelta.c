// Alunno: Stella Alessandro        Classe: 3B

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()

{
   int scelta ;
double lato ;
double perimetro ;
double area ;
double altezza ;
double raggio ;
double diametro ;
double latomin ;
double catetomag ;
double catetomin ;
double ipotenusa ;

        do {
            system ("COLOR De");
            printf ("Scegli una tra le seguenti figure: \n");
            printf ("1. Quadrato \n");
            printf ("2. Triangolo Equilatero \n");
            printf ("3. Triangolo Rettangolo \n");
            printf ("4. Cerchio \n");
            printf ("5. Rettangolo \n");
            printf ("0. ESCI \n");
            do{
            printf ("Quale scegli?");
            scanf ("%d", &scelta);
            }while(scelta<0 || scelta>5);
            switch (scelta){
                case 1:
                    do {
                        system ("COLOR 2e");
                        printf ("Inserisci qui il lato: ");
                        scanf ("%lf", &lato);
                        if (lato<=0)
                            printf("ERRORE");
                    } while (lato<=0);
                    perimetro=lato*4;
                    area=lato*lato;
                    printf ("Il perimetro e': %.2lf \n", perimetro);
                    printf ("L'area e': %.2lf", area);
                    break;
                case 2:
                    do {
                        system ("COLOR 5f");
                        printf ("Inserisci qui il lato: ");
                        scanf ("%lf", &lato);
                        if (lato<=0)
                            printf ("ERRORE");
                    } while (lato<=0);
                    do {
                        printf ("Inserisci qui l'altezza: ");
                        scanf ("%lf", &altezza);
                        if (altezza<=0)
                            printf ("ERRORE \n");
                    } while (altezza<=0);
                    perimetro=lato*3;
                    area= (lato*altezza)/2;
                    printf ("Il perimetro e': %.2lf \n", perimetro);
                    printf ("L'area e': %.2lf \n",area);
                    break ;
                case 3:
                    do {
                        system ("COLOR A9");
                        printf ("Inserisci qui il cateto maggiore: ");
                        scanf ("%lf", &catetomag);
                        if (catetomag<=0)
                            printf ("ERRORE");
                    } while (catetomag<=0);
                    do {
                        printf ("Inserisci qui il cateto minore: ");
                        scanf ("%lf", &catetomin);
                        if (catetomin<=0)
                            printf ("ERRORE");
                    } while (catetomin<=0);
                    ipotenusa=sqrt(catetomag*catetomag)+(catetomin*catetomin);
                    perimetro=catetomag+catetomin+ipotenusa;
                    area=(catetomag*catetomin)/2;
                    printf ("L'ipotenusa e': %.2lf \n", ipotenusa);
                    printf ("Il perimetro e': %.2lf \n", perimetro);
                    printf ("L'area e': %.2lf \n", area);
                    break;
                case 4:
                    do {
                        system ("COLOR 80");
                        printf ("Inserisci qui il raggio: ");
                        scanf ("%lf", &perimetro);
                        if (raggio<=0)
                            printf ("ERRORE");
                    } while (raggio<=0);
                    diametro= raggio*2;
                    perimetro= 6.28*raggio;
                    area= 3.14*raggio*raggio;
                    printf ("Il diametro e': %.2lf \n", diametro);
                    printf ("La circonferenza e': %.2lf \n", perimetro);
                    printf ("L'area e': %.2lf \n", area);
                    break;
                case 5:
                    do {
                        system ("COLOR 5A");
                        printf ("Inserisci qui il lato maggiore: ");
                        scanf ("%lf", &lato);
                        if (lato<=0)
                            printf ("ERRORE");
                    } while (lato<=0);
                    do {
                        printf ("Inserisci qui il lato minore: ");
                        scanf ("%lf", &catetomin);
                        if (lato<=0)
                            printf ("ERRORE");
                    } while (lato<=0);
                    perimetro=lato*2+catetomin*2;
                    area= catetomin*lato;
                    printf ("Il perimetro e': %lf \n", perimetro);
                    printf ("L'area e': %lf \n");
                    break;
                }
            } while (scelta>0);
            printf ("Grazie e alla prossima");








    return 0;
}
