#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
  if (ac != 2)
    return(0);
  usleep(atoi(av[1]));
  return (1);
}
