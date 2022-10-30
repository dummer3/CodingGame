#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Est ce que les heures sup sont payés en linux ?

int main()
{ 
  int N;
  scanf("%d", &N);
  int L;
  scanf("%d", &L); fgetc(stdin);
  L--;

  char ** tabPiece = (char**) malloc(N*sizeof(char*));
    
  for(int i = 0; i<N;i++)
    {
      tabPiece[i] = (char*) malloc(((N+1)*2)*sizeof(char));
      fgets(tabPiece[i], N*2+1, stdin);

    }


  for (int i = 0;i<N;i++)
    {
      for (int j = 0;j < N*2;j+=2)
	{
	  if (tabPiece[i][j] == 'C')
	    {
	      int l;
	      int L2;
	      int limite;
	      int Limite;
		 
	      l = i-L >= 0 ? i-L : 0;
	      L2 = j-L*2 >= 0 ? j-L*2 : 0;
	      limite = i+L < N ? i+L : N-1;
	      Limite =  j+L*2 < N*2 ? j+L*2 : N*2-1;

	      for(int u = l;u <= limite;u++)
		{
		  for (int v = L2; v <=Limite;v+=2)
		    {
		      if(tabPiece[u][v] != 'C')
			{
		      tabPiece[u][v] = 'L';
			}
		    }
		}
		  
	    }
	}
    }



    
  int nbr = 0;
  for (int i =0; i < N;i++)
    {
      //printf(">>>%s",tabPiece[i]);
      for (int j = 0; j < N*2;j++)
	{
	  if (tabPiece[i][j] == 'X')
	    {
	      nbr++;
	    }
	}
    }
		  
       

  printf("%d\n",nbr);

  return 0;
}
