#include <stdio.h>

int main(void) {
  long int sum = 0;
  int old1, old2, cur;

  old1 = 1;
  old2 = 2;
  sum = 2;
  while (1) {
    cur = old1 + old2;
    if (cur > 4000000)
      break;
    if (cur % 2 == 0)
      sum += cur;
    old1 = old2;
    old2 = cur;
  }

  printf("%ld\n", sum);
  return 0;
}
