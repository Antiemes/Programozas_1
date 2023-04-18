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
  - Végigmegyünk minden ponton
    Ha a szomszédon át rövidebb az út,
    akkor az aktuális távolság = szomszéd távolsága + 1
    
    ...
    0..
    ...
    
    1..
    012
    123
    
    123
    012
    123
    
    Akkor áll meg, ha nem tud több frissítést végezni

Váz
  beolvasás
  
  isméltelve
    - keresés
    - megjelenítés

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

int tavolsag(int terkep[TERKEP_MAGASSAG][TERKEP_SZELESSEG], int x, int y)
{
  if (x < 0 || x >= TERKEP_SZELESSEG || y < 0 || y >= TERKEP_MAGASSAG)
  {
    return -2;
  }
  else
  {
    return terkep[y][x];
  }
}

int szomszed_fele_frissit(int terkep[TERKEP_MAGASSAG][TERKEP_SZELESSEG], int x, int y, int x_sz, int y_sz)
{
  int eredeti = terkep[y][x];
  int szomszed_tav;
  
  if ((szomszed_tav = tavolsag(terkep, x_sz, y_sz)) >= 0)
  {
    if (szomszed_tav + 1 < eredeti)
    {
      terkep[y][x] = szomszed_tav + 1;
      return 1;
    }
  }
  return 0;
}

int terkep_keres(int terkep[TERKEP_MAGASSAG][TERKEP_SZELESSEG])
{
  int x, y;
  int cserek = 0;

  for (y=0; y<TERKEP_MAGASSAG; y++)
  {
    for (x=0; x<TERKEP_SZELESSEG; x++)
    {
      cserek += szomszed_fele_frissit(terkep, x, y, x+1, y);
      cserek += szomszed_fele_frissit(terkep, x, y, x-1, y);
      cserek += szomszed_fele_frissit(terkep, x, y, x, y-1);
      cserek += szomszed_fele_frissit(terkep, x, y, x, y+1);
    }
  }
  return cserek;
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
