//Pretvorite dva sluèajna cijela broja u 16-bitni binarni zapis. Jedan treba biti pozitivan, jedan negativan.

// pokazivace uvest ili zauzet memoriju ili premjestit printf u main !!!!!!


#include<stdio.h>
#include<time.h>

int br1, br2;

void DecimalIntToBinary(int n){
    int binaryNumber[16];
    int flag = 0;
    int firstOne = 0;
    int i;

    if(n < 0) 
		flag = 1;

    //popunjavanje
    for(i = 15; i >= 0; i--){
        binaryNumber[i] = abs(n) % 2;
        n /= 2;
    }

    //dvojni komplement
    for( i = 15; i >= 0; i--){
        if(flag == 1){
            if(firstOne == 1){
                if(binaryNumber[i] == 0) 
					binaryNumber[i] = 1;
					
                else binaryNumber[i] = 0;
            }
        }

        if(binaryNumber[i] == 1) 
			firstOne = 1;
    }

    //ispis
    for( i = 0; i < 16; i++){
        if(i % 8 == 0) printf(" ");
        printf("%d", binaryNumber[i]);
    }
}

int main()
{
	srand((unsigned)time(NULL));
	
	//za pozitivan br.	
	do{
		br1= 1+ rand() % (800);
	}while(br1 < 0);
	
	printf("%d\n", &br1);
	
	
	//za negativan br.
	
	do{
		br2= rand() % 1;
	}while(br2 > 0);
		
	printf("%d\n", &br2);
	
		
   DecimalIntToBinary(br1);
   printf("\n");
  // DecimalIntToBinary(br2);
   
   return 0;
}



//2. Pretvorite dva sluèajna realna broja u binarni zapis u 32-bitnom registru za realne brojeve. Brojevi moraju imati barem 3 decimalna mjesta.

#include<stdio.h>
#include<math.h>

int main()
{
	srand((unsigned)time(NULL));
	
	float br;
	int p = 0;
	int E;
	int binary[32];
	int e[8];

	if(br >= 2)
	{
		while(br > 2)
		{
			br/=2;
			p++;	
		}
		E = p + 127;
		br/= pow(2,p);
		
		//mantisa
		F= (float)br/ 2;
	}
	
	else if(0 <br< 1)
	{
		while(br<1)
		{
			br*= 2;
			p++;
		}
		E = -p + 127;
	}
	
	else if(1<=br<2)
	{
		p = 0;
		E = 127;
	}
	
	//pretvaranje eksponenta u binarni zapis
	for(i=31; i>=24; i-- )
	{
		e[i]= E % 2;
		e[i]*=2;
		e[i]/=10;
	}

	
	
	
	
   
   return 0;
}

/* 3. Napisati C program koji s tipkovnice uèitava 16-bitni binarni broj kao niz znakova (0 i 1) u znakovno polje.
 Potrebno je izraèunati i na ekran ispisati dekadski zapis uèitanog cijelog binarnog broja. */
 
 
 #include<stdio.n>
 #include<>
 
 int main()
 {
 	char binary[16];
 	int i,br,f=0;
 	
 	for(i=0; i<16; i++)
	 {
	 	do{
	 		scanf("%s", &binary[i]);
		 }while(binary[i] != '1' || binary[i] != '0');
	 }
 	
 	
 	if(binary[0]== '1')
 	{
 		f=1;
 		for(i=0; i<16; i++){
 			if(binary[i]== '0')
 				binary[i]= 1;
 			else{
 				binary[i]= 0;
			 }
		 printf("%d", &binary[i]);
		}
		 
	 }
 	
 	else{
 		for(i=0; i<16; i++){
 			br= binary[i] + pow(2, 16-i);
		 } 
		 printf("%d", &br);
	 }
 	
 	
 	return 0;
 }
 
 
 /*5. Napisati C program koji æe korisniku omoguæiti unos realnog broja koji je veæi ili jednak 2 s barem
tri decimalna mjesta i pomoæu standarda IEEE 754 jednostruke preciznosti pretvoriti broj u binarni
ekvivalent popunjavanjem cjelobrojnog polja duljine 32 elementa. Pripaziti na postupak pretvorbe
kada je broj negativan i kada je pozitivan. */


 
 /*9. Napisati C program koji æe korisniku omoguæiti unos realnog broja koji je veæi od 0 i manji od 1 s
barem tri decimalna mjesta i pomoæu standarda IEEE 754 dvostruke preciznosti pretvoriti broj u
binarni ekvivalent popunjavanjem cjelobrojnog polja duljine 64 elementa. Pripaziti na postupak
pretvorbe kada je broj negativan i kada je pozitivan.*/

#include<stdio.h>
#include<conio.h>

/*. Ako je apsolutna vrijednost broja veæa od 0 i manja od 1:
a. Broj se množi s 2 tako i svaki sljedeæi rezultat množenja se množi s 2 sve dok je rezultat
množenja manji od 1 i pamti se broj množenja (be).
b. Broj se dijeli s 2

c. U dio za eksponent upisuje se vrijednost ?? = (-???? + 1023)(10)
, u binarnom zapisu(11 bitova).
d. Mantisa se raèuna tako da se uzme decimalni dio rezultata iz koraka b i pomnoži se s
2, tako i svaki sljedeæi rezultat množenja se množi s 2, a cjelobrojni dio rezultata se
upisuje u dio registra od 52. bita na desno.*/

int main()
{
	float br, f;
	int p[64], be, ostatak, E;
	
	printf("Unesite realni br. s 3 decimalna mjesta:");
	
	do{
		scanf("%.3f",&br);
	}while(br<=0 || br>=1);   
	
	//predznak	
	if(br<0)
	{
		p[0]=1;
	}
	else{
		p[0]=0;
	}
	
	
	do{
		br *= 2;
		be++;
	}while(br<1);
	
	//decimalni dio
	f = br* pow(2, be);	
	f -= 1;
	
	E = -be + 1023;
	
	//pretvorba E u binarni br
	for(i=11; i>0 ; i--)
	{
		ostatak= E % 2;
		E /= 2;
		p[i]= ostatak;	
	}
	
	//mantisa
	for(i=12; i<64; i++){
		p[i]=f*2;
		if(f>1)
			f=f-1;
	}
	
	for(i=0; i<64; i++)
		printf("%d", p[i]);
	
	
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




