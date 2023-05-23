#include <stdio.h>

#define BEFILE "be.txt"

int main()
{
  FILE* befile;
  int lap;
  int db = 0;
  int ossz = 0;
  int eleg = 0;
  int hany[12]; // Ebben szamoljuk, hogy melyik kartyabol hany darab van. Nehany helyet nem hasznalunk majd fel.
  int i;
  int tizes_db = 0;
  int asz_db = 0;

  for (i=0; i<12; i++)
  {
    hany[i] = 0;
  }

  befile = fopen(BEFILE, "r"); // Ha nem file-bol dolgozunk, akkor ez nem kell.

  while (fscanf(befile, "%d", &lap) == 1) // Ha nem file-bol dolgozunk, akkor ehelyett a kovetkezo sor kell.
  //while (scanf("%d", &lap) == 1)
  {
    if (!(lap == 2 || lap == 3 || lap == 4 || lap == 10 || lap == 11))
    {
      printf("A %d nem ervenyes lap. Kihagyjuk.\n", lap);
      break;
    }
    hany[lap]++; // Amenyi a lap erteke, a tomb annyiadik eleme tarolja, hogy hany darab van az adott lapbol.
    db++; // Szamoljuk, hogy hany darab lapot olvastunk be.
    ossz += lap;

    if (lap == 10)
    {
      tizes_db++;
    }
    if (lap == 11)
    {
      asz_db++;
    }

    if (!eleg) // Ezt azert kell megvizsgalni, hogy csak az elso esetben jelezzen, utana mar tobbszor ne.
    {
      if (ossz >= 66)
      {
        eleg = 1;
        printf("A %d. lapnal (ami egy %d-es) eleg.\n\n", db, lap);
      }
    }
    //printf("%d\n", lap);
  }
  printf("Osszesen %d db kartya, osszesen %d pont.\n\n", db, ossz);

  printf("%d erteku lapbol %d db van.\n",  2, hany[ 2]); // Ezt illene ciklussal
  printf("%d erteku lapbol %d db van.\n",  4, hany[ 3]); // csinalni, de ha csak
  printf("%d erteku lapbol %d db van.\n",  4, hany[ 4]); // 5 eset van, akkor ez
  printf("%d erteku lapbol %d db van.\n", 10, hany[10]); // is megfelel.
  printf("%d erteku lapbol %d db van.\n", 11, hany[11]);

  printf("\n");
  printf("Tizes es asz osszesen: %d, ossz ertekuk: %d\n", tizes_db + asz_db, tizes_db * 10 + asz_db * 11);

  fclose(befile); //Ha nem file-bol dolgozunk, akkor ez nem kell.
}
