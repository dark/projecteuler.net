#include <stdio.h>
#define L 2000000

int main (void){
  char n[L];
  int i,j;
  long long sum=0;

  for (i=0; i<L; i++)
    n[i]=0;

  for (i=2; i<2000; i++){
    if (n[i-1]==0){
      for (j=(2*i)-1; j<L; j+=i)
	n[j]=1;
    }
  }
  
  for (i=1; i<L; i++)
    if (!n[i]){
      sum+=(i+1);
      //printf("%d\n", i);
    }

  printf("%lld\n", sum);

  return 0;
}
