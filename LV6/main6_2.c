/* 2. Napišite C program koji æe omoguæiti unos n<10 artikala u raèun.
 Unos implementirati u datoteci functions.c prema deklaraciji strukutra u myheader.c datoteci, pri èemu je primjer izvoðenja programa, 
 a ujedno i test case dan u komentaru u functions.c datoteci.
 Ispis raèuna implementiran je u program.c datoteci, te ga nije moguæe mijenjati.*/

#include<stdio.h>
#include "header6_2.h"

int main(){
	
	int n;
	void unos(n);
	
	ARTIKLI artikli[10];
	
	unosPodatakaArtikala(artikli, n);
	
	printf("REZULTATI:\n");
	racun (artikli, n);
	
	return 0;
}


