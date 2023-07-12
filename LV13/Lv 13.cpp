/*Korisnik treba unijeti cjelobrojnu vrijednost u rasponu od 1 do 7, pri èemu 1 predstavlja ponedjeljak, a 7 nedjelju. 
Ispisati poruku „Vikeeeend!“ ako je unesen broj koji oznaèava neradne dane ili poruku „Radis jos %d dana do vikenda.“ 
ako je unesen broj koji oznaèava radne dane. Za dane u tjednu koristiti enumeraciju.*/


//treba koristiti enum,a ne brojeve
#include<stdio.h>
#include<stdlib.h>

enum daniTj{ pon = 1, uto, sri, cet, pet, sub, ned};


int main(){
	
	int dan;
	do{
		printf("Unesite br. od 1(ponedjeljak) do 7(nedjelja):\n");
		scanf("%d", &dan);
	}while(dan<1 || dan>7);
	
	if(dan==6 || dan==7){
		printf("Vikeeeend!");
	}
	else{
		printf("Radis jos %d dana do vikenda.", 7-(dan+1));	
	}
		
	return 0;
}



/*Implementirati makro koji raèuna indeks s u binarnom pretraživanju (s = (dg+gg)/2). U glavnoj funkciji uèitati 500 brojeva
 iz datoteke in.txt te s tipkovnice tražiti unos broja koji tražimo u danom polju u intervalu [1, 1000]. Ispisati poruku „Broj nije nadjen.“ 
 ili „Broj je nadjen.“ s obzirom na rezultat pretraživanja.*/
 
#include<stdio.h>
#include<stdlib.h>

#define s(dg, gg) ((dg+gg)/2)

void swap( int *a, int *b){
	
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSortiraj(int polje[], int n){

	int i,j;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1-i; j++){
			if (polje[j+1] < polje[j])
				swap(&polje[j], &polje[j+1]);
		}
	}	
}

void binarnoPretrazi(int n, int polje[], int trazen){
	
	int dg=0, sredisnji;
	int gg= n-1;
	
	while(dg<=gg){
		sredisnji= s(dg, gg);
		
		if(polje[sredisnji]==trazen){
			printf("Broj je nadjen.");
			break;
		}
		else if(polje[sredisnji]> trazen){
			gg= sredisnji -1;
		}
		else if(polje[sredisnji]< trazen){
			dg= sredisnji +1;
		}	
	}	
	if (dg>gg) printf ("\nBroj nije nadjen!");
}

int main(){
	
	FILE* docJ= fopen("in.txt", "r");
	if(docJ==NULL){
		perror("otvaranje datoteke");
		return -1;
	}
	
	int i, polje[20];
	
	for(i=0; i<20; i++){
		fscanf(docJ, "%d", &polje[i]);
	}
	
	fclose(docJ);
	
	int brojPretrazi;
	do{
		printf("Unesite broj koji zelite pretraziti:\n");
		scanf("%d", &brojPretrazi);
	}while(brojPretrazi<=0 || brojPretrazi>1000);
	
	bubbleSortiraj(polje, 20);
	
	printf("REZULTATI:\n");
	binarnoPretrazi(20, polje, brojPretrazi);
	
	return 0;
}

