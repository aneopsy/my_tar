/*
** my_dir.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 05:10:06 2016 THEIS Paul
** Last update Sun Jan 10 16:19:28 2016 THEIS Paul
*/

#include "main.h"

void		main_tar(int argc, char **argv, char *opt)
{
  FILE		*my_create;
  char		end[MAX_SIZE];
  int		i;

  if ((my_create = fopen(argv[2], "w")) == NULL)
    my_puterror(1, errno);
  printf("Creating archive %s ...\n", argv[2]);
  i = 3;
  while (i < argc)
    {
      my_tar(argv[i], my_create, opt);
      i++;
    }
  my_init_char(end, MAX_SIZE);
  my_writeparam(my_create, end, MAX_SIZE);
  if (fclose(my_create) == -1)
    my_puterror(1, errno);
  printf("Archive created\n");
}

void		main_untar(char *tar, char *opt)
{
  int		fd;

  if ((fd = open(tar, O_RDONLY)) == -1)
    my_puterror(1, errno);
  if (opt[ID_TLIST])
    printf("List of the archive %s\n", tar);
  else
    printf("Unarchive %s\n", tar);
  my_untar(fd, opt);
  if (close(fd) == -1)
    my_puterror(1, errno);
  printf("done!\n");
}

int		main(int argc, char **argv)
{
  char		opt[6];
  int		i;

  i = 0;
  while (i < 6)
    opt[i++] = 0;
  if (argc < 2 || my_check_opt(opt, argv[1]) ||
      ((opt[ID_CREATE] && argc < 2) || (opt[ID_XTRACT] && argc < 3)||
       (opt[ID_TLIST] && argc < 3)))
    {
      printf("Usage : ./my_tar [-cxvftp] TAR [FILES]\n");
      exit(EXIT_FAILURE);
    }
  if (opt[ID_CREATE])
    main_tar(argc, argv, opt);
  else if (opt[ID_XTRACT] || opt[ID_TLIST])
    main_untar(argv[2], opt);
  return (0);
}
