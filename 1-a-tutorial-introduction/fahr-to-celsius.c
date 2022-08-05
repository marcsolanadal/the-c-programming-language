#include <stdio.h>

#define LOWER 0
#define UPPER 50
#define STEP 5

void printTempTable(float (*formulaFn)(float));
float fahrToCelsius(float fahr);
float celsiusToFahr(float celsius);

int main () {
  printf("%3c %6c\n", 'C', 'F');
  printTempTable(celsiusToFahr);
  
  printf("\n------------------\n");

  printf("%3c %6c\n", 'F', 'C');
  printTempTable(fahrToCelsius);
}

void printTempTable(float (*formulaFn)(float)) {
  for (int i = LOWER; i < UPPER; i += STEP) {
    printf("%3d %6.1f\n", i, formulaFn((float) i));
  }
} 

float fahrToCelsius(float fahr) {
  return (5.0/9.0) * (fahr - 32.0);
}

float celsiusToFahr(float celsius) {
  return ((9.0/5.0) * celsius) + 32.0;
}
