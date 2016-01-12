/*
** my_create.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 21:50:23 2016 THEIS Paul
** Last update Sun Jan 10 16:36:51 2016 THEIS Paul
*/

#ifndef MY_CREATE_H_
# define MY_CREATE_H_

# include "main.h"

t_my_header	*my_create_header(char *str);
void		my_createfile(int fg, t_my_header *my_file, char *opt);
void		my_createdir(t_my_header *my_file, char *opt);

#endif /* !MY_CREATE_H_ */
