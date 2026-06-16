#include "bootstrap.h"
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
  if (argc > 1 && strcmp(argv[1], "bootstrap") == 0) {
    bootstrap_ports();
  } else {
  printf("help \n");
  }

  char targetDir[1024];
  if (strcmp(targetDir, "ports/") == 0) {
    printf("you're already in ports\n");
  } else {
  printf("you are not in ports\n");
  }
  return 0;
}
