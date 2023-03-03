// This program computes base^exponent % modulus for HUGE numbers
#include <stdio.h>

#include <pthread.h>

// Jacob Knox CST 240 HW7 3/8/2023

// use constants for the base and modulus
const int BASE = 123456781;
const int MODULUS = 666666666;

// This function computes base^exponent % modulus
void * compute(void* exponent) {
  int result = 1;
  // cast the void* to an int* and dereference it to get the value
  int exp = *((int*)exponent);
  // do the computation
  for (int i = 0; i < exp; i++)
    result = (result * BASE) % MODULUS;

  // print the result
  printf("Result is %d\n", result);
}

int main() {
  int result;

  // exponent values
  int exponents[] = {2111222330, 2111222333, 2111222332, 2111222334, 2111222331, 2111222336, 2111222335, 2111222338, 2111222337, 2111222339};
  int num_exponents = sizeof(exponents) / sizeof(int);

  // thread variables
  pthread_t threads[10] = {0};
  // start the threads
  for (int i = 0; i < num_exponents; i++) {
    // create a thread with thread[i] running the compute function with the i'th exponent
    pthread_create(&threads[i], NULL, compute, &(exponents[i]));
  }

  // wait for the threads to finish
  for (int i = 0; i < num_exponents; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
