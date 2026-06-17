#include "bootstrap.h"
#include <string.h>
#include <unistd.h>
#include "search.h"

int main(int argc, char *argv[])
{
  if (argc > 1 && strcmp(argv[1], "bootstrap") == 0) {
    bootstrap_ports();
  } else if (argc > 1 && strcmp(argv[1], "search") == 0) {
    search(argv[2]);
  }
  return 0;
}
