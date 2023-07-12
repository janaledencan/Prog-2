// lv 12

#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int id;
	char *ime;
	char *prezime;
	float prosjek;
	struct student* next;
}STUDENT;

STUDENT* kreiranjePopisa();
STUDENT* umetanjeNovogCvora( STUDENT* glava);
void ispisSvihClanova(STUDENT* prijelazniC);
STUDENT*pretraziID( STUDENT* prijelazniC, int iD);
void brisanjeCvora(STUDENT** glava, STUDENT* prijelazniC);
STUDENT* brisanjeCijeleListe(STUDENT* prijelazniC);
void unosPodataka(STUDENT* cvor);
float prosjekSvihStudenata(STUDENT* glava);


int main(){     //dvostruki povezani popis
	
	//STUDENT *glava = NULL;    //deklaracija pokazivaca na strukturu(pokazuje na pocetak povezanog popisa)
	
	STUDENT *glava = kreiranjePopisa();
	glava = umetanjeNovogCvora(glava);    //postavljanje nove glave na pocetku DPP-a
	
	int n;
	printf("Unesite broj studenata:\n");
	scanf("%d", &n);
	
	
	printf("REZULTATI:\n");
	ispisSvihClanova(glava);
	pretraziID(glava, n);    //?????
	
	printf("Ukupan prosjek svih studenata je: %.2f", prosjekSvihStudenata(&glava));
	
	printf("Unesite ID studenta kojeg zelite obrisati:\n");
	int idBrisati;
	scanf("%d", &idBrisati);	
	brisanjeCvora(&glava, idBrisati);
	
	if(){   //???
		ispisSvihClanova(glava);
	} 
	else{
		printf("Student s trazenim ID-em nije pronadjen!");
	}
	
	STUDENT* prijelazniC;
	brisanjeCvora(&glava, prijelazniC);
	glava = brisanjeCijeleListe(glava);
	
	return 0;
}

STUDENT* kreiranjePopisa(){
	
	STUDENT* glava=(STUDENT*)calloc(1, sizeof(STUDENT));  //zauzeli memoriju za strukturu
	
	if(glava== NULL){
		
		perror("Kreiranje");
		return NULL;
	}
	else{
		// poziv funkcije unosPodataka
		
	/*	printf("Unesite cijeli broj!\n");
		scanf("%d", &headNode->number);
		headNode->nextNode = NULL;
		headNode->previousNode = NULL;  */
		
		unosPodatka(glava);
	}
	
	return glava;  //vracanje memorijske adrese strukture
}

STUDENT* umetanjeNovogCvora( STUDENT* glava){
	
	STUDENT* novaGlava = (STUDENT*)calloc(1, sizeof(STUDENT));   //zauzimanje memorije za novu glavu
	if(novaGlava == NULL){
		perror("Kreiranje nove glave");
		return glava;                        //ako se ne zauzme mem za novu glavu vraca staru
	}
	else{
		//poziv funkcije unosPodataka
		/*  printf("Unesite cijeli broj!\n");
			scanf("%d", &newHeadNode->number);
			newHeadNode->nextNode = headNode;
			newHeadNode->previousNode = NULL;
			headNode->previousNode = newHeadNode;  */
			
			unosPodatka(glava);
	}
	
	return novaGlava;
}

void ispisSvihClanova(STUDENT* prijelazniC){         //nismo sigurni za povratni tip
	
	//int counter = 0;
	
	if(prijelazniC== NULL){
		perror("Greska pri ispisu");
	}
	else{
		while(prijelazniC){
			
			printf(	"ID: %d - %s %s, prosjek: %f", prijelazniC->id, prijelazniC->ime, prijelazniC->prezime, prijelazniC->prosjek); 
			prijelazniC = prijelazniC->next; 
		}
	}
}

STUDENT*pretraziID( STUDENT* prijelazniC, int iD){  //drugi parametar predstavlja vrijednost kojom æe se usporeðivati podatkovni èlan svakog èvora povezanog popisa
	
	while(prijelazniC){
		
		if(prijelazniC->id == iD ){
			return prijelazniC;
		}
		else{
			prijelazniC = prijelazniC->next;
		}
	}
	return NULL;
}

void brisanjeCvora(STUDENT** glava, STUDENT* prijelazniC){
	
	if((*glava) == prijelazniC){
		
		*glava = (*glava)->next;
		(*glava)->next = NULL;
		free(prijelazniC);
		printf("Osloboden cvor: %p\n", prijelazniC);
	}
	else if(prijelazniC->next == NULL){
		
		prijelazniC = prijelazniC->next;
		free(prijelazniC->next);
		printf("Osloboden cvor: %p\n", prijelazniC);
		prijelazniC->next = NULL;
	}
	//else
	
}

STUDENT* brisanjeCijeleListe( STUDENT* prijelazniC){
	
	while( prijelazniC->next != NULL){
		
		prijelazniC = prijelazniC->next;
		free(prijelazniC->next);
	}
	
	free(prijelazniC);
	printf("Oslobodeno sve");
	
	return NULL;
}

void unosPodataka(STUDENT* cvor){
	
	cvor->ime = (char*)malloc(50* sizeof(char));
	if(cvor->ime == NULL){
		perror("Zauzimanje memorije za ime");
	}
	
	cvor->prezime = (char*)malloc(50* sizeof(char));
	if(cvor->prezime == NULL){
		perror("Zauzimanje memorije za prezime");
	}
	//jel treba to brisat ili u cjelokupnom brisanju se brise
	
	printf("Unesite ID:\n");
	scanf("%d", &cvor->id);  fgets();
	printf("Unesite ime:\n");
	scanf("%s", cvor->ime);   fgets();
	printf("Uneiste prezime:\n");
	scanf("%s", cvor->prezime);
	printf("unesite prosjek:\n");
	scanf("%f", &cvor->prosjek);
	
}

float prosjekSvihStudenata(STUDENT* glava){

 		
	
	
}






