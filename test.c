#include <stdio.h>

int main() {
  char *filename = "collins.txt";
  char *write = 'w';

  // Create a file on your computer (filename.txt)
  FILE *fptr = fopen(filename, write);

  // Close the file
  fclose(fptr);

  return 0;
}