#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int river(int river);

int main()
{
  // le nombre que l'on veut étudier
  int r_1;
  // le nbr de river contenant r_1 (forcément 1 avec river r_1)
  int retour=1;
  int i=1;
  scanf("%d", &r_1);

  /* On répète l'intérieur de la boucle tant qu'on a pas trouvé l'autre river contenant r_1
     Ou tant qu'on a pas essayé pour tous les rivers */
  while(retour < 2 && i < r_1)
    {

      if (i + river(i) == r_1)
	{
         retour ++;
	}
    
        i++;
    }
  if(retour >= 2)
    {
      printf("YES\n");
    }
  else
    {
      printf("NO\n");
    }

   

  return 0;
}


int river(int river)
{
  int somme = 0;
  int i =1;

  
      while((float)(( river) / i >= 1))
	{
    
	  i *= 10;
	  somme += (river%i)/(i/10);
	  river  -= river%i;
	}
          return somme;
}
