#include "lv5-2-header.h"
#include <stdio.h>

//ovaj kod ne trebate mijenjati, vec nadopuniti lv5-2-func.c te lv5-2-header.h


int main(void)
{
  struct ARTIKL *max, artikli[100];
  int n;
  printf("Unesi n: ");
  scanf("%d", &n);
  
  ucitavanje(&artikli[0], n);
  max=najveci(&artikli[0], n);



  // ispis ne dirati, mora koristiti pokazivac max
  printf("REZULTATI:\n");
  printf("cijena: %.2f, kolicina: %d", max->cijena, max->kolicina);
  return 0;
}


#include<stdio.h>
#include "lv5-2-header.h"

void ucitavanje(struct ARTIKL artikli[], int n){
    int i;
for (i=0; i<n; i++)
 {
     scanf("%s", artikli[i].ime);
     scanf("%d", &artikli[i].kolicina);
     scanf("%f", &artikli[i].cijena);
 }
}
struct ARTIKL * najveci( struct ARTIKL artikli[], int n){

    int i,j;
    struct ARTIKL *max;
    float maxcijena;

    for (i=0; i<n; i++){
    
     if( artikli[i].cijena > maxcijena)
     {
        maxcijena=artikli[i].cijena;
        max=&artikli[i];
     }
    
    }
    return max;
}


#ifndef LV5_2_FUNC_H
#define LV5_2_FUNC_H

struct ARTIKL {
  char ime[30];
  int kolicina;
  float cijena;
};

void ucitavanje(struct ARTIKL artikli[], int n);
struct ARTIKL* najveci( struct ARTIKL artikli[], int n);



#endif
