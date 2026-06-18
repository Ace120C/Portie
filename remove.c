#include <stdio.h>
#include <unistd.h>
#include "remove.h"
#include <sys/wait.h>

int port_remove(char *rarg)
{
  chdir("/usr/ports");
  chdir(rarg);

  pid_t pid = fork();
  if (pid == -1) {
    perror("memerror");
  }

  char *args[] = {"make", "remove", NULL};

  if (pid == 0) {
    execvp("make", args);
  } else {
    waitpid(pid, NULL, 0);
  }

  return 0;
}
