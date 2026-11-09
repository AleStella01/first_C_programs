int main () {

int c=0;
int n;
float prezzo;
float somma=0;
float differenza;
float sconto;

printf ("Quanta merce e' stata acquistata?");
scanf ("%d",&n);
do {
    system ("CLS");
    c++;
    printf ("Inserisci il prezzo della merce: ");
    scanf ("%f",&prezzo);
    somma+=prezzo;
} while (c<n);
if (somma<=50)
	sconto=somma*0.05;
else {
	if (somma>50 && somma<=65)
		sconto=somma*0.06;
	else {
		if (somma>65 && somma<=80)
			sconto=somma*0.07;
		else {
			if (somma>=100)
				sconto=somma*0.1;
		}
	}
}
differenza=somma-sconto;
printf ("\nIl prezzo netto e': %.2f",somma);
printf ("\nIl prezzo scontato e': %.2f",differenza);
printf ("\nIl prezzo da non pagare e': %.2f \n",sconto);
system ("PAUSE");

return 0;
}