/******************************************************************************
Labirintus
  Maga a labirintus ("pálya"), ezt fájlból kell beolvasnunk
    - Szövegfájl
    - Sorok, oszlopok, minden karakter egy "elem" -> kódolás
      - Üres (ahol tudunk mozogni)   -> "."
      - Akadály (fal)                -> "#"
      - Megjelölt pont (pl. kijárat) -> "X"

Térkép belső tárolása
  Tömb, progarmba "beégetett" szélesség, magasság
  Elemei: számok
    - természetes számok: távolságok
    - negatív számok: speciális
      - Üres: -1
      - Akadály: -2
      - Megjelölt pont: 0

Térkép beolvasása
  - Be tudok olvasni teljes sort
    - Fájlt soronként olvassuk be
    - Beolvasott sort karakterenként feldolgozzuk

Térkép megjelenítése

Útkereső algoritmus

Váz

*******************************************************************************/
#include <stdio.h>

#define TERKEP_SZELESSEG 10
#define TERKEP_MAGASSAG 8
#define TERKEP_FILE "terkep.txt"

int terkep_kirajzol(int terkep[TERKEP_MAGASSAG][TERKEP_SZELESSEG])
{
  int x, y;
  
  for (y=0; y<TERKEP_MAGASSAG; y++)
  {
    for (x=0; x<TERKEP_SZELESSEG; x++)
    {
      switch (terkep[y][x])
      {
        case -2:
          printf("|##");
          break;
        case -1:
          printf("|  ");
          break;
        default:
          printf("|%2d", terkep[y][x]);
      }
    }
    printf("|\n");
  }
  return 0;
}

int terkep_beolvas(char* filenev, int terkep[TERKEP_MAGASSAG][TERKEP_SZELESSEG])
{
  FILE* befile;
  int x, y;
  
  befile = fopen(filenev, "r");
  
  for (y=0; y<TERKEP_MAGASSAG; y++)
  {
    char sor[TERKEP_SZELESSEG + 1];
    fscanf(befile, "%s", sor);
    for (x=0; x<TERKEP_SZELESSEG; x++)
    {
      int mezo;
      switch (sor[x])
      {
        case 'X':
          mezo = 0;
          break;
        case '#':
          mezo = -2;
          break;
        default:
          mezo = -1;
      }
      terkep[y][x] = mezo;
    }
  }
  
  fclose(befile);
  return 0;
}

int main()
{
  int terkep[TERKEP_MAGASSAG][TERKEP_SZELESSEG];
  int x, y;

//(0, 0) (0, 1) (0, 2) ... (1, 0) (1, 1) (1, 2) ... (2, 0) (2, 1) ...

  for (y=0; y<TERKEP_MAGASSAG; y++)
  {
    for (x=0; x<TERKEP_SZELESSEG; x++)
    {
      terkep[y][x] = -2;
    }
  }

  terkep_beolvas(TERKEP_FILE, terkep);
  

  terkep_kirajzol(terkep);

  return 0;
}
