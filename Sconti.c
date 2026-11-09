int main () {

int c=0;
int n;
float totale=0;
float percentuale;
float sconto;
float costo;
float prezzo;
float differenza;
char sc;

do {
    system ("CLS");
    printf ("Quanta merce è stata acquistata?");
    scanf ("%d",&n);
    do {
	system ("CLS");
        c=c+1;
 	printf ("Inserisci l'importo della %d * merce: ",c);
	scanf ("%f",&costo);
	totale=totale+costo;
    } while (c<n);
    if (totale<500) 
	percentuale=0.1;
    else 
	percentuale=0.2;
    system ("CLS");
    sconto=totale*percentuale;
    differenza=totale-sconto;
    printf ("Il prezzo scontato è:%f \n",sconto);
    printf ("Il prezzo non pagato è:%f \n",differenza);
    system ("PAUSE");
    printf ("Vuoi effettuare altre transizioni? (S/N)");
    fflush (stdin);
    scanf ("%c",&sc); 
} while (sc=='S' || sc=='s');
    
return 0;
}