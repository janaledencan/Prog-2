#ifndef HEADERLV6_1
#define  HEADERLV6_1

typedef struct artikl{
	char ime[20];
	float cijena;
	int kolicina;
	
}Artikl;

typedef struct racun{
	char kupac[20];
	char prodavac[20];
	Artikl artikli[10];
	int brArti;
	float ukupanIznos;
}Racun;

void unesiPodatkeRacuna(Racun *racun);
void ispisRacuna(Racun *racun);
#endif

-----------------------------------------------------------------------

#ifndef HEADER6_1
#define HEADER6_1

typedef struct tocka{
	float x,y,z;
}TOCKA;


typedef struct trokut{
	struct tocka *t1;
	TOCKA *t2;
	TOCKA *t3;
}TROKUT;

void unosTocaka(TOCKA *tocke, int n);
void unosTrokut(TROKUT *trokuti, TOCKA *tocke, int m);
float udaljenost(float x1, float x2, float y1, float y2, float z1, float z2 );
float maxOpseg(TROKUT *trokuti, int m);





#endif











