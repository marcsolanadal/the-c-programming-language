#include <stdio.h>

typedef struct Histogram {
  int digit_count[10];
  int whitespace_count;
  int other_count;
} Histogram;

void Histogram_printBar(int length);
void Histogram_print(Histogram *hist);
void Histogram_count(Histogram *hist);

int main() {
  Histogram hist = { 0 };

  Histogram_count(&hist);
  Histogram_print(&hist);
  
  return 0;
}

void Histogram_count(Histogram *hist) {
  int c;
  while((c = getchar()) != EOF) {
    if(c == ' ') {
      hist->whitespace_count += 1;
    } else if(c >= '0' && c <= '9') {
      hist->digit_count[c-'0'] += 1;
    } else {
      hist->other_count += 1;
    }
  }
}

void Histogram_printBar(int length) {
    printf("|");
    for(int i = 0; i < length; i++) {
      printf("==");
    } 
    printf(">\n");
}

void Histogram_print(Histogram *hist) {
  printf("--------------------------------------------\n");
  printf("HISTOGRAM\n");
  printf("--------------------------------------------\n\n");

  for(int i = 0; i < 10; i++) {
    printf("%10d", i);
    Histogram_printBar(hist->digit_count[i]);
  }
 
  printf("%10s", "Space");
  Histogram_printBar(hist->whitespace_count);

  printf("%10s", "Other");
  Histogram_printBar(hist->other_count);
}
