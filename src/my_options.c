/*
** my_dir.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 05:10:06 2016 THEIS Paul
** Last update Sun Jan 10 16:26:49 2016 THEIS Paul
*/

#include "main.h"

static char		my_create_tab_opt(char c)
{
  char			tab[6];
  unsigned char		i;

  tab[ID_CREATE] = 'c';
  tab[ID_XTRACT] = 'x';
  tab[ID_VERBOSE] = 'v';
  tab[ID_FILE] = 'f';
  tab[ID_TLIST] = 't';
  tab[ID_PERM] = 'p';
  i = 0;
  while (tab[i] && tab[i] != c)
    i += 1;
  return (i);
}

static void		is_good_combo_opt(char *opt)
{
  if ((opt[ID_XTRACT] && !opt[ID_VERBOSE] && !opt[ID_FILE]))
    {
      printf("Usage : ./my_tar [-cxvf] TAR [FILES]\n");
      exit(EXIT_FAILURE);
    }
}

void		print_usage(char *str)
{
  printf("%s", str);
  exit(EXIT_FAILURE);
}

char			my_check_opt(char *opt, char *str)
{
  unsigned char		c;
  int			i;

  i = str[0] == '-' ? 1 : 0;
  while (str[i])
    {
      if ((c = my_create_tab_opt(str[i])) < 6)
	opt[c] = 1;
      else
	return (1);
      i += 1;
    }
  if (opt[ID_CREATE] && opt[ID_XTRACT])
      print_usage("Unable to create and extract same files.\n");
  if (opt[ID_CREATE] && opt[ID_TLIST])
      print_usage("Unable to list, please don't use -c with -t\n");
  if (opt[ID_XTRACT] && opt[ID_TLIST])
      print_usage("Unable to list, please don't use -x with -t\n");
  is_good_combo_opt(opt);
  return (0);
}
