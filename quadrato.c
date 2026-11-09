// Alunno: Stella Alessandro      Classe: 3B
#include <stdio.h>
#include <stdlib.h>

double Lato;
double Perimetro;
double Area;

int main()

{
    printf ("Questo programma ti permette di calcolare perimetro ed area di un quadrato");
    printf(" \n Inserisci qui il lato", Lato);
    scanf ("%lf",&Lato);
    Perimetro= Lato*4;
    Area= Lato*Lato;
    printf ("Perimetro = %lf /n Area = %lf", Perimetro, Area);
    return 0;
}
