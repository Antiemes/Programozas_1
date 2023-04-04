/******************************************************************************
Szerencsekerek
*******************************************************************************/
#include <stdio.h>
#include <string.h>

void kiirRejtve(char* szoveg, int* felfed)
{
  int i = 0;
  char ch;
  while((ch = szoveg[i]))
  {
    if (felfed[i])
    {
      printf("%c", ch);
    }
    else
    {
      printf("_");
    }
    i++;
  }
  printf("\n");
}

char beker()
{
  char ch, dummy;
  printf("Kovetkezo betu: ");
  scanf("%c", &ch);
  scanf("%c", &dummy);
  return ch;
}

int betutFelfed(char* feladvany, int* minta, char betu)
{
  int i = 0;
  char ch;
  int talalat = 0;
  
  while ((ch = feladvany[i]))
  {
    if (feladvany[i] == betu)
    {
      minta[i] = 1;
      talalat++;
    }
    i++;
  }
  return talalat;
}

int main()
{
  char feladvany[]="TUDJA, HOL SZERET A CAPA";
  int felfed[strlen(feladvany)];
  int i;
  int kilep = 0;
  char tipp;
  
  for (i=0; i<strlen(feladvany); i++)
  {
    felfed[i] = 0;
  }
  
  betutFelfed(feladvany, felfed, ' ');
  betutFelfed(feladvany, felfed, '-');
  betutFelfed(feladvany, felfed, ',');
  
  while (!kilep)
  {
    kiirRejtve(feladvany, felfed);
    tipp = beker();
    betutFelfed(feladvany, felfed, tipp);
  }

  return 0;
}
