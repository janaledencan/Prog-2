#include<stdio.h>
#include<stdlib.h>
#include "header.h" 

   
  int main(){
  	
  	int brAuta;
  	
  	printf("Unesite zeljeni broj automobila:\n");
  	scanf("%d", &brAuta);
  	
  	AUTO *auti;
  	
    auti = (AUTO*)malloc(brAuta* sizeof(AUTO));
  	if(auti==NULL){
  		perror("zauzimanje polja");
  		return 2;
	  }
  	
  	unos(auti, brAuta);
  	ispis(auti, brAuta);
  	
  	printf("\n----------------------\n");
  	printf("najmanju cijenu po jednoj konjskoj snazi\n");
  	minPriceByHP(auti, brAuta);
  	sortByVMax(auti, brAuta);
  	printf("\n----------------------\n");
  	printf("najbržeg do najsporijeg\n");
  	ispis(auti, brAuta);
  	
  	
  	
  	int i;
  	for(i=0; i< brAuta; i++){
  		
  		free(auti[i].marka);
  		free(auti[i].model);
	  }
	  free(auti);
  
  	return 0;
  }
