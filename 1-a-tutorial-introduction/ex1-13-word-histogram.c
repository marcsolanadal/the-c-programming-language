#include <stdio.h>

void Histogram_printBar(int length);
void Histogram_print(int numbers[], int whitespace_count, int other_count);

typedef struct Histogram {
  int digit_count[10];
  int whitespace_count;
  int other_count;
} Histogram;

int main() {
  int c, word_count, whitespace_count, other_count;
  int digit_count_list[10];

  word_count = whitespace_count = other_count = 0;

  // Count ocurrences
  while((c = getchar()) != EOF) {
    if(c == ' ') {
      whitespace_count += 1;
    } else if(c >= '0' && c <= '9') {
      ++digit_count_list[c-'0'];
    } else {
      other_count += 1;
    }
  }

  Histogram_print(digit_count_list, whitespace_count, other_count);
  
  return 0;
}

void Histogram_printBar(int length) {
    printf("|");
    for(int i = 0; i < length; i++) {
      printf("==");
    } 
    printf(">\n");
}

void Histogram_print(int numbers[], int whitespace_count, int other_count) {
  printf("--------------------------------------------\n");
  printf("HISTOGRAM\n");
  printf("--------------------------------------------\n\n");

  for(int i = 0; i < 10; i++) {
    printf("%10d", i);
    Histogram_printBar(numbers[i]);
  }
 
  printf("%10s", "Space");
  Histogram_printBar(whitespace_count);

  printf("%10s", "Other");
  Histogram_printBar(other_count);
}
