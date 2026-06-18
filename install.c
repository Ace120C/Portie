#include "install.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

int install(char *iarg)
{
  chdir("/usr/ports/");
  chdir(iarg);

  struct stat st;

  if (stat("src", &st) == 0) {
    pid_t pid = fork();

    if (pid == -1) {
      perror("memerror");
    }

    char *install_args[] = {"make", "install", NULL};

    if (pid == 0) {
      execvp("make", install_args);
    } else {
      waitpid(pid, NULL, 0);
    }

    exit(0);
  }

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
