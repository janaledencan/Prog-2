#include<stdio.h>
#include "headerLV6_1.h"


  int main(void)
{
  int n, m;
  Racun racun;

  unesiPodatkeRacuna(&racun);

  ispisRacuna(&racun);

	return 0;
}


-------------------------------------------------

#include<stdio.h>
#include"headerLV6_1"
#include<math.h>


int main(){
	
	int n,m;
	float opseg;
	
	printf("Unesite br. n i m:\n");
	scanf("%d%d", &n,&m);
	
	TOCKA tocke[10];
	TROKUT trokuti[10];
	
	unosTocaka(tocke, n);
	unosTrokut(trokuti, tocke, m);
	opseg= maxOpseg(trokuti, m);

	printf("%f", opseg);
	
	return 0;
}



















