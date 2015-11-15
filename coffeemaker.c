#include <stdio.h>
#include <stdlib.h>

#define FLOZ_PER_CUP 6.0
#define GRAMS_PER_CUP 10.0
#define TBSP_PER_CUP 2.0

int main(int argc, char *argv[])
{
  unsigned long floz;

  // Check for floz argument
  if (argc > 1) {
    sscanf(argv[1], "%lu", &floz);
  } else { // Prompt for coffee
    char input[8];
    printf("How many fluid ounces of coffee are you making? ");
    fgets(input, sizeof(input), stdin);
    floz = strtol(input, (char** restrict)NULL, 0);
  }

  // Calculate beans
  double cups  = floz / FLOZ_PER_CUP;
  double grams = cups * GRAMS_PER_CUP;
  double tbsp  = cups * TBSP_PER_CUP;

  // Report
  printf("%lu fl.oz. of brewed coffee will require ", floz);
  printf("%.2f grams (about %.2f tbsp) of beans.\n", grams, tbsp);

  return 0;
}
