/*
** my_dir.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 05:10:06 2016 THEIS Paul
** Last update Sun Jan 10 22:40:53 2016 THEIS Paul
*/

#include "main.h"

char		*my_pathfile(char *path, char *name)
{
  char		*res;
  int		i;
  int		j;

  if ((res = malloc(strlen(path) + strlen(name) + 1)) == NULL)
    my_puterror(0, 0);
  i = 0;
  j = 0;
  while (path[i])
    {
      res[i] = path[i];
      i++;
    }
  while (name[j])
    {
      res[i] = name[j];
      i++;
      j++;
    }
  res[i] = '\0';
  return (res);
}

char		*my_add_slash_dir(char *str)
{
  char		*res;
  int		i;

  if (str[strlen(str) - 1] == '/')
    return (str);
  if ((res = malloc(strlen(str) + 2)) == NULL)
    my_puterror(0, 0);
  i = 0;
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '/';
  i++;
  res[i] = '\0';
  return (res);
}
