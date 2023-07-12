//LV 11
/*1. Napisati C program koji iz datoteke in1.txt u polje uèitava 500 cijelih brojeva u rasponu 0 – 1000. 
     Uèitati broj N s tipkovnice koji takoðer mora biti veæi od 0 i manji od 1000 te provjeriti sekvencijalnim
     pretraživanjem nalazi li se taj broj u ranije uèitanom polju. Ukoliko je broj pronaðen ispisati poruku
     „Broj %d je pronadjen nakon %d koraka.“ Ukoliko broj nije pronaðen ispisati poruku „Broj %d nije pronadjen.“*/
     
     #include<stdio.h>
     #include<stdlib.h>
     
     int main(){
     	
     	FILE *doc= fopen("in1.txt", "r");
     	
     	int polje[500];
     	
		int i;
		for(i=0; i<500; i++){
			fscanf(doc, "%d", &polje[i]);	
		} 
		
		int n;
		do{
			printf("Unesite broj n izmedu 0 i 1000:\n");
			scanf("%d", &n);
		}while(n<0 || n>1000);
     	
     	int pronasli=0; 
     	int br=0;
     	
     	while(!pronasli && br<500){
     		if(polje[br]==n){
     			pronasli=1;
			 }
			else
				br++; 
		 }
     	
     	if(pronasli)
     		printf("Broj %d je pronadjen nakon %d koraka.", n, br+1);
     	else
     		printf("Broj %d nije pronadjen.", n);
     	
     	fclose(doc);
     	return 0;
	 }
     
/*2. Napisati C program koji s tipkovnice uèitava 5 cijelih brojeva u rasponu od 1 do 1000. Zatim se uèitava 500 cijelih
 	brojeva iz datoteke in1.txt. Izvršiti pretragu svakog od unesenih brojeva s tipkovnice u uèitanom polju koristeæi metode
  	sekvencijalnog i binarnog pretraživanja. Na kraju je potrebno izraèunati i ispisati srednji broj pretraživanja za svaku
   	metodu pojedinaèno (pri izraèunu srednjeg broja pretraživanja uzeti u obzir samo ona pretraživanja koja su bila pozitivna).
	Ispis na ekran prilagoditi formatu koji je definiran unutar testnih sluèajeva.
	Primjer ispisa: (za unesene brojeve 23, 67, 45, 89, 347)*/
-------------------------
	//ISPPRAVAN KOD SAMO DA BUDE LAKSE TESTIRANJE UMJESTO 500 JE 10 !
	
	#include<stdio.h>
	#include<stdlib.h>
	
	int sekv(int num[], int velicina, int br, int *br_kor);
	
	void swap (int *x, int *y) { // funkcija za zamjenu 2 vrijednosti 
    int aux;
    aux = *x;
    *x = *y; 
    *y = aux; 
}

void quickSort(int a[], int low, int high);

