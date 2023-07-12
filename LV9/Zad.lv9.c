/*1. zad. Rekurzija prima jednu cjelobrojnu vrijednost koja je visina piramide. U datoteku piramida, koju æete kreirati iz programa,
 „nacrtati“ piramidu od znakova '*' koja može imati maksimalnu visinu 30 redova. U main() dijelu uèitati visinu piramide te
  pozvati rekurziju. Primjer piramide je prikazan na slici niže.*/
  
  //1.pokusaj
  #include<stdio.h>
  #include<stdlib.h>
  
  int main(){
  	
  	int visina;
  	
  	do{
	  	printf("Unesite visinu piramide (do 30):\n");
  		scanf("%d", &visina);
  		
	  }while(visina<0 || visina>30);
  	
  	piramida(visina);
  	
  	return 0;
  }
  
   void piramida(int visina){
  	
  	int i;
  	
  	for( i= 30-visina; i > 0; i--){   //for(i=0; i< visina; i++)  mi bi mozda trebale izracunat
  		printf("*");	
	  }
	  
	  printf("\n");	  
	  
	  if(visina != 0){
  		    piramida(visina-1);		
	    }	
  }
  
//2.pokusaj - dobar ispis na ekranu, obrnut u file-u
#include<stdio.h>
#include<stdlib.h>

   
void piramida(int visina);
  
int main(){
  	
  	int visina;
  	
  	do{
	  	printf("Unesite visinu piramide (do 30):\n");
  		scanf("%d", &visina);
  		
	  }while(visina<0 || visina>30);
  	
  	piramida(visina);
  	
  	return 0;
  }
  
int varijabla=1;
 	
void piramida(int visina){
  	
  	int i;
    	
    
  	FILE *trokuticDok = fopen("trokut.txt", "a");
  	if(trokuticDok==NULL){
  	    perror("Error");
  	}
 	
 
 	int zvijezdice= 2 * varijabla -1;

 	
 	for(i=visina-varijabla; i>=0; i--){
 	   // printf(" ");
 	    fprintf(trokuticDok, "%c", ' ');
 	}
 	for(i=0; i<zvijezdice; i++){
 	   // printf("*");
 	    fprintf(trokuticDok, "%c", '*');
 	} 
 	//printf("\n");
 	fprintf(trokuticDok, "%c", '\n');
 	varijabla++;
 	
 	if(varijabla<=visina)
 	    piramida(visina);
 	
 	fclose(trokuticDok);
 	trokuticDok=NULL;
  }
  
 //3.pokusaj- valja varajuci sistem hahaha

#include<stdio.h>
#include<stdlib.h>


void piramida(int visina, int);
  
int main(){
  	
  	int visina;
  	
  	do{
	  	printf("Unesite visinu piramide (do 30):\n");
  		scanf("%d", &visina);
  		
	  }while(visina<0 || visina>30);
  	
  	piramida(visina,visina);
  	
  	return 0;
  }
  
int varijabla=1;	
 	
void piramida(int visina, int a){
  	
  	int i;
    
  	FILE *trokuticDok = fopen("trokut.txt", "a");
  	if(trokuticDok==NULL){
  	    perror("Error");
  	}
 
 	int zvijezdice= 2 * visina - 1;

 	
 	for(i=0; i<varijabla; i++){
 	   // printf(" ");
 	    fprintf(trokuticDok, "%c", ' ');
 	}
 	for(i=0; i<zvijezdice; i++){
 	   // printf("*");
 	    fprintf(trokuticDok, "%c", '*');
 	} 
 	//printf("\n");
 	fprintf(trokuticDok, "%c", '\n');
 	
 	
 	if(varijabla<=a){
 	    
  	    varijabla++;
 	    visina --;
 	    piramida(visina,a);	    
 	}
 	
 	fclose(trokuticDok);
 	trokuticDok=NULL;
  }
   
//4.-kao mrgin

#include <stdio.h>

void pyramid(int height) {
    
	static int level = 1;
	int i;

	FILE* trokuticDok = fopen("piramida.txt", "a");
	if (trokuticDok == NULL) 
	    perror("Error"); 

	int zvijezde = 2 * level - 1;
	int brElemenata = 2 * height - 1;
	int razmak = ((brElemenata - zvijezde) / 2) + 1;


	for (i=0; i < razmak; i++) 
	    fprintf(trokuticDok, "%c", ' ');

	for (i = 0; i < zvijezde; i++) 
	    fprintf(trokuticDok, "%c", '*');
	    
	fprintf(trokuticDok, "%c", '\n');

	fclose(trokuticDok); 
	trokuticDok = NULL;

	level++;
	if (level <= height) 
	    pyramid(height);
}


int main(void) {

	int height;
	
	do{
	    printf("Unesite visinu: ");
	    scanf("%d", &height);
	    
    }while(height<0 || height>30);
    
	pyramid(height);

	return 0;
}
  
  
  /*2. Napisati C program koji æe uèitati cijeli broj te u datoteku naziva suma.txt upisati
sumu njegovih znamenaka. Za traženje sume znamenaka broja koristiti rekurziju.*/

#include<stdio.h>

int traziSumu(int br);

int main(){
	
	int broj;
	
	FILE *infile= fopen("suma.txt", "w");
	if(infile==NULL){
		printf("Pogreska pri otvaranju datoteke !\n");
		return -1;
	}
	printf("Unesite zeljeni cijeli broj:\n");
	scanf("%d", &broj);
	
	fprintf(infile, "%d", traziSumu(broj));
	
	fclose(infile);
	infile==NULL;
	
	return 0;
}


int z=0;  //kao globalna varijabla
	
int traziSumu(int br){
	
	int i;

	
	z += br % 10;
	
	if(br != 0){
		br /= 10;
		traziSumu(br);
	}

	return z;
}





  
  
  
