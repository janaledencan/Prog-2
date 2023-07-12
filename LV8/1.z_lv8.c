/*1. Napisati C program kojim æete omoguæiti voðenje evidencije èlanova jedne videoteke.
 Program treba omoguæiti korisniku kreiranje datoteke Clanovi.txt ukoliko ne postoji (prvi puta kada se pokrene program) te èitanje
  ili dodavanje novih èlanova u datoteku Clanovi.txt. Sljedeæi podaci o èlanovima se trebaju zapisati: prezime, ime, šifru, adresu 
  i broj telefona. Na poèetku programa ponuditi korisniku izbornik za odabir željene radnje:
1- Kreiranje datoteke Clanovi.txt,
2- Èitanje iz datoteke Clanovi.txt
3- Dodavanje novih èlanova u Clanovi.txt
4- Završetak programa.
Operacije za rad sa datotekama izvesti sa funkcijama.*/


#include <stdio.h>
#include <stdlib.h>


typedef struct clan{
	char prezime[30];
	char ime[20];
	long int sifra;
	char adresa[30];
	long int br_telefona;
}CLAN;

void kreiraj();
void citaj();
CLAN definiraj();
void dodavanjeClanova();
void zatvoriProgram();



int main(){
	
	FILE *input;
	int br;	
	
	do{
	printf("Odaberite radnju:\n");
	printf("1- Kreiranje datoteke Clanovi.txt,\n 2- Èitanje iz datoteke Clanovi.txt \n 3- Dodavanje novih èlanova u Clanovi.txt \n 4- Završetak programa.\n");

	scanf("%d", &br);

	
	switch(br){
		case 1:
			kreiraj();
			break;
			
		case 2:
			citaj();
			break;
		
		case 3:	
			dodavanjeClanova();
			break;
			
		
		case 4:
			zatvoriProgram();
			break;
     }
	
    }while(br <1 || br>4 );

	fclose(input);
	return 0;
}


void kreiraj(){
	FILE *input;	
	input=fopen("Clanovi.txt", "ab");
		if(input==NULL){
			perror("Greska");
			
		}
		fclose(input);
}


void citaj(){
	int i;
	FILE *input;	
	input=fopen("Clanovi.txt", "rb");
		if(input==NULL){
			perror("Greska pri otvaranju datoteke.");
			exit(EXIT_FAILURE);
		}
		

    CLAN *clanovi = NULL;
    fseek(input, 0L, SEEK_END);
    float velicina = ftell(input) / sizeof(CLAN);

    clanovi = (CLAN *)malloc(velicina * sizeof(CLAN));

    rewind(input); 
    int i;
    
    for(i = 0; i < (int)velicina; i++){
        fread(&clanovi[i], sizeof(CLAN), 1, input);
         printf("Prezime: %s Ime: %s Sifra: %ld Adresa: %s Telefon: %ld\n", clanovi[i].prezime, clanovi[i].ime, clanovi[i].sifra, clanovi[i].adresa, clanovi[i].br_telefona);
    }

    fclose(input);
    free(clanovi);
}
	


CLAN definiraj(){
	CLAN osoba;
	
	printf("Prezime: ");
	fgets(osoba.prezime, 30, stdin);
	
	printf("Ime: ");
	fgets(osoba.ime, 20, stdin);
	
	printf("sifra ");
	scanf("%ld", &osoba.sifra);
	getchar();
	
	printf("Telefon ");
	fgets(osoba.adresa, 30, stdin);
	scanf("%ld", &osoba.br_telefona);		
	
	return osoba;
}

void dodavanjeClanova(){
	FILE *input;
	input=fopen("Clanovi.txt", "ab");
		if(input==NULL){
			perror("greska");
			exit(EXIT_FAILURE);
		}
		
	CLAN podaci = definiraj();
	//moglo je ostati umjesto CLAN definiraj odma ovdje moze fgets(...,...,stdin); samo bi def varijablu tipa clan
	fwrite(&podaci, sizeof(podaci), 1, input);	
	fclose(input);
}

void zatvoriProgram(){
	
	fclose(input);
	exit(EXIT_SUCCESS);
}


