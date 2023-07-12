/*1.zad Napišite C program koji uèitava toèke i trokute iz datoteke model.txt. Program iz datoteke uèitava prvo broj toèaka n, 
zatim broj trokuta m, a zatim toèke i trokute. Potrebno je dinamièki alocirati memoriju za unos toèaka i trokuta.
Pronaæi i ispisati opseg trokuta koji ima najveæi opseg u formatu „%.2f“.*/


//ISPRAVNI
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct tocka{
	float x;
	float y;
	float z;
}TOCKA;

typedef struct trokut{
	TOCKA *vrh1;
	TOCKA *vrh2;
	TOCKA *vrh3;
}TROKUT;

float opseg(float, float, float, float, float, float,float,float,float);

int main(){
	
	
	int n,m;    //broj tocaka-n , broj trokuta-m
	TOCKA *unosTocaka;
	TROKUT *unosTrokuta;
	
	
	FILE *infile= fopen("model.txt", "r");
	if(infile==NULL){
		printf("Neuspjelo otvaranje datoteke\n");
		return -1;
	}
	
	fscanf(infile,"%d", &n);   //za ucitati broj tocaka iz dok
	fscanf(infile, "%d", &m);
	
	
	unosTocaka= (TOCKA*)calloc(n, sizeof(TOCKA));
	if(unosTocaka==NULL)
		return -2;
	
	unosTrokuta= (TROKUT*)calloc(m, sizeof(TROKUT));
	if(unosTrokuta==NULL)
		return -3;
		
	
	int i;
	for(i=0; i<n; i++){
		fscanf(infile, "%f",&unosTocaka[i].x);      
		fscanf(infile, "%f", &unosTocaka[i].y);
		fscanf(infile, "%f", &unosTocaka[i].z);	
	}
		

	
	int ind1, ind2, ind3;
	for(i=0; i<m; i++){
		fscanf(infile, "%d", &ind1);
		fscanf(infile, "%d", &ind2);
		fscanf(infile,"%d", &ind3);
		unosTrokuta[i].vrh1= &unosTocaka[ind1];
		unosTrokuta[i].vrh2= &unosTocaka[ind2];
		unosTrokuta[i].vrh3= &unosTocaka[ind3];
	}
	
	float trenutniOpseg=0;
	for(i=0;i<m;i++){
		float varijabla= opseg(unosTrokuta[i].vrh1->x,unosTrokuta[i].vrh1->y, unosTrokuta[i].vrh1->z, 
		                        unosTrokuta[i].vrh2->x, unosTrokuta[i].vrh2->y, unosTrokuta[i].vrh2->z,
		                        unosTrokuta[i].vrh3->x, unosTrokuta[i].vrh3->y, unosTrokuta[i].vrh3->z);
		if(varijabla> trenutniOpseg){
			trenutniOpseg=varijabla;}
		
	}
	
	printf("Opesg je najveceg trokuta: %.2f ", trenutniOpseg);
	
	
	free(unosTocaka);
	free(unosTrokuta);
	
	unosTocaka=NULL;
	unosTrokuta=NULL;
	
	fclose(infile);
	
	return 0;
}

	float opseg(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y, float v3z){
		
		float dulj1str, dulj2str, dulj3str;
		float opseg;
		
		dulj1str= sqrt(pow(v2x-v1x, 2)+ pow(v2y-v1y, 2)+ pow(v2z-v1z, 2));
		dulj2str= sqrt(pow(v3x-v1x, 2)+ pow(v3y-v1y, 2)+ pow(v3z-v1z, 2));
		dulj3str= sqrt(pow(v3x-v2x, 2)+ pow(v3y-v2y, 2)+ pow(v3z-v2z, 2));
		
		opseg= dulj1str + dulj2str + dulj3str;
		
		return opseg;
}




//PRVOTNI KOJI NE VALJAJU
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct tocka{
	float x;
	float y;
	float z;
}TOCKA;

typedef struct trokut{
	TOCKA vrh1;
	TOCKA vrh2;
	TOCKA vrh3;
}TROKUT;

