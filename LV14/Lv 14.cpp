/*1. Napisati C program u kojem je potrebno deklarirati strukturu automobil koja sadržava marku, model, broj konja,
  maksimalnu brzinu i cijenu. Kreirati funkciju unos() koja prima pokazivaè na polje automobila te broj elemenata u
  tom polju. Funkcija treba unijeti podatke za traženi broj automobila. Funkcija ne vraæa ništa. Napisati i funkciju
  ispis() koja takoðer prima pokazivaè na polje automobila te broj elemenata u tom polju. Funkcija treba ispisati
  podatke o svim automobilima u polju. U glavnom dijelu programa, tražiti od korisnika broj automobila koji želi
  unijeti te nakon toga unijeti sve podatke i ispisati ih. Kod organizirati u više datoteka te saèuvati sve datoteke
  koje nastaju u svim fazama prevoðenja. Saèuvati i sve naredbe koje su bile potrebne za prevoðenje programskog koda.*/
  
  #include<stdio.h>
  #include<stdlib.h>
  
  typedef struct car{
  	
  	char *marka;
  	char *model;
  	int brKonja;
  	int speed;
  	int price;
  }AUTO;
  
  void unos(AUTO *auti, int br){
  	
  	int i;
  	
  	for(i=0; i<br; i++){
  		printf("Unesite % d marku automobila, model, broj konja, najvecu brzinu i cijenu:\n", i+1);
  		
  		(auti[i].marka) = (char*)malloc(100* sizeof(char));
  		if((auti[i].marka) ==NULL){
            printf("Error marka");
  			exit(EXIT_FAILURE);
		  }
		  
		(auti[i].model) = (char*)malloc(100* sizeof(char));
  		if((auti[i].model) ==NULL){
  			printf("error model");
  			exit(EXIT_FAILURE);
		  }
  		scanf("%s", auti[i].marka);  //& ne
  		scanf("%s", auti[i].model);
  		scanf("%d", &(auti[i].brKonja));
  		scanf("%d", &auti[i].speed);
  		scanf("%d", &(auti[i].price)); getchar();
  		
	  }
  	
  }
  
  void ispis(AUTO *auti, int br){
  	
  	int i;
  	for(i=0; i<br; i++){
  		
  		printf("Marka %d automobila: %s\n", i+1, auti[i].marka);
  		printf("Model automobila: %s\n", auti[i].model);
  		printf("Broj konja: %d\n", auti[i].brKonja);
  		printf("Maksimalna brzina: %d\n", auti[i].speed);
  		printf("Cijena: %d\n", auti[i].price);
  		
  		printf("\n");
    }
  }
  
  int main(){
  	
  	int brAuta;
  	
  	printf("Unesite zeljeni broj automobila:\n");
  	scanf("%d", &brAuta);
  	
  	AUTO *auti = NULL;
  	
    auti = (AUTO*)malloc(brAuta* sizeof(AUTO));
  	if(auti==NULL){
  		perror("zauzimanje polja");
  		return 2;
	  }
  	
  	unos(auti, brAuta);
  	ispis(auti, brAuta);
  	
  	
  	int i;
  	for(i=0; i< brAuta; i++){
  		
  		free(auti[i].marka);
  		free(auti[i].model);
	  }
	  free(auti);
  
  	return 0;
  }
  
  
  /*Nadograditi zadatak 1. Kreirati novu zaglavnu datoteku, novu main datoteku te functions2 datoteku u koju treba implementirati
   nove funkcije, a u proces povezivanja samo ukljuèiti i ranije prevedenu object datoteku functions iz zadatka 1. Prva funkcija
   koju treba implementirati je minPriceByHP() koja prima pokazivaè na polje automobila i broj elemenata u polju. Funkcija treba
   ispisati sve podatke o automobilu koji ima najmanju cijenu po jednoj konjskoj snazi. Funkcija ne vraæa nikakvu vrijednost.
   Druga funkcija je sortByVmax() koja prima pokazivaè na polje automobila te broj elemenata u polju. Funkcija treba sortirati
   polje automobila od najbržeg do najsporijeg korištenjem algoritma po izboru. U main-u prikazati uporabu novih funkcija. Saèuvati
   i sve naredbe koje su bile potrebne za prevoðenje programskog koda.*/
   
   #include <stdio.h>
   #include<stdlib.h>
   
   void minPriceByHP(AUTO *auti, int br){
   	
   	int i;
   	int indeks, trenutni = 0;
   	
   	for(i=0; i<br; i++){
   		if(auti[i].brKonja > trenutni){
   				trenutni= auti[i].brKonja;
   				indeks=i;
		   }	
	}
   	
   		printf("Marka automobila: %s\n", auti[indeks].marka);
  		printf("Model automobila: %s\n", auti[indeks].model);
  		printf("Broj konja: %d\n", auti[indeks].brKonja);
  		printf("Maksimalna brzina: %d\n", auti[indeks].speed);
  		printf("Cijena: %d\n", auti[indeks].price);
   }
   
   void swap(int *a, int *b){
   	
   		int temp;
	   	temp = *a;
	   	*a = *b;
	   	*b = temp;
   }
   
   void sortByVMax(AUTO *auti, int br){
   	
   	int i,j;
   	
   		for(i=0; i<br-1; i++){
   			for(j=0; j<br-i-1; j++){
   				if(auti[j+1].speed > auti[j].speed){
   					swap(&auti[j+1], &auti[j]);
				   }
			   }	
		}
   }
   
   
   
   
   
   
   
