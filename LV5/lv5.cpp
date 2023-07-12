/*1. Napišite program koji æe obaviti množenje matrice cijelim brojem K, te njen ispis na
ekran u formatu („%d\t“), svaki red matrice u novi red. Datoteka program.c veæ je
dana, te nju ne trebate mijenjati. Prema primjeru 1 popunite funkcije koje nedostaju
u datotekama functions.c i myheader.h, a pozivaju se iz funkcije main() unutar
program.c datoteke.*/

#include<stdio.h>
#include"MyHeader.h"


int main()
{
	int i,j,n,k;
	int **matrica;
	
	printf("Unesite dimenziju matrice:\n");
	scanf("%d", &n);
	
	
	unos(matrica, n);
	
	printf("Unesite k:\n");
	scanf("%d", &k);
	
	mnozi (matrica, n, k);
	ispis (matrica, n);
	oslobodi(matrica, n);
	return 0;
}
