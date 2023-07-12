/*1. Napišite C program koji æe omoguæiti upis dva kompleksna broja te ispisati njihov zbroj i razliku. Ispisati rezultate 
zbroja i razlike u formatu “%.3f, %.3f*i\n“.*/

#include<stdio.h>
#include<complex.h> //ne treba

int main()
{
	struct kompleksni{
		float realni;
		float imaginarni;
		
	} z1, z2;
	
	printf("Unesite realni i imaginarni dio kompleksnog br. z1:\n");
	scanf("%f", &z1.realni);
	scanf("%f", &z1.imaginarni);
	
	printf("Unesite realni i imaginarni dio kompleksnog br. z2:\n");
	scanf("%f", &z2.realni);
	scanf("%f", &z2.imaginarni);
	
	printf("REZULTATI:\n");
	printf("Zbroj kompleksnih br. je: %.3f + %.3f *i\n", z1.realni+z2.realni , z1.imaginarni+z2.imaginarni );
	printf("Razlika kompleksnih br. je: %.3f + %.3f *i", z1.realni-z2.realni , z1.imaginarni-z2.imaginarni );	
	
	return 0;
}



/*2. Napišite C program koji æe omoguæiti unošenje imena, prezimena, matiènog broja, prosjeka i datuma roðenja za n uèenika jednog razreda.
 Ispisati koji uèenik ima najbolji prosjek. (Uèenike upisati u polje od najviše 40 elemenata.)
Primjer oèekivanog ispisa rezultata:
REZULTATI:
Pero Peric
Ulazni podaci za svakog ucenika su formata:
Pero
Peric
3000103921082
2.12
1.1.1992.
gdje su vrijednosti redom: ime, prezime, matbr, prosjek i datum.
S obzirom na ulazne podatke formirajte strukturu.
Pripazite na velièinu podatka za matbr te format zapisa datuma (toèke nakon dana, mjeseca i godine)*/

#include<stdio.h>
								//IZBACI STRUCT IZ MAINA ,ALI PROBAJ U[40] OSTAVIT KAO GLOBALNU VARIJABLU
int main()
{
	struct datum{
		int dan;
		int mjesec;
		int godina;
	};
	
	struct ucenik{
		char ime [15];
		char prezime[15];
		char matbr[15];        //ne moze int jer je on premali br (oko 32 000) ,ali ne ni char vec long int
		float prosjek;
		struct datum b_day;
	}u[40];
	
	int n,i;
	
	printf("Unesite br. ucenika:\n");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		printf("Unesite ime:\n");
		scanf("%s", u[i].ime);
		
		printf("Unesite prezime:\n");
		scanf("%s", u[i].prezime);
		
		printf("Unesite maticni br.:\n");
		scanf("%s", &u[i].matbr);
		
		printf("Unesite prosjek:\n");
		scanf("%f", &u[i].prosjek);
		
		printf("Unesite datum rodenja:\n");
		scanf("%d.%d.%d.", &u[i].b_day.dan, &u[i].b_day.mjesec, &u[i].b_day.godina);
		
	}
	
	/*for(i=0; i<n; i++)
	{
	    printf("Ime ucenika je: %s\n",u[i].ime);
	    printf("Prezime ucenika je: %s\n",u[i].prezime);
	    printf("Maticni br. ucenika je: %d\n",u[i].matbr);
	    printf("Prosjek %s je: %f\n",u[i].ime, u[i].prosjek);
	    printf("Datum rodenja: %d.%d.%d.\n", u[i].b_day.dan, u[i].b_day.mjesec, u[i].b_day.godina);  
	}
	*/
	
	float max = u[0].prosjek;
	int indeks;
	
	for(i=0; i<n; i++)
	{
	  if(u[i].prosjek > max){
	     max=u[i].prosjek;
	     indeks=i;
	  }
	}
	
	printf("REZULTATI:\n");
	printf("\nUcenik s najvecim prosjekom %f je:%s.", max, u[indeks].ime);
	
	
	return 0;
}


/*3. Deklarirati strukturu stan koja ima èlanove: površina, cijena, adresa, energetski razred, klima ureðaj [1/0]. 
Omoguæiti korisniku unos podataka za željeni broj stanova (max. 20) u polje struktura. 
Ponavljati unos dokle god je željeni broj manji od 2, a veæi od 20.
Ispisati podatke o svim unesenim stanovima kod kojih je cijena po kvadratu manja od 900 eura i sve stanove kojima
je cijena veæa od 1100 eura po kvadratu, a nemaju klima ureðaj.
Ako nema takvih stanova ispisati tekst: „Niti jedan stan ne odgovara kriterijima.“, a ako ima takvih stanova
ispisati ih u formatu „adresa, cijena“ za svaki takav stan u novi red.*/

#include<stdio.h>

	struct stan{
		float povrsina;
		int cijena;
		char adresa[20];
		char energetskiRaz;
		int klima;
	};
	
	
int main()
{	
	int n,i;
	
	do{
		printf("Unesite zeljeni br stanova:\n");
		scanf("%d", &n);	
	}while(n<2 || n>20);
	
	struct stan stanovi[20];
	
	for(i=0; i<n; i++)
	{
		printf("Unesite povrsinu stana:\n");
		scanf("%f", &stanovi[i].povrsina);
		
		printf("Unesite cijenu stana:\n");
		scanf("%d", &stanovi[i].cijena);
		getchar();        //jer bez njega preskoci unos adrese s fgetsom
		
		printf("Unesite adresu:\n");
		fgets(stanovi[i].adresa, 20, stdin);      //bolji zapis ....fgets(stanovi[i].adresa, sizeof(stanovi[i].adresa), stdin);
		                                         //scanf("%s", stanovi[i].adresa); 
		
		printf("Energetski razred objekta je:\n");
		scanf(" %c", &stanovi[i].energetskiRaz);	//pazi na razmak !!!
		
		printf("Ima li objekt klimu (1 ili 0)?\n");
		scanf("%d", &stanovi[i].klima);	
		
	}
	
	int ima=0; 
	printf("REZULTATI:\n");
	
	for(i=0; i<n; i++)
	{
		if((stanovi[i].cijena / stanovi[i].povrsina) < 900){
			ima=1;
			printf("\nStan kojemu je cijena manja od 900 eura je  %s,a njegova cijena je %d eura.", stanovi[i].adresa, stanovi[i].cijena );
		}
				
		else if ((stanovi[i].cijena / stanovi[i].povrsina)  > 1100 && stanovi[i].klima==0){
			ima=1;
			printf("\nStan kojemu je cijena veca od 1100 eura i nema klima uredaj je  %s,a njegova cijena je %d eura.", stanovi[i].adresa, stanovi[i].cijena );
		}		
	}
	
	if(ima==0)
		printf("Niti jedan stan ne odgovara kriterijima.");
	
	
	
	return 0;
}



//Primjer zad.

#include<stdio.h>

struct number 
{ 
	float x; 
}; 

int main() 
{ 
	struct number n1,n2,n3; 
	n1.x=4; 
	n2.x=3; 
	n3.x=n1.x+n2.x; 

printf("%f", n3.x);

	return 0; 
} 

























