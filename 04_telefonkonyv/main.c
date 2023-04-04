/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

struct diak_adat
{
  char nev[30];
  int halozatok;
  int oprendszerek;
  int analizis;
};

int beker(struct diak_adat* adat)
{
  printf("Nev: ");
  gets(adat.nev);
  if (strcmp(adat.nev, "") == 0)
  {
    return -1;
  }
  
  printf("Halozatok: ");
  scanf("%d", adat.halozatok);
  
  printf("Op. rendszerek: ");
  scanf("%d", adat.oprendszerek);
  
  printf("Analizis: ");
  scanf("%d", adat.analizis);

  return 0;
}


int main()
{
  #define MAXDIAK 10
  struct diak_adat diakok[MAXDIAK];
  int diakok_szama = 0;
  
  beker(&diakok[0]);

  printf(">%s<\n", diakok[0].nev);
  printf(">%d<", diakok[0].halozatok);
  printf(">%d<", diakok[0].oprendszerek);
  printf(">%d<", diakok[0].analizis);


  return 0;
}
