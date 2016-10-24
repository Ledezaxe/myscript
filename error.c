/*
** error.c for  in /home/rouane_q/projets/unix/my_script
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Tue Feb 25 12:29:45 2014 quentin rouanet
** Last update Tue Feb 25 12:31:03 2014 quentin rouanet
*/

#include "main.h"

void error()
{
  perror(strerror(errno));
  exit(EXIT_FAILURE);
}
