/*Napišite C program koji æe iz datoteke racun.txt uèitati n artikala u raèun. Datoteka racun.txt
 je veæ zadana, a sadrži ime kupca, ime prodavaèa, broj artikala u raèunu i podatke o svakom od artikala.
 Program treba ispisati ukupan iznos raèuna na ekran u obliku: „Ukupan iznos racuna: %.2f“. Postavljen je
 oblik struktura, primjetite da je unutar struktura svu memoriju za polja (bilo znakova bilo struktura)
 potrebno alocirati dinamièki. Kako je struktura zadana, na osnovu tipova podataka èlanova strukture i
 oblika podataka u ulaznoj datoteci možete zakljuèiti kako trebate upisati ulazne podatke.*/
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 
typedef struct artikl {
	char* naziv;
	float cijena;
	int kolicina;
} ARTIKL;

typedef struct racun {
	char* prodavac;
	char* kupac;
	ARTIKL* artikli;
	int  broj_artikala;
	float ukupan_iznos;
} RACUN;
 
 int main(){
 	
 	//otvorimo i zatvorimo file 
 	FILE *dokJ= fopen("racun.txt", "r");
	if(dokJ==NULL){
		printf("File nije uspjesno otvoren\n");
		return -1;
	}  
 	
 	//nademo si broj artikala iz file-a
 	int num;
 	fscanf(dokJ, "%d", &num);
 	
 	//dinamicko zauzimanje za artikl i racun i oslobadanje
 	ARTIKL *artikli;
 	artikli=(ARTIKL*)malloc(num* sizeof(ARTIKL));
 	if(artikli==NULL){
 		return -2;
	 }
 	
 	RACUN *racuncic;
 	racuncic=(RACUN*)malloc(sizeof(RACUN));
 	if(racuncic==NULL){
 		return -3;
	 }
 	
 	//ucitali smo artikle u artikli(polje)
 	int i;
 	for(i=0; i<num; i++){
 		
 	fscanf(dokJ, "%s", &racuncic.artikli[i].naziv );
	fscanf(dokJ, "%f", &racuncic.artikli[i].cijena);
	fscanf(dokJ, "%d", &racuncic.artikli[i].kolicina);	
}
 	//cijenu i kolicinu pomnozimo i sve pozbrajamo za ukupan iznos
 	for(i=0; i<num; i++){
 		
 		float iznos;
 		iznos+= racuncic.artikli[i].cijena*racuncic.artikli[i].kolicina;
	 }
 	
 	
 	
 	printf("Ukupan iznos racuna: %.2f", iznos);
 	
 	free(artiklic);
 	free(racuncic);
 	artiklic=NULL;
 	racuncic=NULL;
 	
 	fclose(dokJ);
 	return 0;
 }
 
 
 //zadnji kod
 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 #include<string.h>
 
typedef struct artikl {
	char* naziv;
	float cijena;
	int kolicina;
} ARTIKL;

typedef struct racun {
	char* prodavac;
	char* kupac;
	ARTIKL* artikli;
	int  broj_artikala;
	float ukupan_iznos;
} RACUN;
 
 
 void read_name();
 
 int main(){
 	
 	//otvorimo i zatvorimo file 
 	FILE *dokJ= fopen("racun.txt", "r");
	if(dokJ==NULL){
		printf("File nije uspjesno otvoren\n");
		return -1;
	}  
 	
 	//nademo si broj artikala iz file-a
 	int num;
 	fscanf(dokJ, "%d", &num);
 	
 	//dinamicko zauzimanje za artikl i racun i oslobadanje
 	ARTIKL *artikli;
 	artikli=(ARTIKL*)malloc(num* sizeof(ARTIKL));
 	if(artikli==NULL){
 		return -2;
	 }
 	
 	RACUN *racuncic;
 	racuncic=(RACUN*)malloc(sizeof(RACUN));
 	if(racuncic==NULL){
 		return -3;
	 }
 	
    int i;
    read_name();
 	
 	//ucitali smo artikle u artikli(polje)
 	for(i=0; i<num; i++){
 		
 	fgets(&racuncic->artikli[i].naziv, sizeof(), 1, dokJ); fgetc(dokJ);
	fscanf(dokJ, "%f", &racuncic->artikli[i].cijena);
	fscanf(dokJ, "%d", &racuncic->artikli[i].kolicina);	
}
 	//cijenu i kolicinu pomnozimo i sve pozbrajamo za ukupan iznos
 	
 	float iznos;
 	for(i=0; i<num; i++){
 		iznos+= racuncic->artikli[i].cijena*racuncic->artikli[i].kolicina;
	 }
 	
 	
 	
 	printf("Ukupan iznos racuna: %.2f", iznos);
 	
 	free(artikli);
 	free(racuncic);
 	artikli=NULL;
 	racuncic=NULL;
 	
 	fclose(dokJ);
 	return 0;
 }
 
 void read_name() {
 int i;
 char *naziv;
 char buff[100];
 fgets(buff, 100, stdin);
 for ( i=0; buff[i] != '\n'; i++) {} //prazan for da se dodje na kraj polja
    buff[i] = '\0';
 naziv = (char*) malloc( strlen(buff) * sizeof(char) );
 strcpy(naziv, buff);
 }
 
 
 
 
 
 
 
 
 
 
 
 
