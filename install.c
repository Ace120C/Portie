#include "install.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int install(char *iarg)
{
  chdir("/usr/ports/");
  chdir(iarg);

  pid_t pid = fork();
  if (pid == -1) {
    perror("memerror");
  }

  char *args[] = {"make", NULL};
  if (pid == 0) {
    execvp("make", args);
  } else {
    waitpid(pid, NULL, 0);
  }

  pid = fork();
  if (pid == -1) {
    perror("memerror");
  }

  char *InstallArgs[] = {"make", "install", NULL};
  if (pid == 0) {
    execvp("make", InstallArgs);
  } else {
    waitpid(pid, NULL, 0);
  }
  return 0;
}
