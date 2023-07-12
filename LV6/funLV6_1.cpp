//ovdje pisete implementaciju potrebnih funkcija. 
//ukoliko zelite koristiti dodatne funkcije, njihove deklaracije
//mozete navesti u datoteci zaglavlja. 
//Funkcija unesiPodatkeRacuna je obvezna.

#include<stdio.h>

void unesiPodatkeRacuna(Racun *racun){
	fgets(racun->kupac, 20, stdin );
	fgets(racun->prodavac, 20, stdin );
	scanf("%d", &racun->brArti);
	
	float iznos=0;
	int i;
	
	for(i=0; i<racun->brArti; i++){
		fgets(racun->artikli[i].ime, 20, stdin);
		scanf("%f", &racun->artikli[i].cijena);
		scanf("%d", &racun->artikli[i].kolicina);
		iznos+=racun->artikli[i].cijena * racun->artikli[i].kolicina;
	}
		racun->ukupanIznos=iznos;
}

  void ispisRacuna(Racun *racun){
  	
  }

/*
Primjer kako bi izgledalo izvodjenje programa, 
prema ovom redosljedu trebate upisivati podatke u strukture.
Ispis racuna se izvodi sam. 

Unesi ime kupca: Petar Kupcevic 
Unesi ime prodavaca: Ivan Prodavacevic
Unesi broj artikala: 4

Unesi ime artikla: Pivo Osjecko 0.5l
Unesi cijenu artikla: 5.99
Unesi kolicinu pojedinog artikla: 120

Unesi ime artikla: Brandy Badel 1l
Unesi cijenu artikla: 69.99
Unesi kolicinu pojedinog artikla: 5
Unesi ime artikla: Vino Crno Ribar 1l
Unesi cijenu artikla: 12.99
Unesi kolicinu pojedinog artikla: 55
Unesi ime artikla: Coca Cola 2l
Unesi cijenu artikla: 12.99
Unesi kolicinu pojedinog artikla: 20

REZULTATI:
Kupac: Petar Kupcevic
Prodavac: Ivan Prodavacevic
-----------------------------
Artikli: 
rb   naziv                    kolicina    cijena    ukupno
1    Pivo Osjecko 0.5l         120        5.99       718.80
2    Brandy Badel 1l           5          69.99      349.95
3    Vino Crno Ribar 1l        55         12.99      714.45
4    Coca Cola 2l              20         12.99      259.80

Ukupan iznos racuna: 2043.00
*/

---------------------------------------------------

#include<stdio.h>
#include"headerLV6_1"
#include<math.h>


void unosTocaka(TOCKA *tocke, int n){
	int i;
	for(i=0; i<n; i++){
		scanf("%f", &tocke[i].x);
		scanf("%f", &tocke[i].y);
		scanf("%f", &tocke[i].z);
		
	}
}

void unosTrokut(TROKUT *trokuti, TOCKA *tocke, int m){
	int i;
	int ind1, ind2, ind3;
	
	for(i=0; i<m; i++){
		scanf("%d%d%d", &ind1, &ind2, &ind3);
		trokuti[i].t1= &tocke[ind1];
		trokuti[i].t2= &tocke[ind2];
		trokuti[i].t3= &tocke[ind3];	
	}
	
}

float udaljenost(float x1, float x2, float y1, float y2, float z1, float z2 ){
	sqrt(pow(x2-x1,2)+ pow(y2-y1,2)+ pow(z2-z1, 2));
}

float maxOpseg(TROKUT *trokuti, int m){
	float max=0;
	float topseg=0;
	
	for(i=0; i<m; i++){
		topseg+=udaljenost(trokuti[i]->t1.x, trokuti[i]->t2.x, trokuti[i]->t1.y, trokuti[i]->t2.y, trokuti[i]->t1.z, trokuti[i]->t2.z ); 
		topseg+=udaljenost(trokuti[i]->t2.x, trokuti[i]->t3.x, trokuti[i]->t2.y, trokuti[i]->t3.y, trokuti[i]->t2.z, trokuti[i]->t3.z ); 
		topseg+=udaljenost(trokuti[i]->t1.x, trokuti[i]->t3.x, trokuti[i]->t1.y, trokuti[i]->t3.y, trokuti[i]->t1.z, trokuti[i]->t3.z ); 
		if(topseg>max){
			max=topseg;
		}
	}
	return max;
	
}























