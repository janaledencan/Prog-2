//Vjezba lv12

/* funkcije za kreiranje povezanog popisa, umetanje novog èvora na poèetak popisa, 
pretraživanje popisa prema id-u studenta, brisanje odreðenog èvora popisa te brisanje cijelog popisa*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct student{
int id;
char *ime;
char *prezime;
float prosjek;
struct student* next;
}STUDENT;

STUDENT* createList(){
	
	STUDENT *headL = (STUDENT*)malloc(1* sizeof(STUDENT));
	if (headL == NULL) {
		perror("Kreiranje");    //promj
		return NULL;
	}
	else{
		unosPodataka(headL);
	}
	headL->next = NULL;
	return headL;
}


STUDENT* umetanjeCv(STUDENT* headL){
	
	STUDENT *noviPocetak = (STUDENT*)malloc(1* sizeof(STUDENT));
	if (noviPocetak == NULL) {
		perror("Kreiranje"); //promj
		return headL;
	}
	noviPocetak->next = headL;
	
	unosPodataka(headL);
	//STUDENT*headL = searchSLList(headNode, 5);
	return noviPocetak;
}


STUDENT* pretraziPopisID(STUDENT* headL, int trazeniID){
	
	while (headL) {
		if (headL->id == trazeniID) {
			return headL;
		}
		else {
			headL = headL->next;
		}
	}
return NULL;
}


float prosjekSvihStudenata(STUDENT* headL){
	float sum=0;
	int counter=0;
	
	while(headL != NULL){
		sum+= headL->prosjek;
		counter ++;
		headL = headL->next;
	}
	return sum/counter;
}


void unosPodataka(STUDENT* headL){
	
	//int id;
	char imeS[50], prezimeS [50];
	float prosjek;
	
	scanf("%d", &headL->id); getchar();
	//printf("ID: %d - ", headL->id);
	
	
	fgets(imeS, 50, stdin);
	headL->ime= (char*)malloc(strlen(imeS)* sizeof(char));
	//printf("%s ", headL->ime);
	
	
	fgets(prezimeS, 50, stdin);
	headL->prezime= (char*)malloc(strlen(prezimeS)* sizeof(char));
	//printf("%s, ", headL->prezime);
	
	scanf("%f", &headL->prosjek);  getchar();
	//printf("prosjek: %f", headL->prosjek);
}



void obrisiCvor(STUDENT** headL, STUDENT* zeljanBrisanja){
	if (*headL == zeljanBrisanja) {
			*headL = (*headL)->next;
			free(zeljanBrisanja);
			//printf("Oslobodjen chvor: %p\n", zeljanBrisanja);
	}
		else {
				STUDENT* trenutni = *headL;
				while (trenutni->next) {
						if (trenutni->next == zeljanBrisanja) {
						trenutni->next = zeljanBrisanja->next;
						free(zeljanBrisanja);
							//printf("Oslobodjen chvor: %p\n", zeljanBrisanja);
											break;
				}
				trenutni =trenutni->next;
			}
		}
}


STUDENT* obrisiPopis(STUDENT* trenutni){
	
	STUDENT* obrisi = NULL;
	while (trenutni) {
		obrisi = trenutni;
		trenutni = trenutni->next;
		free(obrisi);
		//printf("Oslobodjen chvor: %p\n", obrisi);
	}
	return NULL;
}
	


int main(){
	
	//STUDENT* headL= NULL;
	STUDENT* headL= createList();
	
	int brStudenata;
	printf("Unesite zeljeni broj studenata:\n");
	scanf("%d", &brStudenata);
	
	for(int i=0;i<brStudenata-1;i++)
        headL= umetanjeCv(headL);
	//unosPodataka(headL);
	printf("Ukupan prosjek svih studenata je: %.2f.\n", prosjekSvihStudenata(headL));


    int trazeniID;
    printf("Unesite zeljeni Id za obrisati:\n");
	scanf("%d", &trazeniID);
	STUDENT *zeljanBrisanja = pretraziPopisID( headL, trazeniID);
	obrisiCvor(&headL, zeljanBrisanja);
	
	unosPodataka(headL);
	headL = obrisiPopis(headL);

	return 0;
}