float opseg(float, float, float, float, float, float,float,float,float);

int main(){
	
	
	int n,m;    //broj tocaka-n , broj trokuta-m
	TOCKA *unosTocaka;
	TROKUT *unosTrokuta;
	
	
	FILE *infile= fopen("model.txt", "r");
	if(infile==NULL){
		printf("Neuspjelo otvaranje datoteke\n");
		return -1;
	}
	
	fread(&n, sizeof(TOCKA), 1, infile);   //za ucitati broj tocaka iz dok
	fread(&m, sizeof(TROKUT), 1, infile);
	
	
	unosTocaka= (float*)calloc(n, sizeof(float));
	if(unosTocaka==NULL)
		return -2;
	
	unosTrokuta= (TROKUT*)calloc(m, sizeof(TROKUT));
	if(unosTrokuta==NULL)
		return -3;
		
	
	int i;
	for(i=0; i<n; i++){
		fread(unosTocaka[i]->x, sizeof(float), 1, infile);      //prvo smo stavile sizeof(TOCKA),ali vjv ide float jer ulazimo u strukturu svaki zasebno element
		fread(TOCKA unosTocaka[i]->y, sizeof(float), 1, infile);
		fread(TOCKA unosTocaka->z, sizeof(float), 1, infile);	
	}
		
	for(i=0; i<m; i++){
		fread(unosTrokuta[i]->vrh1, sizeof(TOCKA), 1, infile);   //prvo uzele TROKUT
		fread(unosTrokuta[i]->vrh2, sizeof(TOCKA), 1, infile);
		fread(unosTrokuta[i]->vrh3, sizeof(TOCKA), 1, infile);	
	}
	
	
	//udaljenosti tocaka, pa dobijemo duljinu i onda trazimo najveci opseg
	
	
	float opseziTrok[];
	opseziTrok=(float*)calloc(m, sizeof(float));
	if(opseziTrok==NULL)
		return -4;
	
	for(i=0; i<m; i++){
		
		opseziTrok[i]=opseg(unosTrokuta[i].vrh1->x, unosTrokuta[i].vrh1->y, unosTrokuta[i].vrh1->z,
					unosTrokuta[i].vrh2->x, unosTrokuta[i].vrh2->y, unosTrokuta[i].vrh2->z,
					unosTrokuta[i].vrh3->x, unosTrokuta[i].vrh3->y, unosTrokuta[i].vrh3->z)	
		
	}
	
	float trenutniOpseg=0;
	for(i=0;i<m;i++){
		
		if(opseziTrok[i]> trenutniOpseg)
			trenutniOpseg=opseziTrok[i];
		
	}
	
	printf("Opesg je najveceg trokuta: %.2f ", trenutniOpseg);
	
	for(i=0;i<n;i++){
			free(unosTocaka[i]);
	}
	for(i=0,i<m;i++){
			free(unosTrokuta[i]);
			free(opseziTrok[i]);
	}
	
	free(unosTocaka);
	free(unosTrokuta);
	free(opseziTrok);
	
	unosTocaka=NULL;
	unosTrokuta=NULL;
	opseziTrok=NULL;
	
	return 0;
}

	float opseg(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y, float v3z){
		
		float dulj1str, dulj2str, dulj3str;
		float opseg;
		
		dulj1str= sqrt(pow(v2x-v1x, 2)+ pow(v2y-v1y, 2)+ pow(v2z-v1z, 2));
		dulj2str= sqrt(pow(v3x-v1x, 2)+ pow(v3y-v1y, 2)+ pow(v3z-v1z, 2));
		dulj3str= sqrt(pow(v3x-v2x, 2)+ pow(v3y-v2y, 2)+ pow(v3z-v2z, 2));
		
		opseg= dulj1str + dulj2str + dulj3str;
		
		return opseg;
}

----------------------------------------------
//Ja mislim da je ispravljen iako ne znam je li ispravan jer ne znam sto da upisem u file kako bi provjerrila tocnost

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct tocka{
	float x;
	float y;
	float z;
}TOCKA;

