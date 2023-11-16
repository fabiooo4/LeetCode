#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isValid(char *s) {
  char open[7];
  int j = 0;

  for (int o = 0; o < 7; o++) {
    open[o] = ' ';
  }

  for (int i = 0; i < 14; i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      open[j] = s[i];
    }

    if (s[i] == ')' && open[j - 1] == '(') {
      open[j - 1] = ' ';
    } else if (s[i] == ']' && open[j - 1] == '[') {
      open[j - 1] = ' ';
    } else if (s[i] == '}' && open[j - 1] == '{') {
      open[j - 1] = ' ';
    } else {
      break;
    }

    printf("i = %d\n", j);
    printf("j = %d\n", i);
  }

  printf("%s\n", open);
  printf("%s\n", s);

  for (int o = 0; o < 7; o++) {
    if (open[o] == ' ') {
      printf("The string is valid\n");
      return true;
    } else {
      printf("The string is not valid\n");
      break;
    }
  }
  return false;
}

int main() {
  char *s[14];
  *s = "()";
  isValid(*s);
}
