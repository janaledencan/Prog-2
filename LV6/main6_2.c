/* 2. Napi�ite C program koji �e omogu�iti unos n<10 artikala u ra�un.
 Unos implementirati u datoteci functions.c prema deklaraciji strukutra u myheader.c datoteci, pri �emu je primjer izvo�enja programa, 
 a ujedno i test case dan u komentaru u functions.c datoteci.
 Ispis ra�una implementiran je u program.c datoteci, te ga nije mogu�e mijenjati.*/

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


