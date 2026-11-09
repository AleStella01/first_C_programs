int main (){

int c;
int n;
int cifra;
int x;
int dec=0;

printf ("Inserisci qui il numero di cifre: ");
scanf ("%d",&n);
c=n-1;
do {
    do {
	system ("CLS");
   	printf ("Cifra: ");
   	scanf ("%d",&cifra);
	if (cifra!=1 && cifra!=0)
		printf ("ERRORE: LE CIFRE DEVONO ESSERE 1/0");
    } while (cifra!=1 && cifra!=0);
    if (cifra!=0); {
	x=cifra*pow(2,c);
    	dec=dec+x
    }
    c--;
} while (c>=0);
system ("CLS");
printf ("Il valore decimale è:%d",dec);

return 0;
}