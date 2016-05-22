#include <stdio.h>

#define DISCARD ((long)1e11)

long pow_with_discard(const int base) {
  long buf = base;

  int count = 1;
  for (; count < base; ++count)
    buf = (buf * base) % DISCARD;

  return buf;
}

int main(void) {
  long sum = 0;

  int count = 1;
  for (; count <= 1000; ++count)
    sum = (sum + pow_with_discard(count)) % DISCARD;

  printf("%ld\n", sum);
  return 0;
}
