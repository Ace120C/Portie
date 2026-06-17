#include "search.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int search(char *sarg) {
  chdir("/usr/ports/");

  pid_t pid = fork();
  if (pid == -1) {
    perror("memerror");
  }
  
  char *args[] = {"grep", "-i", sarg, ".INDEX", NULL};
  if (pid == 0) {
    execvp("grep", args);
  } else {
    waitpid(pid, NULL, 0); 
  }
  return 0;
}
