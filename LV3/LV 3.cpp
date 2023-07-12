/*1. Napisite C program koji za unos broja izmedu 1 i 12 ispisuje pripadajuci mjesec slovima, a ukoliko je unesen broj veci od 12 ili manji od 1, 
ispisuje se "Nekorektan broj mjeseca". Za inicijalizaciju imena mjeseci koristiti polje pokazivaca.*/
//VALJAJU OBA

#include<stdio.h>

int main(){
	
	int n;
	char *p[]={"Sijecanj","Veljaca","Ozujak","Travanj","Svibanj","Lipanj","Srpanj","Kolovoz","Rujan","Listopad","Studeni","Prosinac"};
	
	printf("Unesite broj mjeseca koji zelite da se ispise:\n");
	scanf("%d", &n);
	printf("REZULTATI:\n");
	
		switch(n){
		case 1: printf("%s", p[0]); break;
		case 2: printf("%s",p[1]); break;
		case 3: printf("%s", p[2]); break;
		case 4: printf("%s", p[3]); break;
		case 5:  printf("%s", p[4]); break;
		case 6:  printf("%s", p[5]); break;
		case 7:  printf("%s", p[6]); break;
		case 8:  printf("%s", p[7]); break;
		case 9:  printf("%s", p[8]); break;
		case 10: printf("%s", p[9]); break;
		case 11: printf("%s", p[10]); break;
		case 12: printf("%s", p[11]); break;
		
		default: printf("Nekorektan broj mjeseca.");
	}	
		
	return 0;
}

//funkcionira i kad se stavi u scanf("%c", &n) i u case-ovima se stave kao charovi('1'),ali vrijedi samo zajednoznamenkaste br.
// jer su oni jedan char pa ne valja za 10, 11 i 12
// nee bi tako moglo ici jer izraz test pod switch(test) mora biti cjelobrojan!!!
-----------------------------------------------------------------
#include<stdio.h>

int main(){

	int n;
	char *mjeseci[]={"Sijecanj","Veljaca","Ozujak","Travanj","Svibanj","Lipanj","Srpanj","Kolovoz","Rujan","Listopad","Studeni","Prosinac"};
	
	scanf("%d", &n);
	
	printf("REZULTATI:\n");
	
	if(n>=1 && n<=12)
		printf("%s", mjeseci[n-1]);
		
	else{
		printf("Nekorektan br. mjeseca.");
	}	

return 0;
}

/*2. Napravite funkciju koji ce vratiti najveci element matrice. 
U glavnom dijelu programa treba unijeti matricu cijelih brojeva reda nÅ x m (2<=n<=5, 2<=m<=8) i ispisati rezultat u formatu %d \t */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int maxelement(int k, int l, int m[][8])   //int m[][8] prva dimenzija polja(redovi)moze ostati prazna,
{                                          //ali druga dimenzija mora imati vrijednost(BROJ !)
	int i,j;
	int max=0;
	
	for(i=0; i<k; i++){
		for(j=0; j<l; j++){
			if(m[i][j]> max){
				max= m[i][j];
			}
		}
	}
	return max;
}

int main(){
	
	int n,m,i,j;
	srand((unsigned)time(NULL));
	int matrica[5][8];
	int (*p)[8];
	
	p = matrica;
	
	printf("Unesite n i m dimenzije matrice:\n");
	do{
		printf("Unesite n:\n");
		scanf("%d", &n);
	}while(n<2 || n>5);
	
	do{
		printf("Unesite m:\n");
		scanf("%d", &m);
	}while(m<2 || m>8);
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			matrica [i][j] = 2 + rand()%(100-2+1);
		}
	}
	
	for(i=0; i<n; i++){
	    for(j=0; j<m; j++){
	        printf("%d\t",matrica[i][j]);
	    }
	    printf("\n");
	}  //za provjeru
	
	printf("REZULTATI:\n");
	printf("\n %d",maxelement(n,m, matrica));
	
	return 0;
}


