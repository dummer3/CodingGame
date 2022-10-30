#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// fonction transformant un caracteres (en decimal) en binaire
void passageEnBinaire(int c, int i, int * binaire)
{
  //calcul le reste de la division par 2, le place dans tab[j] et divise le nombre par 2 
  for (int j = 6; j>=0;j--)
    {
      binaire[i+j] = c%2;
      c=  c/2;

    }

}
int main()
{
  // Le message que l'in veut coder
  char MESSAGE[101];

  
    fgets(MESSAGE, 101, stdin);
    // La taille de ce même message mais avec cette fois-ci ses caractères en binaire
    int taille = 7*(strlen(MESSAGE)-1);
    // Le message à coder en binaire
  int * messageBinaire = (int *) malloc(taille*sizeof(int));
  // Appele de la fonction pour transformer une par une les caractères en binaire 
    for (int i =0 ; i < strlen(MESSAGE)-1;i++)
      {

	passageEnBinaire(MESSAGE[i],i*7,messageBinaire);

      }
    //nombre correspond au nombre de bit de même valeur qui se suivent 
    int nombre = 1;
    // Pour chaque chiffre du message codé en binaire
    for(int j =0; j <taille;j++)
      {
	// reference reprèsente le valeur de la suite de bit (0 ou 1)
       int  reference = messageBinaire[j];
        if (j<taille-1 && messageBinaire[j+1] == messageBinaire[j])
	  {
	    // si le prochain bit est de même valeur l'actuelle, on rajoute 1 à  nombre
	    nombre++;
	  }
	// si le prochain bit n' a pas la même valeur 
	else
	  {
	    // si la valeur de la suite de bit est 1, on affiche "0" ...
	    if (reference == 1)
	      {
		printf("0 ");
	      }
	    // si la valeur de la suite de bit est 0, on affiche "00" ... 
	    else
	      {
		printf("00 ");
	      }
	    //suivi de nombre* "0"
	    for (int u = 0 ; u < nombre ; u++)
	      {
		printf("0");
	      }
	    // Si on n'a pas atteint le dernier bit,on met un espace pour éviter que tous soit collée 
	    if(j != taille-1)
	      {
	    printf(" ");
	      } 
	    nombre = 1;
	  }
      }
    printf("\n");
    free(messageBinaire);
    return 0;
}
