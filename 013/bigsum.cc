#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bigsum.h"

int sum_and_carry(const int b_offset, const long carry) {
  const int e_offset = b_offset + 9;

  char buf[1000];
  long buf_n;

  long sum = carry;
  for (auto i = 0; i < NUMBERS_CNT; ++i) {
    strncpy(buf, numbers[i] + b_offset, e_offset - b_offset + 1);
    buf[e_offset - b_offset + 1] = 0;

    buf_n = strtol(buf, NULL, 10);
    sum += buf_n;
  }

  printf("Sum for offset %d: %ld\n", b_offset, sum);
  return sum / 1e10;
}

int main (void) {
  int carry = 0;

  for (int offset = 40; offset >= 0; offset -= 10)
    carry = sum_and_carry(offset, carry);

  return 0;
}