int binarnaP (int K[], int length, int x, int *brk) { 
    int dg, gg, s; 
    dg = 0; 
    gg = length-1; 
    
    while (dg<=gg) { 
        s = (dg+gg)/2; 
        (*brk)++; 
        
        if (x == K[s]) { 
            return s; 
            } 
            else if (x>K[s]) 
                dg = s+1; 
            else if (x<K[s])
                gg = s-1; 
            } 
            if (dg>gg) 
                return -5; 
            }

	
	int main(){
		
	int br[5];
	int i;
	int num[10];
	
	for(i=0; i<5; i++){
		do{
			printf("Unesite br. izmedu 1 i 1000: ");
			scanf("%d", &br[i]);
		}while(br[i]<1 || br[i]>1000);	
	}
	
	FILE *doc= fopen("in1.txt", "r");
	if(doc== NULL){
		printf("Error opening file.");
		return -1;
	}
	
	for(i=0; i<10; i++){
		fscanf(doc, "%d", &num[i]);
	}
	//tu stavit fclose
	//sekvencijalno pretrazivanje
     
	int br_kor= 0;
	int rj;
	
	int brojacsek=0; //brojac koliko ih je pronadeno, tj. za racunanje srednje vrijednosti koraka
	int sumkorakasek=0;
	printf("Sevencijalnim pretrazivanjem:\n");
	for(i=0; i<5; i++){
	   br_kor=0;
	  rj=sekv(num, 10, br[i], &br_kor); 
	  
	  if (rj != -4){ printf ("Broj %d je pronadjen na %d. mjestu u %d koraka.\n",br[i], rj, br_kor); 
	  brojacsek++;
	  sumkorakasek+=br_kor;
	  }
	  else printf ("Broj %d nije pronadjen.\n", br[i]);	  
	}

    float sredvsek=sumkorakasek/brojacsek;


	//binarno pretrazivanje, prije toga sortiranje
	
	quickSort(num, 0, 9);
	int brojacbin=0; // brojac koliko je pronadenih brojeva, za racunanje srednje vr koraka
	int sumkorakabin=0;
	
	printf("\n");
	printf("Binarnim pretrazivanjem:\n");
	for(i=0; i<5; i++){
	   br_kor=0;
	  rj=binarnaP(num, 10, br[i], &br_kor); 
	  
	  if (rj != -5) {printf ("Broj %d je pronadjen na %d. mjestu u %d koraka.\n",br[i], rj, br_kor); 
	  brojacbin++;
	  sumkorakabin+=br_kor;
	  }
	  else printf ("Broj %d nije pronadjen.\n", br[i]);
	}
	
	float sredvbin=sumkorakabin/brojacbin;
	
	
	printf("Srednji broj koraka za sekvencij pretr je: %f \n",sredvsek);
	printf("Srednji broj koraka za binarno pretr je: %f \n", sredvbin);	
	
	
	
		return 0;
	}
	

	
	int sekv(int num[], int velicina, int br, int *br_kor){
    int i;
    
    	for(i=0; i<velicina; i++){
	
	    (*br_kor)++;
	    
		if (num[i] == br) 
			return i; 
	    }
	   return -4;
}
	
void quickSort(int a[], int low, int high) { 
    int i = low, j = high; // funkcija koja obavlja rekurzivno 
    int s = a[(low + high) / 2]; // sortiranje algoritmom brzog sortiranja
    while (i <= j) {  
        while (a[i] < s) {
            i++; 
        } 
        while (a[j] > s) { 
            j--; 
        } 
            if (i <= j) { 
                swap(&a[i], &a[j]); 
                i++; j--; 
                } 
    } 
    if (low < j) 
        quickSort(a, low, j); 
    if (i < high) 
        quickSort(a, i, high); 
    
}
	
		
--------------------------------------------------------------------------------------------------
	#include<stdio.h>
	#include<stdlib.h>
	
	int sekv(int num[], int velicina, int br, int *br_kor);
	
	void swap (int *x, int *y) { // funkcija za zamjenu 2 vrijednosti 
    int aux;
    aux = *x;
    *x = *y; 
    *y = aux; 
}

void quickSort(int a[], int low, int high);

