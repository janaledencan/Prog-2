#include<stdio.h>
#include "header6_2.h"

void unos (int n){
		
		printf ("Unesite broj artikala n koje cete uneti u racun:\n");
		scanf("%d", &n);
	}
	
void unosPodatakaArtikala (ARTIKLI *art, int n ){
	
	int i;
	for(i=0;i<n;i++){
		
		printf("Unesite ime %d artikla:\n", i+1);
		fgets(art[i].ime, 40, stdin);
		
		printf("Unesite cijenu %d artikla:\n", i+1);
		scanf("%f", &art[i].cijena);
		
		printf("Unesite bar kod %d artikla:\n", i+1);
		scanf("%ld", &art[i].barKod);
	}	
	
}

void racun (ARTIKLI *art, int n){
	
	int i;
	
	printf("Raèun:\n");
	
	for(i=0;i<n;i++){
		
		printf("%d artikl:\n", i+1);
		printf( "%d \t\t %f \t\t %ld\n", art[i].ime, art[i].cijena, art[i].barKod);
		
	}	
}
