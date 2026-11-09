//Alunno: Stella Alessandro     Classe: 3B      Data: 30/05/2018
//Gestione Musica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char marca[21];
    char tipo[10];
    char strumento[16];
    char autore[25];
    char cod[14];
    int giacenza;
    float prezzo;
}tipomus;

int main()
{
    printf("Hello world!\n");
    return 0;
}

int menu(){
    int s;

    printf("\t\t\tMENU'\n\n");
    printf("1. Registrare i prodotti e copiarli nei vari file\n");
    printf("2. Visualizzare i vari prodotti registrati\n");
    printf("3. Inserire una tipologia per visualizzarne il prezzo medio\n");
    printf("4. Visualizzare tutti i prodotti con giacenza=0\n");
    printf("5. Inserire una casa produttrice per visualizzare i vari prodotti\n");
    printf("6. Inserire uno strumento/autore per visualizzarne i prodotti\n");
    printf("7. Modificare la giacenza di alcuni prodotti\n");
    printf("8. Inserire il codice per visualizzare il prodotto\n");
    printf("0.   ")
}
