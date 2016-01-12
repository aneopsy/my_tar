/*
** my_dir.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 05:10:06 2016 THEIS Paul
** Last update Sun Jan 10 16:25:56 2016 THEIS Paul
*/

#include "main.h"

int		my_add(char *str)
{
  int		tot;
  int		i;

  tot = 0;
  i = 0;
  while (str[i])
    {
      tot += str[i];
      i++;
    }
  return (tot);
}

void		my_checksum(char *str, char *tmp)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while ((unsigned int)i < 6 - strlen(tmp))
    str[i++] = '0';
  while (i < 6)
    str[i++] = tmp[j++];
  str[i++] = '\0';
  str[i] = ' ';
}

void		my_puterror(char flag, int my_errno)
{
  errno = my_errno;
  if (flag == 0)
    printf("ERROR: /!\\malloc!\n");
  else
    printf("%s\n", strerror(errno));
  exit(EXIT_FAILURE);
}

char		my_check_block(char *str)
{
  int		i;

  i = 0;
  while (i < MAX_SIZE && str[i] == '\0')
    i++;
  return ((i == MAX_SIZE));
}
