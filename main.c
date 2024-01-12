#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int   main(int ac, char **av)
{
  char  *line;
  int   fd1;

  fd1 = open("test.txt", O_RDONLY);
  line = get_next_line(fd1);
  printf("%s\n", line);
  free(line);
  line = get_next_line(fd1);
  printf("%s\n", line);
  free(line);
  return (0);
}
