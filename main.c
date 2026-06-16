#include <asm-generic/errno-base.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


int main()
{
  printf("Checking /usr/ports....\n");
  chdir("/usr");
  char targetDir[1024];
  getcwd(targetDir, sizeof(targetDir));

  if (strcmp(targetDir, "/usr") == 0) {
    if (mkdir("/usr/ports", 0777) == -1) {
      if (errno == EEXIST) {
        printf("Ports Already exist!");
      }  else if (errno == EACCES) {
        perror("Portie");
        printf("try running this with sudo/doas!\n");
        exit(1);
      }
    }
  } else {
    perror("Portie");
    exit(1);
  }
  printf("Sucess!\n");
  return 0;
}
