/*
** my_dir.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 05:10:06 2016 THEIS Paul
** Last update Sun Jan 10 22:52:46 2016 THEIS Paul
*/

#include "main.h"

void		my_writeparam(FILE *file, char *str, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      fputc(str[i], file);
      i++;
    }
}

static void		my_writefunction(FILE *file, t_my_header *my_file)
{
  my_writeparam(file, my_file->name, 100);
  my_writeparam(file, my_file->mode, 8);
  my_writeparam(file, my_file->uid, 8);
  my_writeparam(file, my_file->gid, 8);
  my_writeparam(file, my_file->size, 12);
  my_writeparam(file, my_file->mtime, 12);
  my_writeparam(file, my_file->chksum, 8);
  fputc(my_file->typeflag, file);
  my_writeparam(file, my_file->linkname, 100);
  my_writeparam(file, my_file->magic, 6);
  my_writeparam(file, my_file->version, 2);
  my_writeparam(file, my_file->u_name, 32);
  my_writeparam(file, my_file->g_name, 32);
  my_writeparam(file, my_file->devmajor, 8);
  my_writeparam(file, my_file->devminor, 8);
  my_writeparam(file, my_file->prefix, 167);
}

static void	my_writefile(FILE *file, FILE *tar)
{
  char		str[MAX_SIZE];
  unsigned int	lenoffile;
  char		*check;

  lenoffile = 0;
  while ((check = fgets(str, MAX_SIZE, file)) != NULL)
    {
      fprintf(tar, "%s", str);
      lenoffile += strlen(check);
    }
  lenoffile = MAX_SIZE - lenoffile % MAX_SIZE;
  while (lenoffile > 0)
    {
      fprintf(tar, "%c", '\0');
      lenoffile--;
    }
  if (check == NULL && errno != 0 && errno != EISDIR)
    my_puterror(1, errno);
}

static char	my_check_dir(struct stat *buf, char *str, FILE *tar, char *opt)
{
  struct dirent	*fle;
  DIR		*rep;
  char		*tmp;

  if (!S_ISDIR(buf->st_mode))
    return (0);
  if (!(rep = opendir(str)))
    my_puterror(1, errno);
  while ((fle = readdir(rep)))
    {
      if (!(fle->d_name[0] == '.' &&
	    (fle->d_name[1] == '\0' ||
	     (fle->d_name[1] == '.' && fle->d_name[2] == '\0'))))
	{
	  tmp = my_pathfile(str, fle->d_name);
	  my_tar(tmp, tar, opt);
	  free(tmp);
	}
    }
  if (closedir(rep) == -1)
    my_puterror(1, errno);
  return (0);
}

void			my_tar(char *str, FILE *tar, char *opt)
{
  t_my_header		*my_file;
  struct stat		*buf;
  FILE			*file;

  if ((buf = malloc(sizeof(*buf))) == NULL)
    my_puterror(0, 0);
  if ((file = fopen(str, "r")) == NULL || (lstat(str, buf)) == -1)
    my_puterror(1, errno);
  if (S_ISDIR(buf->st_mode))
    str = my_add_slash_dir(str);
  if ((my_file = my_fill_struct(buf, str)) && opt[ID_FILE])
    {
      my_writefunction(tar, my_file);
      if (my_file->typeflag != '5')
	my_writefile(file, tar);
    }
  else
    my_display_all(my_file, file);
  my_check_dir(buf, str, tar, opt);
  if (opt[ID_VERBOSE])
    printf("%s\n", str);
  free(buf);
  free(my_file);
  if (fclose(file) == -1)
    my_puterror(1, errno);
}
