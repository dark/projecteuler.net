#include <set>
#include <stdio.h>
#include <math.h>

#define LIMIT 1000000

std::set<int> primes;

void gen_primes(int limit) {
  for (int n = 2; n <= limit; ++n)
    primes.insert(n);

  int sqrt_limit = sqrt(limit);
  for (int cursor = 2; cursor < sqrt_limit; ++cursor){
    if (primes.count(cursor) == 1) {
      for (int multiple = (2*cursor); multiple < limit; multiple += cursor)
	primes.erase(multiple);
    }
  }
}

bool try_stride(const int stride) {
  //printf("Trying stride: %d\n", stride);

  int sum = 0;
  std::set<int>::iterator head = primes.begin();
  // init the sum with the initial stride
  for (int i = 0; i < stride; ++i) {
    sum += *head;
    ++head;
    // this stride will go nowhere, the initial sum is too large already
    if (sum > LIMIT)
      return false;
  }

  // the main loop
  std::set<int>::iterator tail = primes.begin();
  while (true) {
    // this stride will go nowhere, the sum just became too large
    if (sum > LIMIT)
      return false;

    if (primes.count(sum)) {
      // found it
      printf("Prime %d is the sum of %d consecutive primes\n", sum, stride);
      return true;
    }

    // advance the window, if possible
    if (head == primes.end())
      break; // no more primes to try

    sum += *head;
    sum -= *tail;
    ++head;
    ++tail;
  }
  
  return false;
}

void try_strides() {
  const int max_stride = primes.size();
  for (int stride = max_stride; stride > 1; --stride) {
    if (try_stride(stride))
      return;
  }
  printf("Could not find a stride?\n");
}

int main(void) {
  gen_primes(LIMIT);
  printf("%ld primes under limit of %d\n", primes.size(), LIMIT);

  try_strides();
  
  return 0;
}
