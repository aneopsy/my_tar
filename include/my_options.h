/*
** my_options.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 20:59:54 2016 THEIS Paul
** Last update Sun Jan 10 16:18:41 2016 THEIS Paul
*/

#ifndef MY_OPTIONS_H_
# define MY_OPTIONS_H_

# include "main.h"

# define ID_CREATE	0
# define ID_XTRACT	1
# define ID_VERBOSE	2
# define ID_FILE	3
# define ID_TLIST	4
# define ID_PERM	5

char			my_check_opt(char *opt, char *str);

#endif /* !MY_OPTIONS_H_ */
