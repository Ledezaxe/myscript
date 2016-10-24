/*
** my_tty.c for  in /home/rouane_q/projets/unix/my_script
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Tue Feb 25 12:27:55 2014 quentin rouanet
** Last update Fri Feb 28 10:17:59 2014 quentin rouanet
*/

#include "main.h"

int my_posix_openpt(int flags)
{
  int fd;

  fd = open("/dev/ptmx", flags);
  if (fd == -1)
    error();
  return (fd);
}

void my_grantpt(int master)
{
  char name[50];
  uid_t uid;
  gid_t gid;
  int ret;
  int ret2;

  uid = getuid();
  gid = getgid();
  ptsname_r(master, name, 50);
  printf("%s\n", name);
  ret = chown(name, uid, gid); // change le uid et gid du pseudo esclave
  ret2 = chmod(name, S_IRUSR|S_IWUSR|S_IWGRP); // change le mode de l'esclave pour que ça marche ... en théorie.
  if (ret == -1 || ret2 == -1)
    error();
}

void my_unlockpt(int fd)
{
  int unlock;

  if (ioctl(fd, TIOCSPTLCK, &unlock) == -1)
    error();
}
