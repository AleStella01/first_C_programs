// Alunno: Stella Alessandro    Classe: 3B

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int scelta ;
double lato ;
double perimetro ;
double area ;
double triangolo ;
double altezza ;
double catetomag ;
double catetomin ;
double ipotenusa ;
double raggio ;
double diametro;
double latomag ;
int main()

{
    system ("TITLE COLORI");
    system ("CLS");
    system ("COLOR Ce");
    do {
    printf ("Tra le seguenti figure geometriche: \n");
    printf ("1.Quadrato \n");
    printf ("2.Triangolo equilatero \n");
    printf ("3.Crerchio \n");
    printf ("4.Rettangolo \n");
    printf ("5.Triangolo rettangolo \n");
    printf ("Quale scegli?");
    scanf ("%d", &scelta);
    if (scelta==1) {
            printf ("Inserisci qui il lato: ");
            scanf ("%lf", &lato);
            perimetro = lato*4;
            area = lato*lato;
            printf ("Il perimetro e': %lf \n L'area e': %lf", perimetro, area);
            printf ("\n Grazie e alla prossima");
            } else {
                if (scelta==2) {
                        printf ("Inserisci qui il lato: ");
                        scanf ("%lf",&lato);
                        printf ("Inserisci qui l'altezza: ");
                        scanf ("%lf", &altezza);
                        perimetro=lato*3 ;
                        area=(lato*altezza)/2 ;
                        printf ("Il perimetro e': %lf \n L'area e': %lf", perimetro, area);
                        printf ("\n Grazie e alla prossima");
                         } else {
                             if (scelta==3) {
                                    printf ("Inserisci qui il raggio: ");
                                    scanf ("%lf", &raggio);
                                    diametro= raggio*2;
                                    perimetro= 2*(3.14)*raggio;
                                    area= (3.14)*raggio*raggio;
                                    printf ("Il diametro e': %lf \n La circonferenza e': %lf \n L'area e': %lf", diametro, perimetro, area);
                                    printf ("\n Grazie e alla prossima");
                                    } else {
                                        if (scelta==4) {
                                                printf ("Inserisci qui il lato minore: ");
                                                scanf ("%lf", &lato);
                                                printf ("Inserisci qui il lato maggiore: ");
                                                scanf ("%lf", &latomag);
                                                perimetro= (lato*2)+(latomag*2);
                                                area= lato*latomag;
                                                printf ("Il perimetro e': %lf \n L'area e': %lf", perimetro, area);
                                                printf ("\n Grazie e alla prossima");
                                                } else {
                                                    if (scelta == 5) {
                                                    printf ("Inserisci qui il cateto maggiore: ");
                                                    scanf ("%lf", &catetomag);
                                                    printf ("Inserisci qui il cateto minore: ");
                                                    scanf ("%lf", &catetomin);
                                                    ipotenusa=sqrt(catetomag*catetomag)+(catetomin*catetomin);
                                                    perimetro= catetomag+catetomin+ipotenusa;
                                                    area= (catetomag*catetomin)/2;
                                                    printf ("L'ipotenusa e': %lf \n Il perimetro e': %lf \n L'area e': %lf", ipotenusa, perimetro, area);
                                                    printf ("\n Grazie e alla prossima");
                                                    } else {
                                                        if (scelta>=6);
                                                        printf ("ERRORE");
                                                        }
                                                    }
                                                    }
                                                    }
                                                    }
                                                    } while (scelta >=6, scelta<=0);









    return 0;
}
