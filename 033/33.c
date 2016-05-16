#include <stdio.h>

#define EQUAL(n1,d1,n2,d2) (((n1)*(d2) == (n2)*(d1)))

int main (void){
  int num, den;

  for(num=10; num<=99; ++num)
    for (den=num+1; den<=99; ++den)
      {
        int n_1 = num / 10;
        int n_2 = num % 10;
        int d_1 = den / 10;
        int d_2 = den % 10;

        if (n_2 == 0 && d_2 == 0)
          continue;
        if ( (n_1 == d_1 && EQUAL(num,den,n_2,d_2)) ||
             (n_1 == d_2 && EQUAL(num,den,n_2,d_1)) ||
             (n_2 == d_1 && EQUAL(num,den,n_1,d_2)) ||
             (n_2 == d_2 && EQUAL(num,den,n_1,d_1)))
          printf("%d %d\n", num, den);
      }
  return 0;
}
