/******************************************************************************

Adatok nyilvántartása
  - Nevek
  - Jegyek (tárgyakhoz)

Mire van szükségünk:
  - Tárolnunk kell az adatokat
  - Adatok bekérése
  - Adatok listázása
  - ... Keresés valami alapján
  
Tervezés:
  - Tárolás: Együtt tudjunk tárolni többféle adatot: struktúra
  - Bekérés: Külön függvényben
  - Listázás: Külön függvény

*******************************************************************************/
#include <stdio.h>
#include <string.h>

struct diak_adat_t
{
  char nev[30];
  int matek;
  int prog1;
  int elektronika;
};

int beker(struct diak_adat_t* diak)
{
  char dummy;
  
  printf("Nev: ");
  gets(diak->nev);
  //if (strcmp(diak->nev, "") == 0)
  //{
  //  return -1;
  //}
  if (strlen(diak->nev) == 0)
  {
    return -1;
  }
  
  printf("Matek: ");
  scanf("%d", &(diak->matek));
  scanf("%c", &dummy);
  
  printf("Prog1: ");
  scanf("%d", &(diak->prog1));
  scanf("%c", &dummy);

  printf("Elektronika: ");
  scanf("%d", &(diak->elektronika));
  scanf("%c", &dummy);
  return 0;
}

int kiir(struct diak_adat_t diak)
{
  printf("-------------------------------\n");
  printf("    %s\n", diak.nev);
  printf("Matek:       %d\n", diak.matek);
  printf("Prog1:       %d\n", diak.prog1);
  printf("Elektronika: %d\n", diak.elektronika);
  printf("\n");
  printf("-------------------------------\n");
  
  return 0;
}

int main()
{
#define MAXDIAK 3

  struct diak_adat_t diakok[MAXDIAK];
  int kilep = 0;
  int diak_szamlalo = 0;
  int i;
  int legjobb_matek_jegy = 0;
  int legjobb_matek_index = 0;
  
  while (!kilep)
  {
    if (beker(&diakok[diak_szamlalo]) < 0)
    {
      kilep = 1;
      diak_szamlalo--;
    }
    diak_szamlalo++;
    if (diak_szamlalo >= MAXDIAK)
    {
      kilep = 1;
    }
  }

  for (i=0; i<diak_szamlalo; i++)
  {
    kiir(diakok[i]);
  }

  for (i=0; i<diak_szamlalo; i++)
  {
    if (diakok[i].matek > legjobb_matek_jegy)
    {
      legjobb_matek_jegy = diakok[i].matek;
      legjobb_matek_index = i;
    }
  }

  printf("A legjobb matekbol:\n");

  kiir(diakok[legjobb_matek_index]);

  return 0;
}

