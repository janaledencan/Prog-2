/* 1.zad. Napisati C program koji æe proèitati broj iz datoteke Dat.txt. Uèitati s tipkovnice ime i prezime studenata onoliko puta koliko je zapisano u Dat.txt, 
svaki zapis u novi red. Sva uèitana imena i prezimena u formatu „%s %s\n“ zapisati u datoteku Studenti.txt koju je potrebno kreirati iz programa.*/

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
	
	FILE *pFile;
	pFile=fopen("Dat.txt","r");
	if(pFile==NULL){
		printf("Greska prilikom otvaranja datoteke");
		return 1;
	}
	FILE *stud;
	stud=fopen("Studenti.txt","w");
	if(stud==NULL){
		printf("Greska prilikom otvaranja datoteke");
		return 2;	
	}
	int n;
	fscanf(pFile, "%d", &n); //iz file-a izvlacim n- br imena i prezimena
	
	int i;
	char *ime;
	char *prezime;
	
	ime=(char*) malloc(n*sizeof(char));
	if(ime==NULL)
		return 3;
	prezime=(char*)malloc(n*sizeof(char));
	if(ime==NULL)
		return 4;
	
	
	for(i=0; i<n; i++){
		scanf("%s",ime[i]);
		scanf("%S", prezime[i]);
		fprintf(stud, "%s %s\n", ime[i], prezime[i]);
		
	}
	fclose(pFile);
	fclose(stud);
	
	
	
	return 0;
}
*/

/*2. Napisati C program koji æe iz datoteke "in.txt" uèitati prvo dva cijela broja (m i n), a zatim sa tipkovnice uèitati m x n 
 realnih brojeva u realnu matricu A. U datoteku "out.txt" i na ekran ispisati dio matrice , u formatu
  „%.2f\t“, koja se dobije ako izostavimo prvi stupac i zadnji redak. Datoteku "out.txt" treba kreirati iz programa.*/

/*
 #include<stdio.h>
 #include<stdlib.h>
 
 
 int main(){
 	FILE* infile = fopen("in.txt", "r");
 
	 if(infile==NULL){
 		printf("Greska u otvaranju datoteke.");
 		return 1;
 	}
 	
 	int n,m,i,j;
 	fscanf(infile, "%d %d", &n,&m);
 	
 	float **matA;
 	
 	matA= (float**)malloc(n* sizeof(float*));
 	if(matA==NULL)
 		return -1;
 		
 	for(i=0; i<n; i++){
 		matA[i]= (float*)malloc(m* sizeof(float));
 		if(matA==NULL){
 			return -2;
		 }
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%f", &matA[i][j]);
		}
	}
 	
 	FILE* outfile= fopen("out.txt", "w");
 	if(outfile==NULL){
 		printf("Greska.\n");
 		return 2;
	 }
 	
 	for(i=1; i<n; i++){
 		for(j=0; j<m-1; j++){
 			fprintf(outfile, "%.2f\t" , matA[i][j]);
 			printf("%.2f\t", matA[i][j]);
		 }
		 	fprintf(outfile, "\n", matA[i][j]);
		 	printf("\n");
			
	 }
 	
 	for(i=0; i<n; i++){
 		free(matA[i]);
	 }
	 
	 free(matA);
	 
 	
 	fclose(infile);
 	fclose(outfile);
 	
 return 0;
 }
 
 */
 
 /*3. Napišite program koji kopira jednu tekst datoteku u drugu pri èemu mijenja mala slova u velika. 
 Datoteka sa iz koje se kopira se zove Prva.txt i pripremljena je samo za èitanje, a drugu datoteku, imena Druga.txt, trebate kreirati iz programa.*/
 
#include<stdio.h>
#include<stdlib.h>
 
 
 int main(){
 	
 	FILE* kopi;
 	kopi=fopen("Prva.txt", "r");
 	if(kopi==NULL){
 		return 1;
	 }
 	
 	FILE* kreacija;
 	kreacija=fopen("Druga.txt", "w");
 	if(kreacija==NULL){
 		return 2;
	 }
	 
	 char z;
	 int i, dodatna;
	 while(dodatna=fscanf(kopi, "%c", &z)!=EOF){
	 	
	 	if(z>='a' && z<='z'){
	 		z=z-32;	
	 		fprintf(kreacija, "%c", &z);
		 }
	 		
	 }
	 
	 fclose(kopi);
	 fclose(kreacija);
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
