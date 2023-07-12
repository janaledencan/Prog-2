#ifndef HEADER_LV6
#define HEADER_LV6

typedef struct tocka{
	int x,y,z;
}TOCKE;      //tu sam navela kao globalnu varijablu TOCKE[10], ali NE, koristimo ga samo kao naziv

typedef struct trokut{
	struct tocka *t1;
	struct tocka *t2;
	struct tocka *t3;
}TROKUTI;

void unos(int n, int m);
void popunjavanjeTocaka(int n, TOCKE *dot);
void definiranjeTocakaTrokuta(int m, TROKUTI *tr );
float opseg(TROKUTI *t);  //bilo kao argumenti TROKUTI t, TROKUTI t.t2, TROKUTI t.t3)
int trokutMaxOpsega(TROKUTI *trok, int m);

#endif
