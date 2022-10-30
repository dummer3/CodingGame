#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// pair représente un chemin possible
struct pair
{

  char pointDeDepart;
  int positionArrivee;
};
typedef struct pair p_t;

int main()
{
  // W et la largeur et H la hauteur du diagramme représentant le ghost legs
  int W;
  int H;
  scanf("%d%d", &W, &H); fgetc(stdin);
  // cette variable permet de sauvegarder la première ligne, ce qui nous servira à la fin pour remttre les chemins dans le bon ordre
  char  premiereLigne[1025];
  // servira à la fin pour remettre les chemins dans le bon ordre
  int r=0;
  // tableau de pairs (tab[0] = résultat si on prends le chemin n°1)
  p_t *   tabDePair =( p_t *)  malloc((W/3+1)*sizeof( p_t));


  // On répète tant qu'on a pas regarder toutes les lignes du diagramme
  for (int i = 0; i < H; i++) {
    // On demande à l'utilisateur de rentrer ligne par ligne son diagramme
    char line[1025];
    fgets(line, 1025, stdin);

    // Pour chaque lignes verticales du diagramme (= chemin)
    for(int j = 0; j  < W; j+=3)
      {
	// Si c'est la premiere ligne
	if( i== 0)
	  {
	    // On sauvegarde la première ligne dans la variable prévu à cette effet
	    for (int v = 0 ; v < W ; v++)
	      {
		premiereLigne[v]=line[v];
		  
	      }
	    // on sauvegarde dans pointDeDepart le caractères du cette ligne verticale et dans positionArrivee le rang de cette ligne 
	    (&tabDePair[j/3])->pointDeDepart = line[j];
	    (&tabDePair[j/3])->positionArrivee = j;
	  }
	// Sinon si on a pas atteint la dernière ligne
	else if ( i < H-1)
	  {
	    // Si il y a un pont sur le côté droit de la ligne
	    if (j < W-1 && line[j+1] == '-')
	      {
		// positionArrivee de la ligne de droite gagne un rang et celui de la ligne de droite en perd un
		((&tabDePair[j/3])->positionArrivee) += 3;
		((&tabDePair[j/3+1])->positionArrivee) -= 3;
		// On remplace les 2 lignes afin de pouvoir répèter cette étape
		p_t   tempo = tabDePair[j/3];
		tabDePair[j/3] = tabDePair[j/3+1];
		tabDePair[j/3+1] = tempo;
		      
	      }
		
	  }
	// Sinon si c'est la dernière ligne
	else
	  {
	    // On remet chaque chemin à  sa place
	    for (int k =0; k < W/3+1;k++)
	      {
		if (tabDePair[k].pointDeDepart == premiereLigne[r*3])
		  {
		    // On affiche les chemins (Départ/Arrivée)
		    printf("%c%c\n",(&tabDePair[k])->pointDeDepart,line[(&tabDePair[k])->positionArrivee]);
		    r++;
		  }
	      }
		    
	  }
      }
  }
  // On libére le tableau alloué
  free(tabDePair);
  return 0;
}
