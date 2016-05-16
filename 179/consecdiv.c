#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#define CAP 10000000

void doit(){
  int i,j,n,index;
  int result=0;
  int divnum[CAP];

  divnum[0]=1;
  for(i=2; i<=CAP; i++)
    divnum[i-1]=0; //init

  for (i=2; i<=CAP; i++){
    // cycle on  numbers
    if (divnum[i-1] == 0){
      divnum[i-1]=2;

      // if 'i' is a prime
      if (i<=CAP/2)
	for (j=(2*i); j<=CAP; j+=i){
	  // apply the rule to its multiples 'j'
	  n=i;
	  index=1;
	  while(n<=j/i && j%(n*i) == 0){
	    n *= i;
	    index++;
	  }

	  if (divnum[j-1] == 0)
	    // if 'j', till now, was thought to be a prime
	    divnum[j-1] = index+1;
	  else
	    // if previously we already found
	    divnum[j-1] *= index+1;
	}
    }
    // end cycle

    if(divnum[i-1] == divnum[i-2])
      result++;
  }

  printf("Solution: %d\n", result);

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
