/* trl.c timed read line */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/* timed read line */
char *trl(int timeout)
{
  static char buf[512];
  fd_set rfds;
  struct timeval tv = {
    .tv_sec = timeout, 
    .tv_usec = 0
  };
  int ret;

  FD_ZERO(&rfds);
  FD_SET(0, &rfds);

  ret = select(1, &rfds,NULL,NULL,&tv);
  if (ret && FD_ISSET(0, &rfds))
  {
    memset(buf, 0, 512);
    ret = read(0, buf, 511);
    if (ret < 1)
      return 0;
    ret--;
    buf[ret] = 0;

    return buf;
  }
  else
    return 0;
}

int main() {
  char *name;

  printf("name please \n");
  name = trl(3);
  if (name)
    printf("hello %s\n", name);
  else
    printf("too slow\n");
  return 0;
}
