#include <stdio.h>
#define CAP 1000000

int main (void){
  int i,steps;
  unsigned long n;
  int optimize[CAP];
  int best_chain = 0;
  int best_generator = 0;

  for(i=0; i<CAP; i++)
    optimize[i]=0; //AKA I will try this

  for (i=2; i<=CAP; i++){
    steps=0;
    n=i;
    do{
      steps++;
      if(n % 2 == 1){
	// odd
	n = 3*n + 1;
      }
      else{
	// even
	n >>= 1;
      }

      if (n<=CAP && optimize[n-1]!=0){
	// try to optimize an already partially solved solution
	steps += optimize[n-1];
	break;
      }
    } while (n!=1);

    optimize[i-1]=steps;
    if (steps>best_chain){
      best_chain=steps;
      best_generator=i;
    }

    // end cycling on all numbers
  }

  printf("Solution: %d, generated by: %d\n", best_chain, best_generator);
  return 0;
}
