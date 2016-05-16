#include <stdio.h>
#define L 1000000

int main (void){
  int i,j, res;
  int max=0;

  for (i=999; i>101; i--)
    for(j=i-1; j>101; j--){
      res=i*j;
      
      if (res%10 == res/100000 &&
	  (res/10)%10 == (res/10000)%10 &&
	  (res/100)%10 == (res/1000)%10 &&
	  res > max)
	max = res;
    }

  printf("%d\n", max);
  return 0;
}
