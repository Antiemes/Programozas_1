/*
Beolvasás: tömbbe, legfejlebb 10 elem
Vége: Üres sor
*/
#include <stdio.h>

#define MAXSZAMOK 10
#define BEFILE "be.txt"
#define KIFILE "ki.txt"

int szamok[MAXSZAMOK];
int szamok_db = 0;
int kilep = 0;

int main()
{
  int max = 0;
  int max_index = 0;
  int i, j;
  int osszeg = 0;
  float atlag;
 
  FILE* befile;
  befile = fopen(BEFILE, "r");
  
  FILE* kifile;
  kifile = fopen(KIFILE, "w");
  
  do
  {
    int szam;
    
    if (fscanf(befile, "%d", &szam) > 0)
    {
      szamok[szamok_db] = szam;
      szamok_db++;
    }
    else
    {
      kilep = 1;
    }
    if (szamok_db >= MAXSZAMOK)
    {
      kilep = 1;
    }
    
  } while (!kilep);

  /*printf("Osszesen %d db szam.\n", szamok_db);
  for (i=0; i<szamok_db; i++)
  {
    printf("%d\n", szamok[i]);
  }*/

  for (i=0; i<szamok_db; i++)
  {
    if (szamok[i] > max)
    {
      max = szamok[i];
      max_index = i;
    }
  }
  fprintf(kifile, "A legnagyobb szam: %d (%d. helyen)\n", max, max_index);

  for (i=0; i<szamok_db; i++)
  {
    for (j=i+1; j<szamok_db; j++)
    {
      if (szamok[i] > szamok[j])
      {
        int temp;
        temp = szamok[i];
        szamok[i] = szamok[j];
        szamok[j] = temp;
      }
    }
  }
  
  for (i=0; i<szamok_db; i++)
  {
    fprintf(kifile, "%d\n", szamok[i]);
  }

  for (i=0; i<szamok_db; i++)
  {
    osszeg += szamok[i];
  }
  fprintf(kifile, "Osszesen: %d\n", osszeg);
  atlag = (float)osszeg / (float)szamok_db;
  fprintf(kifile, "Szamok atlaga: %f\n", atlag);
  

  fclose(befile);
  fclose(kifile);

  return 0;
}
