#include <stdio.h>
char *strcpy(char *dest, const char *src);


int main() {
  char buffer[32] = {0};
  strcpy(buffer, "poop");
  printf("%s\n", buffer);
  strcpy(buffer, "butts");
  printf("%s\n", buffer);
  return 0;
} //program should output:
// poop
// butts