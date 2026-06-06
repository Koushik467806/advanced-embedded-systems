#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
  FILE *f = fopen("nothing.txt", "r");

  if (f == NULL) {
    printf("Error: %s\n", strerror(errno));
    return 1;
  }

  fclose(f);
  return 0;
}

// strerror(errno) -> Provides error numbers and errno converts them into a message
// ENOENT: No such file or directory
// EACCES: Permission denied
// ENOMEM: Out of memory
// ETIMEDOUT: The connection timed out

// Search for man 3 errno for more codes

// Use exit() like this:
// exit(0): exits the program
// exit(1): Something went wrong