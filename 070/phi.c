#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#define CAP 10000000
#define CAP_LENGTH 8

inline int permutation(int a, int b){
  static int a_digits[CAP_LENGTH];
  static int b_digits[CAP_LENGTH];
  static int i,j, a_length, b_length;

  i=0;
  do{
    a_digits[i]=a%10;
    i++;
  } while( (a/=10)!=0 );
  a_length=i;

  i=0;
  do{
    b_digits[i]=b%10;
    i++;
  } while( (b/=10)!=0 );
 
  if(a_length!=i)
    return 0; //even digit number differ between a and b
  b_length=i;

   for(i=0; i<a_length; i++){
    // cycle on all a digits
    for (j=0; j<b_length; j++){
      // cycle on all the (remaining, valid) b digits
      if(a_digits[i]==b_digits[j]){
	b_digits[j]=-1;
	break;
      }

    }

    if(j==b_length)
      return 0;
  }

  return 1;
}

void doit(){
  int i,j,n,best=-1;
  int phi[CAP];
  double result = CAP;

  for(i=1; i<=CAP; i++)
    phi[i-1]=1; //init

  printf("Phi init DONE\n");

  for (i=2; i<=CAP; i++){
    // cycle on  numbers

    if (phi[i-1] == 1){
      // if 'i' is a prime
      phi[i-1]=i-1;
      if (i<=CAP/2)
	for (j=(2*i); j<=CAP; j+=i){
	  // apply the rule to its multiples 'j'
	  n=i;
	  while(n<=j/i && j%(n*i) == 0)
	    n *= i;

	  phi[j-1]*=(i-1)*(n/i);
	}
    }
    // end cycle
  }
  // now phi is set up
  printf("Phi calculation DONE\n");

  for (i=2; i<=CAP; i++){
    if ( ( ((double)i)/phi[i-1] ) < result
	   && permutation(i,phi[i-1]) ){
      result = ( ((double)i)/phi[i-1] );
      best = i;
      // printf("i: %d; phi: %d; res: %lf\n",i,phi[i-1],result);
    }
  }

  printf("Solution: %d\n", best);

  // problem 69 extension
  result=0;
  for (i=2; i<=1000000; i++){
    if ( ( ((double)i)/phi[i-1] ) > result ){
      result = ( ((double)i)/phi[i-1] );
      best = i;
    }
  }
  printf("Solution: %d, result: %lf\n", best, result);

  return ;
}

int main (void){
  struct rlimit rlim;
  getrlimit(RLIMIT_STACK, &rlim);
  rlim.rlim_cur=rlim.rlim_max;
  setrlimit(RLIMIT_STACK, &rlim);
  doit();
  return 0;
}
