#include <stdio.h>

//#define DEBUG

int tabla[10][10];

int beker(int* x, int* y)
{
    //B5 --> 1, 4
  char c1, c2; //amit beirok
  char dummy; //ide megy az enter

  scanf("%c%c", &c1, &c2);
  scanf("%c", &dummy);

#ifdef DEBUG
  printf(">%c<  >%c<\n", c1, c2);
#endif

  *x = c1 - 'A';
  *y = c2 - '0';
  
#ifdef DEBUG
  printf(">%d<  >%d<\n", *x, *y);
#endif

  return 0;
}

int jatekmezo()
{
  
  int i, j;
  
  //i -> x
  //j -> y
  
  printf(" ABCDEFGHIJ\n");
  for (j=0; j<10; j++)
  {
    printf("%d", j);
    for (i=0; i<10; i++)
    {
      char ch;
      int mezo = tabla[i][j];
      
      if (mezo == 0) // ures / rejtett
      {
        ch = '_';
      }
      else if (mezo == 1) // loves
      {
        ch = '*';
      }
      else
      {
        ch = '?';
      }

      printf("%c", ch);
    }
    printf("\n");
  }
  
  return 0;
}

int main()
{
  int x, y;
  
/*  beker(&x, &y);
#ifdef DEBUG
  printf(">%d<  >%d<\n", x, y);
#endif
*/

  jatekmezo();

  return 0;
}
/*

  ABCDEFGHIJ
 0**********
 1**********
 2**********
 3**********
 4**********
 5**********
 6**********
 7**********
 8**********
 9**********

Játékmező + dekoráció
El kell rejteni egy aknát
Játékmezőt ki kell rajzolni
  - Hova lőttünk eddig
  - Ha eltaláltunk valamit, akkor az jelenjen meg
Bekérjük a lövés koordinátáit
*/
/*
Feladatok:
  koordináták bekérése, átváltása
  Játék állapotának tárolása
    - Kétdimenziós tömb
       - Karakterek
       - Számok (0: üres, 1: bomba, 2: lövés)
       - ....
  Játékmenet (kilépés, lövések bekérése, tábla kirajzolása)
*/
