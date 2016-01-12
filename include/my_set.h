/*
** my_set.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 21:50:14 2016 THEIS Paul
** Last update Sun Jan 10 16:35:23 2016 THEIS Paul
*/

#ifndef MY_SET_H_
# define MY_SET_H_

# include "main.h"

void	my_set_octal(char *str, int oct, int size);
void	my_set_int(char *str, int nbr, int size);
void	my_set_dev(char *str, int nbr, int size, mode_t st_mode);
void	my_set_data(char *str, char *data);
void	my_set_chksum(char *str, t_my_header *file, int tot);
void	my_set_link(char *my_link, char *str, struct stat *buf);
void	my_set_uid(char *str, struct stat *buf, char type);
char	my_type_file(struct stat *buf);

#endif /* !MY_SET_H_ */
