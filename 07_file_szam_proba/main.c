/******************************************************************************
File megnyitasa
  - Olvasasra
  - Irasra
    fopen -> FILE*
  
File muveletek
  - Olvasas a file-bol
    gets -> fgets
    scanf -> fscanf
    
  - Iras a file-ba
    printf -> fprintf

File lezarasa
  fclose
*******************************************************************************/
#include <stdio.h>

#define MAXSZAM 10

int main()
{
  FILE* befile;
  int beszam;
  int kilep = 0;
  int szamok[MAXSZAM];
  int index[MAXSZAM];
  int szamok_db = 0;
  int i, j;
  
  befile = fopen("be.txt", "r");
  do
  {
    kilep = (fscanf(befile, "%d", &beszam) < 1);
    if (!kilep)
    {
      szamok[szamok_db] = beszam;
      szamok_db++;
    }
    if (szamok_db == MAXSZAM)
    {
      kilep = 1;
    }
  } while (!kilep);
  fclose(befile);
  
  for (i=0; i<szamok_db; i++)
  {
    printf("%d\n", szamok[i]);
  }
  
  printf("-------------\n");
  int maxszam = szamok[0];
  int maxszam_index = 0;
  for (i=0; i<szamok_db; i++)   //Max. kivalasztas, linearis futasi ideju
  {
    if (szamok[i] > maxszam)
    {
      maxszam = szamok[i];
      maxszam_index = i;
    }
  }
  printf("Legnagyobb: %d (%d. helyen)\n", maxszam, maxszam_index);
  
  printf("-------------\n");
  int minszam = szamok[0];
  int minszam_index = 0;
  for (i=0; i<szamok_db; i++)   //Min. kivalasztas, linearis futasi ideju
  {
    if (szamok[i] < minszam)
    {
      minszam = szamok[i];
      minszam_index = i;
    }
  }
  printf("Legkisebb: %d (%d. helyen)\n", minszam, minszam_index);
  
  printf("-------------\n");
  for (i=0; i<szamok_db; i++)
  {
    index[i] = i;
  }
  for (i=0; i<szamok_db; i++)   //Ez a rendezo algoritmus n^2 futasi ideju
  {
    for (j=i+1; j<szamok_db; j++)
    {
      if (szamok[index[i]] > szamok[index[j]])
      {
        int temp;
        temp = index[i];
        index[i] = index[j];
        index[j] = temp;
      }
    }
  }
  for (i=0; i<szamok_db; i++)
  {
    printf("%d\n", szamok[index[i]]);
  }
  
  
  return 0;
}
