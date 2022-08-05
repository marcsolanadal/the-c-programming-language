#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\b':
        putchar('\\');
        c = 'b';
        break;
      case '\t':
        putchar('\\');
        c = 't';
        break;
      case '\\':
        putchar('\\');
        c = '\\';
        break;
      default:
        putchar(c);
        break;
    }
  }
}