//2.cijelom pokazivackom notacijom

#include<stdio.h>
#include<stdlib.h>
int najveci (int **a, int n, int m);

int main(){
        // a je matrica, m i n su dimenzije matrice
        int **a, m, n;
        int i,j;
        
        // zbog testinih slucajeva potrebno je prvo unijeti velicinu n, a tek zatim m
        do{
            scanf("%d",&n);
            //upis i provjera scanf-a za n
        }while(n<2 || n>5);//uvjeti za n
        do{
            //upis i provjera scanf-a za m
            scanf("%d",&m);
        }while(m<2 || m>8);//uvjeti za m
        
        //ovdje ide vas kod za upis dimenzija matrice i elemenata u matricu
        //pogledajte primjer 3 u LV
        
        a=(int**)calloc(n, sizeof(int*));
        if(a==NULL)
            return 1;
            
        for(i=0; i<n;i++){
            *(a+i)=(int*)calloc(m, sizeof(int));
            
            if(*(a+i)==NULL)
                return 1;
        }
        
        for(i=0; i<n;i++){
            for(j=0; j<m; j++){
                scanf("%d",&a[i][j]);
            }
        }
            
            
        
        //Ispis rezultata
        printf("\nREZULTATI:\n");
        printf("%d", najveci (a,n,m));
        
        for(i=0; i<n;i++){
            free(*(a+i));
        }
        free(a);
        
        a=NULL;
        
        return 0;
}
int najveci (int **a, int n, int m){
        //ova funkcija treba vratiti vrijednost najveceg elementa u predanoj matrici
       //ovdje ide vas kod
       int max=0;
       int i,j;
       
       for(i=0; i<n; i++){
           for(j=0;j<m;j++){
               if(*(*(a+i)+j) > max)
                    max= *(*(a+i)+j);
           }
       }
       return max;
}


/*3. Napravite funkciju koji ce omoguciti mnozenje matrice cijelih brojeva i cijelog broja k te vratiti pokazivac na matricu umnoska. 
U glavnom dijelu programa treba unijeti matricu reda n Åx m (2<=n<=10, 2<=m<=10) i jedan cijeli broj k. Ispisati dobivenu matricu po redcima u formatu "Å%d\tÅ".*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int mnozi (int **a,int **matu, int k, int n, int m);

int main()
{
	 int n,m,i,j,k;
	 
	 srand((unsigned)time(NULL));
	 
	do{
		printf("Unesite br n:");	
	 	scanf("%d",&n);
	} while(n<2||n>10);
	
	do{
	  	printf("Unesite br m:");	
	 	scanf("%d",&m);
	  }while(m<2||m>10);
	 
	  printf("Unesite br k:");	
	 	scanf("%d",&k);
	
	int **matA;
	int **matu;
	
	//Din. aloc. mem.
	matA = (int**)malloc(n*sizeof(int*));
	for (i = 0; i < n; i++)
		*(matA + i) = (int*)malloc(m*sizeof(int));

	 for(i=0;i<n;i++){
	 	for(j=0;j<m;j++){
	 	
	 		matA[i][j]=rand()%451;
		 }
	 }
	 
	 //Din. alociranje za matricu umnoska
	matu = (int**)malloc(n*sizeof(int*));
	for (i = 0; i < n; i++)
		*(matu + i) = (int*)malloc(m*sizeof(int));
		
	 
	 for(i=0;i<n;i++){
	 	for(j=0;j<m;j++){
	 	    printf("%d\t",matA[i][j]);
	 	}
	 	printf("\n");
	 }
	 	    mnozi(matA,matu,k,n,m);
	
	printf("REZULTATI:\n");
	
	 for(i=0;i<n;i++){
	 	for(j=0;j<m;j++){
	 		printf("%d\t",matu[i][j]);
	    }
	    printf("\n");
	  }
 return 0;	 
}

int mnozi (int **a,int **matu, int k, int n, int m){
	
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matu[i][j]=a[i][j]*k;
		}
	}
}




























