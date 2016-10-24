/*
** main.c for  in /home/rouane_q/projets/unix/my_script/my_script_FI
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Tue Feb 18 16:02:28 2014 quentin rouanet
** Last update Fri Feb 28 10:17:48 2014 quentin rouanet
*/

#include "main.h"

int g_stop;

void setstop(int s)
{
  s = s;
  g_stop = 0;
}

void side_master(int master, int file)
{
  fd_set f;
  char buff[4096];
  int i;

  while (g_stop == 1)
    {
      FD_ZERO(&f);
      FD_SET(0, &f);
      FD_SET(master, &f);
      select(master + 1, &f, NULL, NULL, NULL);
      if (FD_ISSET(0, &f))
	{
	  i = read(0, buff, 4096);
	  write(master, buff, i);
	}
      if (FD_ISSET(master, &f))
	{
	  i = read(master, buff, 4096);
	  write(1, buff, i);
	  write(file, buff, i);
	}
      if (i < 0)
	g_stop = 0;
    }
}

void side_slave(int slave, struct termios *terms_new, struct termios *terms_default)
{
  tcgetattr(slave, terms_default);
  *terms_new = *terms_default;
  cfmakeraw(terms_new);
  tcsetattr(slave, TCSANOW, terms_new);
  close(0);
  close(1);
  close(2);
  dup(slave);
  dup(slave);
  dup(slave);
  system("bash");
}

int open_file(char *name, int flags)
{
  int fd;

  fd = open(name, flags);
  if (fd == -1)
    error();
  return (fd);
}

void script(char *namefile, int flags)
{
  int file;
  int master;
  int slave;
  struct winsize win;
  struct termios terms_default;
  struct termios terms_new;
  pid_t pid;
  char name[50];

  g_stop = 1;
  signal(SIGCHLD, setstop);
  master = my_posix_openpt(O_RDWR);
  ioctl(0, TIOCGWINSZ, &win);
  my_grantpt(master);
  my_unlockpt(master);
  ptsname_r(master, name, 50);
  slave = open_file(name, O_RDWR|O_NOCTTY);
  file = open_file(namefile, flags);
  fchmod(file, 00644);
  pid = fork();
  if (pid)
    side_master(master, file);
  else
    {
      close(master);
      side_slave(slave, &terms_new, &terms_default);
    }
  tcsetattr(slave, TCSANOW, &terms_default);
}
