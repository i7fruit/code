#include <stdio.h>

int main() {
  char *filename = "collins.txt";

  // Create a file on your computer (filename.txt)
  FILE *fptr = fopen(filename, "a");

  fprintf(fptr, "I don't know. Find out.\n");

  // Close the file
  fclose(fptr);

  return 0;
}