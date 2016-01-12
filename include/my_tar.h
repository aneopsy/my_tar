/*
** my_tar.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 21:51:05 2016 THEIS Paul
** Last update Sun Jan 10 16:37:24 2016 THEIS Paul
*/

#ifndef MY_TAR_H_
# define MY_TAR_H_

# include "main.h"

void	my_writeparam(FILE *file, char *str, int size);
void	my_tar(char *str, FILE *tar, char *opt);

#endif /* !MY_TAR_H_ */
