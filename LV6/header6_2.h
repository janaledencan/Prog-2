#ifndef HEADER6_2_H
#define HEADER6_2_H

typedef struct artikl{
	
	char ime[40];
	float cijena;
	long int barKod;
	
} ARTIKLI;

void unos (int n);
void unosPodatakaArtikala (ARTIKLI *art, int n );
void racun (ARTIKLI *art, int n);

#endif
