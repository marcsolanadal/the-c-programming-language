#include <stdio.h>

int main() {
  int current, previous;

  while((current = getchar()) != EOF) {
    if (previous != ' ') {
      putchar(current);
    }

    previous = current;
  }
}
