/*
** my_untar.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 21:49:52 2016 THEIS Paul
** Last update Sun Jan 10 16:37:37 2016 THEIS Paul
*/

#ifndef MY_UNTAR_H_
# define MY_UNTAR_H_

# include "main.h"

# define MAX_SIZE	512

void	my_untar(int fd, char *opt);
int	my_fill_elt(char *header, char *elt, int start, int end);
void	my_convert_elt(mode_t *mode, uid_t *owner,
		       gid_t *grp, t_my_header *file);

#endif /* !MY_UNTAR_H_ */
