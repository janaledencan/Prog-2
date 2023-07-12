/*1. Napisati C program koji iz datoteke in1.txt u polje uèitava 500 cijelih brojeva u rasponu 0 – 1000. Uèitati broj N s tipkovnice
 	koji takoðer mora biti veæi od 0 i manji od 1000 te provjeriti sekvencijalnim pretraživanjem nalazi li se taj broj u ranije uèitanom
  	polju. Ukoliko je broj pronaðen ispisati poruku „Broj %d je pronadjen nakon %d koraka.“ Ukoliko broj nije pronaðen ispisati poruku
   „Broj %d nije pronadjen.“*/
   
#include<stdio.h>
#include<stdlib.h>


	int main(){

	FILE* docJ= fopen("in1.txt", "r");
	if(docJ==NULL){
		printf("Opening failed.");
		return -1;
	}	
	
	int polje[500];
	int i;
	
	for(i=0; i<500; i++){
		do{			
			fscanf(docJ, "%d", &polje[i]);	
		}while(polje[i]<0 || polje[i]>1000);	
	}
	
	int n;
	do{
		printf("Unesite broj n:\n");
		scanf("%d", &n);
	}while(n<0 || n>1000);
	
	
	int find=0, num=0;
	
	for(i=0; i<500; i++){
		if(polje[i]==n){
			find=1;
			break;
		}
		num++;
	}
	
	if (find) 
		printf ("Broj %d je pronadjen nakon %d koraka.\n", n, num+1); 
	else printf ("Broj %d nije pronaden.\n", n );

	fclose(docJ);
	
	return 0;
}
   
--------------------------------------------------------------------------------------
//U FUNKCIJAMA

#include<stdio.h>

  
   void ucitavanjeBr(FILE* docJ, int *polje){
   	int i;
   		for(i=0; i<10; i++){
			do{			
				fscanf(docJ, "%d", &polje[i]);	
			}while(polje[i]<0 || polje[i]>1000);	
		}
   }
   
   int unosBr(){
   	int n;
   		do{
			printf("Unesite broj n:\n");
			scanf("%d", &n);
		}while(n<0 || n>1000);
		
	return n;
   }
   
   void sekvencijalnoP(int *polje, int n){
   		int i, find=0, num=0;
	
		for(i=0; i<10; i++){
			if(polje[i]==n){
				find=1;
				break;
			}
		num++;
	 }
	if (find) 
		printf ("Broj %d je pronadjen nakon %d koraka.\n", n, num+1); 
	else printf ("Broj %d nije pronaden.\n", n );
   }
   
int main(){	
    
	FILE *docJ= fopen("in1.txt", "r");
		if(docJ==NULL){
			printf("Opening failed.");
		}		
	
	int polje[10];	
	int n;
	
	ucitavanjeBr(docJ, polje);
	n=unosBr();
	sekvencijalnoP(polje, n);
	
	fclose(docJ);
	
	
	return 0;
} 
 
/*2. Napisati C program koji s tipkovnice uèitava 5 cijelih brojeva u rasponu od 1 do 1000. Zatim se uèitava 500 cijelih
 	brojeva iz datoteke in1.txt. Izvršiti pretragu svakog od unesenih brojeva s tipkovnice u uèitanom polju koristeæi metode
  	sekvencijalnog i binarnog pretraživanja. Na kraju je potrebno izraèunati i ispisati srednji broj pretraživanja za svaku
   	metodu pojedinaèno (pri izraèunu srednjeg broja pretraživanja uzeti u obzir samo ona pretraživanja koja su bila pozitivna).
    Ispis na ekran prilagoditi formatu koji je definiran unutar testnih sluèajeva. */
    
    
#include<stdio.h>
    
    void swap (int *x, int *y) {
		int aux;
		aux = *x;
		*x = *y;
		*y = aux;	
	}
	void selectionSort (int brojeviDat[], int num) {
		int i, j, min;
		for (i = 0; i < num; i++) {
			min = i;
			for (j = i+1; j < num; j++)
				if (brojeviDat[j] < brojeviDat[min]) 
					min = j;
				swap(&brojeviDat[i], &brojeviDat[min]);
		}
	}
	
	void binarno(int num, int brojeviDat[] ){
		
	int donjaG=0, gornjaG= 9;
	int i, srednjiClan, brojac=0;
	
	while(donjaG<=gornjaG){
		srednjiClan= (donjaG+gornjaG)/2;
		if(brojeviDat[i]==num ){
			printf("Pronaden broj %d nakon %d koraka.", num, brojac);
			break;
		}
		else if(brojeviDat[i]<num){
			gornjaG=srednjiClan-1;
			brojac++;
		}	
		else if(brojeviDat[i]>num){
			donjaG=srednjiClan+1;
			brojac++;
		}
	}
	if(donjaG<gornjaG)
		printf("Broj nije pronaden.");
}
	
	
    int main(){
    	
    	int num[5];
    	int i;
    	
    	for(i=0; i<5; i++){
    		do{
    			printf("Unesite 5 cijelih brojeva:\n");
    			scanf("%d", &num[i]);
			}while(num[i]<1 || num[i]>1000);
		}
    	
    	FILE *docJ= fopen("in1.txt", "r");
    	if(docJ==NULL){
    		printf("Greska pri otvaranju.\n");
    		return -1;
		}
		
		
		int brojeviDat[10];
		for(i=0; i<10; i++){
			fscanf(docJ, "%d", &brojeviDat[i]);
		}
	
		//sekvencijalno pretrazivanje
		int find[5]={0}; 
		int br[5]={0};
	    int brjcPronadenih=0;
	    int sumKoraci, j;
	    
	for(j=0; j<5; j++ ){
	    for(i=0; i<10; i++){
			if(brojeviDat[i]==num[j]){
				find[j]=1;
				brjcPronadenih++;
				sumKoraci+= br[j];
				break;
			}
		br[j]++;   //broj koraka
	  }
	}
	
	printf("REZULTATI:\n");
	printf("Sekvencijalno pretrazivanje.\n");
		
	
	for(i=0;i<5;i++) {
	if (find) 
		printf ("Broj %d je pronadjen nakon %d koraka.\n", num[i], br[i] ); 
	else printf ("Broj %d nije pronaden.\n", num[i] );
	}
	
	printf("srednja vrijednost sekv. pretr. je %d \n", sumKoraci/brjcPronadenih);
	
	//sortiranje polja
	selectionSort ( brojeviDat, 10);
	
	printf("Binarno pretrazivanje:\n");
	//binarno pretrazivanje
	for(i=0; i<5; i++){
		binarno(num[i], brojeviDat);   
	}
	printf("srednja vrijednost sekv, pretr. je %d \n", sumKoraci/brjcPronadenih);
	
	
	
	fclose(docJ);
    	return 0;
	}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
   
