#include "bootstrap.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "search.h"
#include "install.h"

int main(int argc, char *argv[])
{
  if (argc > 1 && strcmp(argv[1], "bootstrap") == 0) {
    bootstrap_ports();
  } else if (argc > 1 && strcmp(argv[1], "search") == 0) {
    search(argv[2]);
  } else if (argc > 1 && strcmp(argv[1], "install") == 0) {
    printf("Install Started!\n");
    install(argv[2]);
    printf("Install Complete.\n");
  }
  return 0;
}