typedef struct trokut{
	TOCKA *vrh1;
	TOCKA *vrh2;
	TOCKA *vrh3;
}TROKUT;

float opseg(float, float, float, float, float, float,float,float,float);

int main(){
	
	
	int n,m;    //broj tocaka-n , broj trokuta-m
	TOCKA *unosTocaka;
	TROKUT *unosTrokuta;
	
	
	FILE *infile= fopen("model.txt", "r");
	if(infile==NULL){
		printf("Neuspjelo otvaranje datoteke\n");
		return -1;
	}
	
	fread(&n, sizeof(TOCKA), 1, infile);   //za ucitati broj tocaka iz dok
	fread(&m, sizeof(TROKUT), 1, infile);
	
	
	unosTocaka= (TOCKA*)calloc(n, sizeof(TOCKA));
	if(unosTocaka==NULL)
		return -2;
	
	unosTrokuta= (TROKUT*)calloc(m, sizeof(TROKUT));
	if(unosTrokuta==NULL)
		return -3;
		
	
	int i;
	for(i=0; i<n; i++){
		fscanf(infile, "%f",&unosTocaka[i].x);      //prvo smo stavile sizeof(TOCKA),ali vjv ide float jer ulazimo u strukturu svaki zasebno element
		fscanf(infile, "%f", &unosTocaka[i].y);
		fscanf(infile, "%f", &unosTocaka[i].z);	
	}
		
	for(i=0; i<m; i++){
		fscanf(infile, "%f%f%f", &unosTrokuta[i].vrh1->x,&unosTrokuta[i].vrh1->y,&unosTrokuta[i].vrh1->z);   //prvo uzele TROKUT
		fscanf(infile, "%f%f%f", &unosTrokuta[i].vrh2->x,&unosTrokuta[i].vrh2->y, &unosTrokuta[i].vrh2->z);
		fscanf(infile, "%f%f%f", &unosTrokuta[i].vrh3->x, &unosTrokuta[i].vrh3->y, &unosTrokuta[i].vrh3->z);	
	}
	
	
	//udaljenosti tocaka, pa dobijemo duljinu i onda trazimo najveci opseg
	
	
	float *opseziTrok;
	opseziTrok=(float*)calloc(m, sizeof(float));
	if(opseziTrok==NULL)
		return -4;
	
	for(i=0; i<m; i++){
		
		opseziTrok[i]=opseg(unosTrokuta[i].vrh1->x, unosTrokuta[i].vrh1->y, unosTrokuta[i].vrh1->z,
					unosTrokuta[i].vrh2->x, unosTrokuta[i].vrh2->y, unosTrokuta[i].vrh2->z,
					unosTrokuta[i].vrh3->x, unosTrokuta[i].vrh3->y, unosTrokuta[i].vrh3->z);	
		
	}
	
	float trenutniOpseg=0;
	for(i=0;i<m;i++){
		
		if(opseziTrok[i]> trenutniOpseg)
			trenutniOpseg=opseziTrok[i];
		
	}
	
	printf("Opesg je najveceg trokuta: %.2f ", trenutniOpseg);
	
	
	free(unosTocaka);
	free(unosTrokuta);
	free(opseziTrok);
	
	unosTocaka=NULL;
	unosTrokuta=NULL;
	opseziTrok=NULL;
	
	fclose(infile);
	
	return 0;
}

	float opseg(float v1x, float v1y, float v1z, float v2x, float v2y, float v2z, float v3x, float v3y, float v3z){
		
		float dulj1str, dulj2str, dulj3str;
		float opseg;
		
		dulj1str= sqrt(pow(v2x-v1x, 2)+ pow(v2y-v1y, 2)+ pow(v2z-v1z, 2));
		dulj2str= sqrt(pow(v3x-v1x, 2)+ pow(v3y-v1y, 2)+ pow(v3z-v1z, 2));
		dulj3str= sqrt(pow(v3x-v2x, 2)+ pow(v3y-v2y, 2)+ pow(v3z-v2z, 2));
		
		opseg= dulj1str + dulj2str + dulj3str;
		
		return opseg;
}







	
