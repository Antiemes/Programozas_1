/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nev[6];
    char dummy[6];
    int bekert;
    int rejtett;
    int nyert = 0;

    printf("Mi a neved?\n");
    gets(nev);

    rejtett = (rand() % 10) + 1;

    do
    {
        printf("Kerek egy szamot:");
        scanf("%d", &bekert);
        gets(dummy);
        if (bekert == rejtett)
        {
            nyert = 1;
        }
    } while (!nyert);

    printf("Nyertel, %s!\n", nev);

    return 0;
}
