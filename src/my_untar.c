/*
** my_dir.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 05:10:06 2016 THEIS Paul
** Last update Sun Jan 10 16:29:07 2016 THEIS Paul
*/

#include "main.h"

int		my_fill_elt(char *header, char *elt, int start, int end)
{
  int		i;

  i = 0;
  while (start < end)
    {
      elt[i] = header[start];
      i++;
      start++;
    }
  return (start);
}

static void	my_wrong_header(int len)
{
  if (len < MAX_SIZE)
    {
      printf("Error: Problem with header, is it a tar file ?\n");
      exit(EXIT_FAILURE);
    }
}

void	my_convert_elt(mode_t *mode, uid_t *owner,
		       gid_t *grp, t_my_header *file)
{
  *mode = strtol(file->mode, NULL, 8);
  *owner = strtol(file->uid, NULL, 8);
  *grp = strtol(file->gid, NULL, 8);
}

void		my_untar(int fd, char *opt)
{
  int		len;
  char		buff[MAX_SIZE];
  t_my_header	*my_file;

  buff[0] = 'a';
  while (!my_check_block(buff))
    {
      if ((len = read(fd, buff, MAX_SIZE)) == -1)
	my_puterror(1, errno);
      my_wrong_header(len);
      if (!my_check_block(buff))
	{
	  my_file = my_create_header(buff);
	  if (my_file->typeflag == '5')
	    my_createdir(my_file, opt);
	  else
	    my_createfile(fd, my_file, opt);
	  free(my_file);
	}
    }
}
