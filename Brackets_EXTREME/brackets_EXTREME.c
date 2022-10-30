#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct maillon
{
 struct maillon* suivant;
  char caracteres;
};

typedef struct maillon maillon;

struct pile
{
  maillon* debut;
};

typedef struct pile pile;

void empile(pile* p, maillon* c)
{
  if(p->debut == NULL)
    {
      p->debut = c;
      c->suivant = NULL;

    }
  else
    {
  maillon* premier = p->debut;
  p->debut = c;
    c->suivant = premier;
    }
  maillon* maillonEncours = p->debut;
    
  while (maillonEncours != NULL)
    {
     
      maillonEncours = maillonEncours->suivant;
	}
  }

void depile(pile* p)
{
  
  if(p->debut != NULL)
    {
      p->debut = p->debut->suivant;
    }
	
}
char ValeurTop(pile* p)
{
  if(p->debut !=NULL)
    {
  return p->debut->caracteres;
    }
  return '0';
 
}

int main()
{
  bool bracketsEntrees = false;
  pile p = {NULL};
    char expression[2049];
    scanf("%s", expression);
    int taille = strlen(expression);
    for(int i = 0; i<taille;i++)
      {
	if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
	  {
	    bracketsEntrees = true;
	    // maillon m = {NULL,expression[i]};
	    maillon * m;
	    m= (maillon *) malloc(1*sizeof(maillon));
	    m->suivant = NULL;
	    m->caracteres = expression[i];
	      empile(&p,m);
	  }
	else if(expression[i]-1 ==  ValeurTop(&p) || expression[i] -2 == ValeurTop(&p))
	  {
	  
	    depile(&p);
	  }

      }

    if(p.debut == NULL && bracketsEntrees == true)
      {
      printf("true\n");
      }
      else
	{
	printf("false\n");
	}

    return 0;
}
