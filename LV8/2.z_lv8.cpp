/*2. Iskoristiti prethodni zadataka, no dodati jednu više operaciju (posudba filma) u izbornik:
1- Kreiranje datoteke Clanovi.txt,
2- Èitanje iz datoteke Clanovi.txt
3- Dodavanje novih èlanova u Clanovi.txt,
4- Posudba filma
5- Završetak programa
Ukoliko se odabere opcija 4, trebaju se izvršiti sljedeæe operacije:
- pitati koliko se filmova želi posuditi (ne više od 4)
- za svaki film unijeti: ime filma, datum posudbe (broj manji od 365 koji oznaèava dan u godini) i šifra èlana koji je posudio film.
- Sve te podatke o posuðenom filmu spremiti u datoteku posudbe.txt
Ako je korisnik veæ posuðivao filmove, ima pravo posuditi nove filmove dok god je broj posuðenih filmova manji od 4. 
Ukoliko ne postoji datoteka posudbe.txt, potrebno ju je kreirati, u suprotnom je otvaramo i dodajemo nove posuðene filmove.*/


#include <stdio.h>
#include <stdlib.h>


typedef struct clan{
	char prezime[30];
	char ime[20];
	long int sifra;
	char adresa[30];
	long int br_telefona;
}CLAN;

typedef struct film{
	char imeFilma[20];
	int datumPosudbe; 
	long int sifra; 
}FILM; 

void kreiraj();
void citaj();
CLAN definiraj();
void dodavanjeClanova();
FILM unosFilma();
void novaPosudbaFilma();
void zatvoriProgram();

int main(){
	
	FILE *input;
	int br;	
	
	do{
	printf("Odaberite radnju:\n");
	printf("1- Kreiranje datoteke Clanovi.txt,\n 2- Èitanje iz datoteke Clanovi.txt \n 3- Dodavanje novih èlanova u Clanovi.txt \n 4- Posudba filma \n 5-Završetak programa\n");

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
			printf("Koliko filmova zelite posuditi?\n");
			int k;
			scanf("%d", &k);
		//default  return(1);
		NovaPosudbaFilma();
		case 5:
			zatvoriProgram();
			break;
			
			
     }
	
    }while(br<1 || br > 5 );

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
    
    for(int i = 0; i < velicina; i++){
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

FILM unosFilma(){
	FILM filmic;
	printf("Unesite naziv filma: ");
	fgets(filmic.imeFilma,20,stdin);
	printf("Dan posudbe: ");
	do{
		scanf("%LD",&filmic.datumPosudbe); 
		getchar();
	}while(filmic.datumPosudbe<=0 || filmic.datumPosudbe>365);
	 printf("Sifra: ");
	 scanf("%LD",&filmic.sifra); 
	
	return filmic;
}

//podatke o posuðenom filmu spremiti u datoteku posudbe.txt

void novaPosudbaFilma(){
    input = fopen("posudbe.txt", "r");
    if(input == NULL) exit(EXIT_FAILURE);

    int counter = 1;

    fseek(input, 0L, SEEK_END);
    float duljina = ftell(input) / sizeof( FILM );
    rewind(input);

    FILM posudba = unosFilma();
    FILM *posudbe = (FILM *)malloc(duljina * sizeof(FILM ));


    for(int i = 0; i < length; i++){
        fread(&posudbe[i], sizeof(FILM ), 1, input);
    }

    for(int i = 0; i < duljina; i++) if(strcmp(posudbe[i].sifra, posudba.sifra) == 0) counter++;
    fclose(input);

    input = fopen("posudbe.txt", "a+");

    if(counter > 3){
        printf("Preko 4 posudbe!\n");
        fclose(input);
    }
    else if(counter <= 3) {
        fwrite(&posudba, sizeof(FILM ), 1, input);
    }

    fclose(input);
    free(posudbe);
}



void zatvoriProgram(){
	
	fclose(input);
	exit(EXIT_SUCCESS);
}





