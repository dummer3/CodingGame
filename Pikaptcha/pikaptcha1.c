#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main()
{
  int width;
  int height;

  scanf("%d%d", &width, &height);

  // tableau2D representant le labyrinthe
  char ** tab = (char**) malloc(height*sizeof (char**));
  for(int l =0; l < width; l++)
    {
      tab[l] = (char*) malloc(width*sizeof (char*));
    }


    
  for (int i = 0; i < height; i++) {
    char line[256];
    scanf("%s", line);
    // L'utilisateur entre la carte du labyrinthe ligne par ligne
    sprintf(tab[i],"%s",line);

  }
  //Pour chaque ligne
  for (int i = 0; i < height; i++) {
    //pour chaque colonne
    for (int j = 0; j < width; j++)
      {
	// Si la case actuelle est un chemin 
	if (tab[i][j] == '0')
	  {
	    // somme va permettre de calculer le nombre de chemins accessibles adjacents
	    int somme = 0;
	    // Si il y a un chemin à gauche
	    if (j-1 >= 0 && tab[i][j-1] != '#')
	      {
		// On ajoute 1 à somme
		somme ++;
	      }
	    //Si il y a un chemin à droite
	    if (j+1 < width && tab[i][j+1] != '#')
	      {
		somme ++;
	      }
	    // Si il y a un chemin en haut
	    if( i-1 >= 0 && tab[i-1][j] != '#')
	      {
		somme ++;
	      }
	    // Si il y a un chemin en bas
	    if (i+1 < height && tab[i+1][j] != '#')
	      {
		somme++;
	      }
	    // On ajoute somme dans notre case actuelle, ainsi la case actuelle contient le nombre de chemins adjacents
	    tab[i][j] = '0'+ somme;
	  }
	// Par sécurité si je tapais un mauvais caractère.
	else
	  {
	    tab[i][j] = '#';
	  }


	    
      }
      
    // On affiche les lignes une par une.
    printf("%s\n",tab[i]); 
  }

  return 0;
}
