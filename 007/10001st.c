#include <stdio.h>
#define L 1000000

int main (void){
  char n[L];
  int i,j;
  int test=0;

  for (i=0; i<L; i++)
    n[i]=0;

  for (i=2; i<1000; i++){
    if (n[i-1]==0){
      for (j=(2*i)-1; j<L; j+=i)
	n[j]=1;
    }
  }
  
  for (i=0; i<L; i++)
    if (!n[i]){
      test++;
      if (test==10002)
	break;
    }

  printf("%d\n", i+1);

  return 0;
}
