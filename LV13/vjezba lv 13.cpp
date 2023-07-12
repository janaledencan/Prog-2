/*Korisnik treba unijeti cjelobrojnu vrijednost u rasponu od 1 do 7, pri èemu 1 predstavlja ponedjeljak, a 7 nedjelju.
 Ispisati poruku „Vikeeeend!“ ako je unesen broj koji oznaèava neradne dane ili poruku „Radis jos %d dana do vikenda.“
  ako je unesen broj koji oznaèava radne dane. Za dane u tjednu koristiti enumeraciju.*/
  
  #include<stdio.h>
  #include<stdlib.h>
  
  enum dani{ pon=1, uto, sri, cet, pet, sub, ned };
  
  int main(){
  	
  	int dan;
  	
  	do{
  		printf("Unesite br u rasponu 1-7:\n");
  		scanf("%d", &dan);
	  }while(dan < pon || dan > ned);
  	
  	if(dan<=pet)
  		printf("Radis jos %d dana do vikenda.", ned-(dan+1));
	  
	else{
		printf("Vikeeeend!");
	}  	
  	return 0;
  }
  
  
  /*Implementirati makro koji raèuna indeks s u binarnom pretraživanju (s = (dg+gg)/2). U glavnoj funkciji uèitati 500 brojeva
   iz datoteke in.txt te s tipkovnice tražiti unos broja koji tražimo u danom polju u intervalu [1, 1000]. Ispisati poruku „Broj nije nadjen.“
   ili „Broj je nadjen.“ s obzirom na rezultat pretraživanja.*/
   
   #include<stdio.h>
  #include<stdlib.h>
   
   #define sredina(dg, gg) ((dg + gg)/2)
   
	void zamjena( int *a, int *b){
		
	   	int temp;
	   	temp = *a;
	   	*a = *b;
	   	*b = temp;
   }
   
   void bubbleSort(int array[], int vel){
   	
   	int i,j;
	
	for(i=0; i<vel-1; i++){
		for(j=0; j<vel-1-i; j++){
			if(array[j+1] < array[j])
				zamjena(&array[j+1], &array[j]);
		}
	} 
	  	
   }
   
   void binarySearch(int array[], int vel, int num){
	
	int dg=0; 
	int gg= vel-1;
	int s;

	
	while(dg<=gg){
		
		s = sredina(dg,gg);
			
		if(array[s]== num){
			printf("Broj je nadjen.");
			break;
		}
		else if(num < array[s]){
			gg= s-1;
		}
		else if(num > array[s]){
			dg= s+1;
		}
	
	}
	if(dg>gg)
	    printf("Broj nije nadjen.");
	
   }
   
   int main(){
   
   	FILE *docJ= fopen("in.txt", "r");
	   if(docJ== NULL){
			exit(EXIT_FAILURE);
			return -1;
	   }	
	   
	int i;
	int *array;
	
	array= (int*)malloc(15 * sizeof(int));
	if(array==NULL){
	    return -2;
	    exit(EXIT_FAILURE);
	}
	for(i=0; i<15; i++){
		fscanf(docJ, "%d", &array[i]);
	}
		
	fclose(docJ);

	bubbleSort(array, 15);
	
	
	int num;
	printf("Unesite zeljeni broj:\n");
	
	do{
		scanf("%d", &num);
	}while(num<1 || num>1000);
	
	
	printf("REZULTATI:\n");
	binarySearch(array, 15, num);
	
	free(array);
	
   	return 0;
   }
   
