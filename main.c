#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  chdir("/usr/");
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork failed: not enough memory");
  }
  char *args[] = {"ls", NULL};
  if (pid == 0) {
    execvp("ls", args);
    perror("ececvp failed");
  } else {
    waitpid(pid, NULL, 0);
  }
  return 0;
}