int binarnaP (int K[], int length, int x, int *brk) { 
    int dg, gg, s; 
    dg = 0; 
    gg = length-1; 
    
    while (dg<=gg) { 
        s = (dg+gg)/2; 
        (*brk)++; 
        
        if (x == K[s]) { 
            return s; 
            } 
            else if (x>K[s]) 
                dg = s+1; 
            else if (x<K[s])
                gg = s-1; 
            } 
            if (dg>gg) 
                return -5; 
            }

	
	int main(){
		
	int br[5];
	int i;
	int num[500];
	
	for(i=0; i<5; i++){
		do{
			printf("Unesite br. izmedu 1 i 1000: ");
			scanf("%d", &br[i]);
		}while(br[i]<1 || br[i]>1000);	
	}
	
	FILE *doc= fopen("in1.txt", "r");
	if(doc== NULL){
		printf("Error opening file.");
		return -1;
	}
	
	for(i=0; i<500; i++){
		fscanf(doc, "%d", &num[i]);
	}
	
	//sekvencijalno pretrazivanje
     
	int br_kor= 0;
	int rj;
	
	for(i=0; i<5; i++){
	   br_kor=0;
	  rj=sekv(num, 500, br[i], &br_kor); 
	  
	  if (rj != -4) printf ("Element je pronadjen na %d. mjestu u %d koraka.\n", rj, br_kor); 
	  else printf ("Element nije pronadjen.\n");	  
	}

	//binarno pretrazivanje, prije toga sortiranje
	
	quickSort(num, 0, 499);
	
	for(i=0; i<5; i++){
	   br_kor=0;
	  rj=binarnaP(num, 500, br[i], &br_kor); 
	  
	  if (rj != -5) printf ("Element je pronadjen na %d. mjestu u %d koraka.\n", rj, br_kor); 
	  else printf ("Element nije pronadjen.\n");
	}	
		return 0;
	}
	
	
	
	int sekv(int num[], int velicina, int br, int *br_kor){
    int i;
    
    	for(i=0; i<velicina; i++){
	
	    (*br_kor)++;
	    
		if (num[i] == br) 
			return i; 
	    }
	   return -4;
}
	
void quickSort(int a[], int low, int high) { 
    int i = low, j = high; // funkcija koja obavlja rekurzivno 
    int s = a[(low + high) / 2]; // sortiranje algoritmom brzog sortiranja
    while (i <= j) {  
        while (a[i] < s) {
            i++; 
        } 
        while (a[j] > s) { 
            j--; 
        } 
            if (i <= j) { 
                swap(&a[i], &a[j]); 
                i++; j--; 
                } 
    } 
    if (low < j) 
        quickSort(a, low, j); 
    if (i < high) 
        quickSort(a, i, high); 
    
}
--------------------------------------------------------------------------------S vpl-a
#include<stdio.h>

int sekvencijalnoPretrazi(int *polje, int n);
void zamj (int *x, int *y);
void sortirajSel(int a[], int n);
int binarnoPretrazi(int n, int polje[]);

int main(){
    
    FILE* docJ= fopen("in1.txt", "r");
    if(docJ==NULL){
        printf("Opening fail.\n");
        return -1;
    }
    
    int i;
    int polje[500];
    int num[5];
    
    //ucitavanje s tipkovnice
    for(i=0; i<5; i++){
       do{
            scanf("%d", &num[i]);
        }while(num[i]<0 || num[i]>1000); 
    }
    
    
    //ucitavanje iz dat
    for(i=0; i<500; i++){
            fscanf(docJ, "%d", &polje[i]);
    }
    
    int sekv, brojac_sekv=0;
    float sumSekv=0;
    float srednjaVSek;
    
    printf("REZULTATI:\n"); 
    printf("Sekvencijalno:\n");
    
  //sekvencijalno
   for(i=0; i<5; i++){
       	printf("%d. broj ", i + 1);
        sekv = sekvencijalnoPretrazi(polje, num[i]);
        
        if(sekv != 3){
            brojac_sekv++;
            sumSekv += sekv;
        
        }   
   }
    
   if(brojac_sekv == 0){
       srednjaVSek = sumSekv/1;
   }
   else
        srednjaVSek= sumSekv/brojac_sekv;
        
        
  
    sortirajSel(polje, 500);
    
    //binarno
    
    printf("\nBinarno:\n");
    
    int bnrn=0;
    int brojac_bnrn=0;
    float sumBnrn=0;
    
    for(i=0; i<5; i++){
       	printf("%d. broj ", i + 1);
        bnrn = binarnoPretrazi(num[i], polje);
        
        if(bnrn != 4){
            brojac_bnrn++;
            sumBnrn += bnrn ;
        
        }   
   }
    
    float srednjaVBin;
    
    if(brojac_bnrn == 0){
       srednjaVBin = sumBnrn/1;
   }
   else
        srednjaVBin= sumBnrn/brojac_bnrn;    
    
    
    
   printf("Srednji broj koraka za sekvencijalno pretrazivanje je: %.2f\n",srednjaVSek);
   printf("Srednji broj koraka za binarno pretrazivanje je: %.2f", srednjaVBin);
    fclose(docJ);
    return 0;
}


