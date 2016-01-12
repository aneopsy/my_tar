/*
** my_dir.h for my_tar in /home/theis_p/Rush1/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sat Jan  9 05:10:06 2016 THEIS Paul
** Last update Sun Jan 10 16:33:14 2016 THEIS Paul
*/

#include "main.h"

t_my_header       *my_create_header(char *str)
{
  t_my_header	*my_file;
  int		i;

  if ((my_file = malloc(sizeof(*my_file))) == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  i = my_fill_elt(str, my_file->name, 0, 100);
  i = my_fill_elt(str, my_file->mode, i, i + 8);
  i = my_fill_elt(str, my_file->uid, i, i + 8);
  i = my_fill_elt(str, my_file->gid, i, i + 8);
  i = my_fill_elt(str, my_file->size, i, i + 12);
  i = my_fill_elt(str, my_file->mtime, i, i + 12);
  i = my_fill_elt(str, my_file->chksum, i, i + 8);
  my_file->typeflag = str[i++];
  i = my_fill_elt(str, my_file->linkname, i, i + 100);
  i = my_fill_elt(str, my_file->magic, i, i + 6);
  i = my_fill_elt(str, my_file->version, i, i + 2);
  i = my_fill_elt(str, my_file->u_name, i, i + 32);
  i = my_fill_elt(str, my_file->g_name, i, i + 32);
  i = my_fill_elt(str, my_file->devmajor, i, i + 8);
  i = my_fill_elt(str, my_file->devminor, i, i + 8);
  i = my_fill_elt(str, my_file->prefix, i, i + 167);
  return (my_file);
}

int			set_time(char *name, char *timer)
{
  struct utimbuf 	ubuf;

  ubuf.modtime = strtoul(timer, NULL, 8);
  time(&ubuf.actime);
  if (utime(name, &ubuf) != 0)
    fprintf( stderr, "error of time: %s", timer);
  return (1);
}

void		my_reader(int nbr, char *opt, int my_fd, int fd)
{
  char		buff[MAX_SIZE];
  int		len;

  while (nbr > 0)
    {
      my_init_char(buff, MAX_SIZE);
      if ((len = read(fd, buff, MAX_SIZE < nbr ? MAX_SIZE : nbr)) == -1)
	my_puterror(1, errno);
      if (!(opt[ID_TLIST]))
	write(my_fd, buff, len);
      nbr -= len;
    }
}

void		my_createfile(int fd, t_my_header *my_file, char *opt)
{
  char		buff[MAX_SIZE];
  mode_t	mode;
  uid_t		owner;
  gid_t		group;
  int		my_fd;
  int		nbr;
  int		len;

  my_convert_elt(&mode, &owner, &group, my_file);
  if (!(opt[ID_TLIST]))
    my_fd = 0;
    if ((my_fd = open(my_file->name, O_WRONLY | O_CREAT, mode)) == -1 ||
	fchown(fd, owner, group) == -1)
	my_puterror(1, errno);
  nbr = (int)strtoul(my_file->size, NULL, 8);
  my_reader(nbr, opt, my_fd, fd);
  if ((len = read(fd, buff, MAX_SIZE -
		  (int)strtoul(my_file->size, NULL, 8) % MAX_SIZE)) == -1)
    my_puterror(1, errno);
  close(my_fd);
  set_time(my_file->name, my_file->mtime);

  if (opt[ID_VERBOSE] || opt[ID_TLIST])
    printf("%s\n", my_file->name);
}

void		my_createdir(t_my_header *my_file, char *opt)
{
  char		*my_path;
  mode_t	mode;
  int		i;
  int		j;

  if ((my_path = malloc(2 + strlen(my_file->prefix) +
			strlen(my_file->name))) == NULL)
    my_puterror(0, 0);
  mode = strtol(my_file->mode, NULL, 8);
  i = 0;
  j = 0;
  while (my_file->prefix[j])
    my_path[i++] = my_file->prefix[j++];
  j = 0;
  while (my_file->name[j])
    my_path[i++] = my_file->name[j++];
  my_path[i] = '\0';
  if (!opt[ID_TLIST])
    if ((mkdir(my_path, mode)) == -1)
	my_puterror(1, errno);
  if (opt[ID_VERBOSE] || opt[ID_TLIST])
    printf("%s\n", my_path);
  free(my_path);
}
