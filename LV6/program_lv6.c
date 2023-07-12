/*1. Napi�ite C program koji omogu�uje unos dva broja n i m. Omogu�iti unos n to�aka i m trokuta. 
Prona�i i ispisati trokut koji ima najve�i opseg. Opseg najve�eg trokuta ispisat �e se u funkciji main.
Pretpostaviti kako n i m ne�e biti ve�i od 10, ali nije potrebno u kodu testirati njihove veli�ine. */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header_lv6.h"

int main(){
	int n,m,in;

	TOCKE tck[10]; // jer ne smijemo globalnu varijablu radit u headeru
	TROKUTI trok[10];
	
	unos(n, m);
	popunjavanjeTocaka(n, tck);
	definiranjeTocakaTrokuta(m, trok);


	in=trokutMaxOpsega(trok, m);
	printf("%d\n", trok [in]);    //nez hoce li se moci tako ispisati jer je to struktura

	printf("%f\n", opseg(trok[in]); //opseg najve�eg trokuta

	return 0;
}
