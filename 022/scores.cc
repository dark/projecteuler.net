#include <stdio.h>

#include "scores.h"

int main (void) {
  long total = 0;

  for (int i = 0; i < NAMES_COUNT; ++i) {
    long name_score = 0;
    for (int c = 0; names[i][c] != 0; ++c) {
      name_score += names[i][c] - 'A' + 1;
    }

    total += (i + 1) * name_score;
  }

  printf("total: %ld\n", total);
  
  return 0;
}
