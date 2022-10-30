  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  int main ()
  {

    FILE* f;
    char chaine[100];
    int num = 1;


    f = fopen("lumen_IN.txt" ,"r");


    for(int i = 0; i < num ; i++)
      {

	do
	  {
	    fgets(chaine,100,f);

	  } while(strcmp(chaine,"NEXT\n"));
      }

	fgets(chaine,100,f);
    do 
      {
	if(chaine[0] !=' ')
	  {
	printf("%s\n",chaine);
	}
	fgets(chaine,100,f);
      }while(strcmp(chaine,"NEXT\n"));
    return 0;
  }
