
//primjer iz priloga

#include <stdio.h>
#include <math.h>
#define N 10

struct tocka {
 float x;
 float y;
 float z;
 };
 struct trokut {
 struct tocka *t1;
 struct tocka *t2;
 struct tocka *t3;
 };

 float len3d(float x, float y, float z) {
 return sqrt( x*x + y*y + z*z);
 }

 int main(void)
 {
   struct tocka tocke[100];
   struct trokut trokuti[100];
   struct trokut *max;
  int i;
  int ind1, ind2, ind3;
  float Dtrenutni=0, Dmax=0;

 for (i = 0; i < N; i++) {
 printf("Upisi x, y i z za %d tocku: ", i+1);
 scanf("%f%f%f", &tocke[i].x, &tocke[i].y, &tocke[i].z);
  }
 for (i = 0; i < N; i++) {
printf("Upisi indexe tocaka za %d trokut: ", i+1);
scanf("%d%d%d", &ind1, &ind2, &ind3);
 trokuti[i].t1 = &tocke[ind1];
 trokuti[i].t2 = &tocke[ind2];
 trokuti[i].t3 = &tocke[ind3];
 }

 for (i = 0; i < N; i++) {
 Dtrenutni = 0;
 Dtrenutni += len3d( trokuti[i].t1->x, trokuti[i].t1->y, trokuti[i].t1->z);
 Dtrenutni += len3d( trokuti[i].t2->x, trokuti[i].t2->y, trokuti[i].t2->z);
 Dtrenutni += len3d( trokuti[i].t3->x, trokuti[i].t3->y, trokuti[i].t3->z);
 Dtrenutni /= 3;
 if (Dtrenutni > Dmax)
 {
 Dmax = Dtrenutni;
 max = &trokuti[i];
 }
 }

 printf("Najudaljeniji trokut je udaljen %.2f od ishodišta,\n", Dmax);
 printf("a njegove koordinate su:\n");
 printf("(%.2f, %.2f, %.2f)\n", max->t1->x, max->t1->y, max->t1->z);
 printf("(%.2f, %.2f, %.2f)\n", max->t2->x, max->t2->y, max->t2->z);
 printf("(%.2f, %.2f, %.2f)\n", max->t3->x, max->t3->y, max->t3->z);

 return 0;
 }


/*1.zad. Napišite C program koji omoguæuje unos dva broja n i m. Omoguæiti unos n toèaka i
m trokuta. Pronaæi i ispisati trokut koji ima najveæi opseg. Opseg najveæeg trokuta
ispisati u formatu (“%.2f\n“). Pretpostaviti da n i m neæe biti veæi od 10, ali nije
potrebno u kodu testirati njihove velièine.*/
 
 #include<stdio.h>
 #include<math.h>
 
 struct tocka{
 	float x;
 	float y;
 	float z;
 };

struct trokut{
	struct tocka *t1;
	struct tocka *t2;
	struct tocka *t3;
};

float duljina(float x1,float x2,float y1,float y2,float z1,float z2)
{
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
	
}
int main(){
	
	int n,m,i;
	do{
		printf("Broj tocaka:\n");
		scanf("%d",&n);
	}while(n<0 || n>10);
	
	do{
		printf("Broj trokuta:\n");
		scanf("%d",&m);
	}while(m<0 || m>10);
	
	struct tocka tocke[100];
	struct trokut trokuti[100];
	
	float maxo=0, topseg=0;
	
	for(i=0;i<n;i++){ //unos kordinata tocaka
		
		scanf("%f\n",&tocke[i].x);
		scanf("%f\n",&tocke[i].y);
		scanf("%f\n",&tocke[i].z);
	}
	
	int indeks1,indeks2,indeks3;
	
	for(i=0;i<m;i++) //unos tocaka trokuta
	{
		scanf("%d%d%d",&indeks1,&indeks2,&indeks3);
		
		trokuti[i].t1=&tocke[indeks1];
		trokuti[i].t2=&tocke[indeks2];
		trokuti[i].t3=&tocke[indeks3];
		
	}
	struct trokut *max;
	for(i=0;i<n;i++){
		topseg=0;
		topseg+=duljina(trokuti[i].t1->x,trokuti[i].t1->y,trokuti[i].t1->z,trokuti[i].t2->x,trokuti[i].t2->y,trokuti[i].t2->z);
		topseg+=duljina(trokuti[i].t2->x,trokuti[i].t2->y,trokuti[i].t2->z,trokuti[i].t3->x,trokuti[i].t3->y,trokuti[i].t3->z);
		topseg+=duljina(trokuti[i].t3->x,trokuti[i].t3->y,trokuti[i].t3->z,trokuti[i].t1->x,trokuti[i].t1->y,trokuti[i].t1->z);
	    
	    
	    if(topseg>maxo)
	    {
	    	maxo=topseg;
	    	max=&trokuti[i];
		}
	}
	
	printf("%.2f\n",maxo);
	
	
	
	
	return 0;
}



/*2.Napišite C program koji æe u polje struktura artikl omoguæiti unos n<10 artikala
(struktura ima èlanove ime, cijena i kolicina). U pokazivaè max spremiti memorijsku
adresu najskupljeg artikla. Nakon teksta REZULTATI: ispisati cijenu i kolièinu
najskupljeg artikla u formatu (“cijena: %.2f, kolicina: %d“).   */

#include<stdio.h>

struct artikl{
	char ime[10];
	float cijena;
	int kolicina;
};

int main(){
	
	struct artikl *max;
	
	struct artikl artikli[10];
	max=&artikli[0];
	
	int n,i;
	do{
	    printf("Unesite n (broj artikala):\n");
	    scanf("%d",&n);
	}while(n>10);
	
	for(i=0;i<n;i++)
	{
		scanf("%s",artikli[i].ime);
		scanf("%f",&artikli[i].cijena);
		scanf("%d",&artikli[i].kolicina);
	}
	
	for(i=0;i<n;i++)
	{
		if(artikli[i].cijena>max->cijena){
		
			max=&artikli[i];
		}
			
	}
	
	printf("REZULTATI:\n");
	printf("cijena: %.2f, kolicina: %d",max->cijena,max->kolicina);
	
	
	return 0;
}
































