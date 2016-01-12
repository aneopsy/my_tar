/*
** my_dir.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 05:10:06 2016 THEIS Paul
** Last update Sun Jan 10 16:34:20 2016 THEIS Paul
*/

#include "main.h"

void			my_set_octal(char *str, int oct, int size)
{
  char			tmp[12];
  unsigned int		i;
  unsigned int		j;

  my_init_char(tmp, 12);
  sprintf(tmp, "%o", oct);
  i = 0;
  while (i < size - strlen(tmp) - 1)
    str[i++] = '0';
  j = 0;
  while (i < (unsigned)size)
    str[i++] = tmp[j++];
}

void			my_set_int(char *str, int nbr, int size)
{
  char			tmp[12];
  unsigned int		i;
  unsigned int		j;

  my_init_char(tmp, 12);
  if (nbr != 0)
    sprintf(tmp, "%d", nbr);
  i = 0;
  while (i < size - strlen(tmp) - 1)
    str[i++] = '0';
  j = 0;
  while (i < (unsigned)size)
    str[i++] = tmp[j++];
  str[i] = '\0';
  }

void			my_set_dev(char *str, int nbr,
				      int size, mode_t st_mode)
{
  char			tmp[8];
  unsigned int		i;
  unsigned int		j;

  my_init_char(tmp, 12);
  if (S_ISCHR(st_mode) || S_ISBLK(st_mode))
    {
      sprintf(tmp, "%d", nbr);
      i = 0;
      while (i < size - strlen(tmp))
	str[i++] = '0';
      j = 0;
      while (i < (unsigned)size)
	str[i++] = tmp[j++];
    }
  else
    {
      i = 0;
      while (i < size - strlen(tmp))
	str[i++] = '\0';
    }
}
