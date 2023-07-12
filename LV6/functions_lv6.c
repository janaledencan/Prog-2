#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header_lv6.h"

void unos(int n, int m){
	printf("Unesite n (br.tocaka) i m (br. trokuta):\n");
	scanf("%d %d", &n,&m);
}

void popunjavanjeTocaka(int n, TOCKE *dot){
	int i;
	printf("Unesite vrijednosti x,y,z kordinata tocaka:\n");
	for(i=0; i<n;i++){
		scanf("%d", &(dot[i].x));
		scanf("%d", &(dot[i].y));
		scanf("%d", &(dot[i].z));		
	}
}	

void definiranjeTocakaTrokuta(int m, TROKUTI *tr ){
	int i;
	printf("Unesite tocake trokuta:\n");
	for(i=0; i<m;i++){
		scanf("%d", &(tr[i].t1));
		scanf("%d", &(tr[i].t2));
		scanf("%d", &(tr[i].t3));		
	}
}	

float opseg(TROKUTI *t){     //racunanje opsega za svaki trokut
	float u1, u2, u3; 
	float opseg;
	
	u1 = sqrt(pow(t.t2->x-t.t1->x,2) + pow(t.t2->y-t.t1->y,2) + pow(t.t2->z-t.t1->z,2));  //duljina prve stranice trokuta
	u2 = sqrt(pow(t.t3->x-t.t2->x,2) + pow(t.t3->y-t.t2->y,2) + pow(t.t3->z-t.t2->z,2)); 
	u3 = sqrt(pow(t.t3->x-t.t1->x,2) + pow(t.t3->y-t.t1->y,2) + pow(t.t3->z-t.t1->z,2));   
	
	opseg= u1+u2+u3;
	return opseg; 
}

int trokutMaxOpsega(TROKUTI *trok, int m){
		int i;
		float oT;
		float max= 0;
		int index;
		
		for(i=0; i<m; i++){
			oT= opseg(trok[i]);  //spremamo opseg za svaki trokut
			if(oT>max){
				max=oT;
				index=i;
			}			
		} 
		return index;  //Pronaæi i ispisati trokut koji ima najveæi opseg
	}
	
	
	
	
	//sa sata
	
	void unesiTocke(Tocka* tocke, int n){
    int i;
    for(i=0; i<n; i++){
        scanf("%F", &(*(tocke+i)).x);
        scanf("%f", &(*(tocke+i)).y);
        scanf("%f", &(*(tocke+i)).z);
    }
}


void unesiTrokute(Trokut* trokuti, Tocka* tocke, int m){
   
    int i;
    int ind1, ind2, ind3;
    for (i = 0; i < m; i++) {
    printf("Unesite indekse\n");
    scanf("%d %d %d", &ind1, &ind2, &ind3);
    
    (trokuti + i)->t1 = &tocke[ind1];
    (trokuti + i)->t2 = &tocke[ind2];
    (trokuti + i)->t3 = &tocke[ind3];
    
    }
}

float udaljenost(float x1, float x2, float y1, float y2, float z1, float z2){
   return sqrt(pow(x2-x1, 2)+ pow(y2-y1, 2)+ pow(z2-z1,2));
}

float pronadjiNajveciOpseg(Trokut* trokuti, int m){
    
    float topseg;
    float max=0;
    int i;
    
    for(i=0; i<m; i++){
        topseg=0;
        topseg+= udaljenost((trokuti+i)->t1->x , (trokuti+i)->t2->x, (trokuti+i)->t1->y, (trokuti+i)->t2->y , (trokuti+i)->t1->z, (trokuti+i)->t2->z);
        topseg+= udaljenost((trokuti+i)->t2->x , (trokuti+i)->t3->x, (trokuti+i)->t2->y, (trokuti+i)->t3->y , (trokuti+i)->t2->z, (trokuti+i)->t3->z);
        topseg+= udaljenost((trokuti+i)->t1->x , (trokuti+i)->t3->x, (trokuti+i)->t1->y, (trokuti+i)->t3->y , (trokuti+i)->t1->z, (trokuti+i)->t3->z);
        
        if(topseg>max){
            max=topseg;
        }
    }
    return max;
    
}

---------------------------------------------------------------
//2. sa lv6

void unesiPodatkeRacuna(Racun *r) {
    
    int i;
    float iznos=0;
    
    
    fgets(r->kupac,50,stdin);
    fgets(r->prodavac,50,stdin);
    scanf("%d", &r->broj_artikala);
    
    for(i=0; i< r->broj_artikala; i++){getchar();
        scanf("%49[^\n]", (r->artikli+i)->naziv);
        scanf("%f",&(r->artikli+i)->cijena);
        scanf("%d",&(r->artikli+i)->kolicina);
        iznos+= ((r->artikli+i)->cijena * (r->artikli+i)->kolicina);
    }
    r->ukupan_iznos=iznos;
