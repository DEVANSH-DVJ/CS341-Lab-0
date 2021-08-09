#include "argparse.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  initArgs();

  addArg("-M");
  addArg("-N");
  addArg("-K");
  addArg("-L");
  addArg("-J");

  parseArgs(argc, argv);

  char *result = getArg("-J");

  if (result)
    printf("Found J: %s\n", result);

  cleanUp();

  free(result);

  return 0;
}
