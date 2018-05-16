#include <stdio.h>
#include <stdlib.h>

void	sapin(int size)
{
  char etoile;
  char newline;
  char espace;
  char tronc;

  etoile = '*';
  newline = '\n';
  espace = ' ';
  tronc = '|';


  //CALCUL DU NOMBRE DE LIGNE TOTAL

  int a = 0;
  int b = 0;
  int c = 4;
  int total_lignes;
  while (a <= size)
    {
      b = 0;
      while (b < c)
	{
	  b++;
	  total_lignes++;
	}
      c++;
      a++;
    }

  //PARTIE PRINCIPALE

  int ligne;
  int i;
  int j;
  int etage;
  int nblignes;
  int nbetoiles;
  int nbespaces_ligne;
  int retours_pairs;

  etage = 0;
  nblignes = 4;
  nbetoiles = 1;
  nbespaces_ligne = total_lignes/2;
  retours_pairs = 2;

  while(etage < size)
    {
      ligne = 0;
      while(ligne < nblignes)
	{
	  i = nbespaces_ligne;
	  j = 0;

	  while(i > 0)
	    {
	      write(1,&espace,1);
	      i--;
	    }

	  while(j < nbetoiles)
	    {
	      write(1,&etoile,1);
	      j++;
	    }
	  write(1,&newline,1);
	  nbespaces_ligne--;
	  nbetoiles = nbetoiles +2;
	  ligne++;
	}

      //Passer à l'etage suivant
      if(etage == 0)
	{
	  nbetoiles = nbetoiles -4;
	  nbespaces_ligne = nbespaces_ligne +2;
	}
      else if (etage%2 == 0)
	{
	  retours_pairs++;
	  nbetoiles = nbetoiles - 2 * retours_pairs;
	  nbespaces_ligne = nbespaces_ligne + retours_pairs;
	}
      else if (etage%2 != 0)
	{
	  nbetoiles = nbetoiles - 2 * retours_pairs;
	  nbespaces_ligne = nbespaces_ligne  + retours_pairs;
	}

      nblignes++;
      etage++;
    }


  //Tronc
  int x; //lignes
  int y; //espaces
  int z; //pipes
  int nbpipe;

  if (size%2 == 0)
    nbpipe = size +1;
  else
    nbpipe = size;

  x = 0;
  while(x < size)
    {
      y = 0,
      z = 0;

      while(y < ((j-nbpipe)/2 +1))//j'utilise la derniere ligne, la base du sapin
	{
	  write(1,&espace,1);
	  y++;
	}
      while(z < nbpipe)
	{
	  write(1,&tronc,1);
	  z++;
	}
      write(1,&newline,1);
      x++;
    }
  //printf("\n");
  //printf("Retours des pairs : %d\n", retours_pairs);
  //printf("Etoiles sur la derniere ligne : %d\n", j);
  //printf("Total de Lignes : %d\n", total_lignes);

}


int	main(int argc, char* argv[])
{
  if (argc == 2 && atoi(argv[1]) > 0)
    {
      sapin(atoi(argv[1]));
    }
  return(0);
}
