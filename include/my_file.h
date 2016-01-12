/*
** my_file.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 21:50:40 2016 THEIS Paul
** Last update Sun Jan 10 16:58:16 2016 Paul THEIS
*/

#ifndef MY_FILE_H_
# define MY_FILE_H_

# include "main.h"

typedef struct	s_my_header
{
  char		name[100];
  char		mode[8];
  char		uid[8];
  char		gid[8];
  char		size[12];
  char		mtime[12];
  char		chksum[8];
  char		typeflag;
  char		linkname[100];
  char	        magic[6];
  char		version[3];
  char		u_name[32];
  char		g_name[32];
  char		devmajor[8];
  char		devminor[8];
  char		prefix[167];
}		t_my_header;

t_my_header	*my_fill_struct(struct stat *buf, char *name);
void		my_init_char(char *str, int size);
void		my_display_all(t_my_header *my_file, FILE *file);

#endif /* !MY_FILE_H_ */
