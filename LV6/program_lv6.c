/*1. Napišite C program koji omoguæuje unos dva broja n i m. Omoguæiti unos n toèaka i m trokuta. 
Pronaæi i ispisati trokut koji ima najveæi opseg. Opseg najveæeg trokuta ispisat æe se u funkciji main.
Pretpostaviti kako n i m neæe biti veæi od 10, ali nije potrebno u kodu testirati njihove velièine. */

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

	printf("%f\n", opseg(trok[in]); //opseg najveæeg trokuta

	return 0;
}
