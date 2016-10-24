/*
** select.c for  in /home/rouane_q/projets/unix/my_script
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Tue Feb 25 10:11:40 2014 quentin rouanet
** Last update Tue Feb 25 12:46:56 2014 quentin rouanet
*/

#include "main.h"
#include <stdio.h>

void script(char *name, int flags);

int main(int ac, char **av)
{
  if (ac == 1)
    script("typescript", O_RDWR|O_CREAT);
  else if (ac == 2)
    {
      if (strcmp(av[1], "-a") == 0)
	script("typescript", O_RDWR|O_CREAT|O_APPEND);
      else
	script(av[1], O_RDWR|O_CREAT);
    }
  else if (ac == 3)
    {
       if (strcmp(av[1], "-a") == 0)
	script("typescript", O_RDWR|O_CREAT|O_APPEND);
      else
	printf("Usage : ./my_script [-a] [FILENAME]\n");
    }
  else
    printf("Usage : ./my_script [-a] [FILENAME]\n");
  return 1;
}
