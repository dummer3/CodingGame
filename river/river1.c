#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void  prochainRiver(long long *  r,long long autreR);


int main()
{  
 

    long long r_1;
    scanf("%lld", &r_1);
    long long r_2;
    scanf("%lld", &r_2);
 


    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

while (r_1 != r_2)
{

    if (r_1 <= r_2)
    {
       prochainRiver(&r_1,r_2);
    }
    else
    {
       prochainRiver(&r_2,r_1);
    }
}


    return 0;
}



void prochainRiver(long long * r,long long autreR)
{
    long long initialR = *r;
  
    long i = 1;
    int somme = 0;
 
    while((float)(( initialR) / i >= 1))
    {
    
       i *= 10;
       somme += (initialR%i)/(i/10);
        initialR -= initialR%i;
      

    }
    *r += somme;
    if (*r == autreR)
    {
    
      printf("%lld",*r);
       
    }
 }
 
