/******************************************************************************

Mi matekból az átlag?
Ki a legjobb villanyból?
Ki a legrosszabb prog1-ből?
Melyik jegyből hány darab van összesen?

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define BEFILE "be.txt"
#define MAXJEGYEK 10

struct jegyek_t
{
  char vezeteknev[40];
  char keresztnev[40];
  int matek, prog1, villanytan;
};

int main()
{
  FILE* befile;
  char sor[40];
  int szamlalo = 0;
  
  struct jegyek_t jegyek[MAXJEGYEK];
  
  char vezeteknev[40];
  char keresztnev[40];
  int matek, prog1, villanytan;
  
  befile = fopen(BEFILE, "r");
  
  while(fgets(sor, 39, befile))
  {
    sscanf(sor, "%s %s %d %d %d", vezeteknev, keresztnev, &matek, &prog1, &villanytan);
    strcpy(jegyek[szamlalo].vezeteknev, vezeteknev);
    strcpy(jegyek[szamlalo].keresztnev, keresztnev);
    jegyek[szamlalo].matek = matek;
    jegyek[szamlalo].prog1 = prog1;
    jegyek[szamlalo].villanytan = villanytan;
    szamlalo++;
    printf("%d %d %d\n", matek, prog1, villanytan);
  }
  
  fclose(befile);
  
  printf("Osszesen %d sort olvastam be.\n", szamlalo);

  int i;
  int matek_ossz = 0;
  float matek_atlag;
  for (i=0; i<szamlalo; i++)
  {
    matek_ossz += jegyek[i].matek;
  }
  matek_atlag = 1. * matek_ossz / szamlalo;
  printf("A matek jegyek atlaga: %.2f\n", matek_atlag);
  
  int legjobb_villanytanbol = 0;
  int legjobb_villanytan_jegy = jegyek[0].villanytan;
  
  for (i=0; i<szamlalo; i++)
  {
    if (jegyek[i].villanytan > legjobb_villanytan_jegy)
    {
      legjobb_villanytan_jegy = jegyek[i].villanytan;
      legjobb_villanytanbol = i;
    }
  }
  printf("Legjobb villanytanbol: %s %s (jegye: %d)\n", jegyek[legjobb_villanytanbol].vezeteknev, jegyek[legjobb_villanytanbol].keresztnev, legjobb_villanytan_jegy);

  int jegyek_db[6];
  for (i=0; i<6; i++)
  {
    jegyek_db[i] = 0;
  }
  for (i=0; i<szamlalo; i++)
  {
    jegyek_db[jegyek[i].matek]++;
    jegyek_db[jegyek[i].prog1]++;
    jegyek_db[jegyek[i].villanytan]++;
  }
  for (i=1; i<=5; i++)
  {
    printf("%d: %d db\n", i, jegyek_db[i]);
  }

  return 0;
}
