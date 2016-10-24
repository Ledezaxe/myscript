/*
** main.h for  in /home/rouane_q/projets/unix/my_script/my_script_FI
** 
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
** 
** Started on  Tue Feb 18 16:04:56 2014 quentin rouanet
** Last update Fri Feb 28 10:18:04 2014 quentin rouanet
*/

#ifndef MAIN_H__
# define MAIN_H__

# define _GNU_SOURCE
# define _BSD_SOURCE
# define _XOPEN_SOURCE 800

#include <stropts.h>
#include <pty.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/vfs.h>

void error();
int my_posix_openpt(int flags);
void my_grantpt(int master);
void my_unlockpt(int fd);

#endif /* !MAIN_H__ */
