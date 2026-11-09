int main () {

int c=0;
int num;
int min;

do{
   do {
    	printf ("Inserisci il numero strettamente maggiore di 0");
   	scanf ("%d",&num);
    } while (num<0); //controllo di accettabilità perché il valore deve essere sempre>0 (0 accettato ma non esaminato)
    if (num!=0) {	
	if (c==0) {
   		min=num;
		c=1;
    	} 
    	else {
		if (num<min)
			min=num;
    	}
    }
} while (num!=0); //controllo per terminare la sequenza
if (c!=0) //E' possibile che non ci siano valori accettabili
    printf ("Il numero minore e': %d",min);
else 
    printf ("Errore: Non sono presenti numeri");
return 0;
}