int sekvencijalnoPretrazi(int *polje, int n){
    
    int find= 0;
    int brojac = 0;
    int i;
    
      for(i=0; i<500; i++){
          
        if(polje[i]==n){
            printf("%d je pronadjen u %d koraka.\n",  n, brojac+1);
            find=1;
            return (brojac+1);
        }
        brojac++;
    }
        if(find==0) printf("%d nije pronadjen.\n",  n);   
  
   return 3;
}


void zamj (int *x, int *y) {
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

void sortirajSel(int a[], int n) {

    int i, j, min;
    
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (a[j] < a[min]) min = j;
        zamj(&a[i], &a[min]);
    }
}

int binarnoPretrazi(int n, int polje[]){
    
    int dg = 0;
    int gg = 499;
    int s;
    int brkor = 0;
    
    while (dg<=gg) {
        
        s = (dg+gg)/2;
        
        if (n == polje[s]) {
            brkor++;
            printf ("%d je pronadjen u %d koraka.\n", n, brkor);
            return brkor;
        }
         if (n > polje[s]) {
            dg = s+1;
            brkor++;
         
        }
         if (n < polje[s]) {
            gg = s-1;
            brkor++;
        }
    }
if (dg>gg){
   printf ("%d nije pronadjen.\n", n);
   return 4; 
} 
    
}	
--------------------------------------------------------------------------------
/*3.Napisati C program u kojem æete implementirati funkcije za selection sort i bubble sort. Program iz datoteke
 	ulaz.txt prvo uèitava jedan broj koji oznaèava koliko elemenata slijedi, a nakon toga program treba uèitati n cijelih
  	brojeva u polje. Omoguæiti korisniku izbornik u kojem æe imati moguænost:
	1. ispisati uèitano polje, 2. sortirati ga koristeæi bubble sort uzlazno, 3. sortirati ga koristeæi bubble sort silazno,
	4. sortirati ga koristeæi selection sort uzlazno, 5. sortirati ga koristeæi selection sort silazno, 6. zapisati polje u
 	datoteku izlaz.txt, 7. Kraj
	Funkcije za sortiranje primaju pokazivaè na polje, duljinu polja te parametar koji kazuje treba li vršiti uzlazno ili
 	silazno sortiranje. Ovaj zadatak ne predajete preko VPL-a.*/	
	
	#include<stdio.h>
	
	
int main(){
	
	FILE* doc=fopen("ulaz.txt", "r");
	if(doc==NULL){
		printf("Greska pri otvaranju file-a.");
		return -1;
	}
	
	int brElemenata;
	fscanf(doc,"%d",&brElemenata);
	
	int polje*;
	polje=(int*)calloc(brElemenata*sizeof(int));
		if(polje==NULL)
			return -2;
	
	int i;
	for(i=0;i<brElemenata;i++){
		
		fscanf(doc,"%d", &polje[i]);
	}
	
	int r;
	
	printf("1. ispisati uèitano polje\n");
	printf("2. sortirati ga koristeæi bubble sort uzlazno\n");
	printf("3. sortirati ga koristeæi bubble sort silazno\n");
	printf("4. sortirati ga koristeæi selection sort uzlazno\n");
	printf("5. sortirati ga koristeæi selection sort silazno\n");
	printf("6. zapisati polje u datoteku izlaz.txt\n");
	printf("7. Kraj\n");
	
	printf("Odaberite radnju (1-7): ");
	scanf("%d",&r);
	
return 0;	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
