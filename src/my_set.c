/*
** my_dir.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 05:10:06 2016 THEIS Paul
** Last update Sun Jan 10 22:42:08 2016 THEIS Paul
*/

#include "main.h"

void		my_set_data(char *str, char *data)
{
  int		i;

  i = 0;
  while (data != NULL && data[i])
    {
      str[i] = data[i];
      i++;
    }
}

void		my_set_chksum(char *str, t_my_header *file, int tot)
{
  char		tmp[6];

  tot += my_add(file->name);
  tot += my_add(file->mode);
  tot += my_add(file->uid);
  tot += my_add(file->gid);
  tot += my_add(file->size);
  tot += my_add(file->mtime);
  tot += my_add("       ");
  tot += file->typeflag;
  tot += my_add(file->linkname);
  tot += my_add(file->magic);
  tot += my_add(file->version);
  tot += my_add(file->u_name);
  tot += my_add(file->g_name);
  tot += my_add(file->devmajor);
  tot += my_add(file->devminor);
  tot += my_add(file->prefix);
  sprintf(tmp, "%o", tot);
  my_checksum(str, tmp);
}

void		my_set_link(char *my_link, char *str, struct stat *buf)
{
  char		*link;
  int		len;

  if ((link = malloc(sizeof(char) * 256)) == NULL)
    exit(EXIT_FAILURE);
  if (S_ISLNK(buf->st_mode))
    {
      if ((len = readlink(str, link, 256 * sizeof(char))) < 0)
	{
	  printf("error readlink.");
	  exit(EXIT_FAILURE);
	}
      else
	link[len] = '\0';
      my_set_data(my_link, link);
    }
  free(link);
}

void			my_set_uid(char *str, struct stat *buf, char type)
{
  struct passwd		*pwd;
  struct group		*grp;
  char			*tmp;
  int			i;

  if (type == 0)
    {
      pwd = getpwuid(buf->st_uid);
      tmp = pwd->pw_name;
    }
  else
    {
      grp = getgrgid(buf->st_gid);
      tmp = grp->gr_name;
    }
  i = 0;
  while (tmp[i])
    {
      str[i] = tmp[i];
      i++;
    }
}

char		my_type_file(struct stat *buf)
{
  char		c;

  c = 0;
  if (S_ISREG(buf->st_mode))
    c = '0';
  else if (S_ISLNK(buf->st_mode))
    c = '2';
  else if (S_ISCHR(buf->st_mode))
    c = '3';
  else if (S_ISBLK(buf->st_mode))
    c = '4';
  else if (S_ISDIR(buf->st_mode))
    c = '5';
  else if (S_ISFIFO(buf->st_mode))
    c = '6';
  else if (S_ISSOCK(buf->st_mode))
    c = '7';
  return (c);
}
