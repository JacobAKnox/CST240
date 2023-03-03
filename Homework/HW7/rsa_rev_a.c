// This program computes base^exponent % modulus for HUGE numbers
#include <stdio.h>

// Jacob Knox CST 240 HW7 3/8/2023

// This function computes base^exponent % modulus
int compute(int base, int exponent, int modulus) {
  int result = 1;
  // do the computation
  for (int i = 0; i < exponent; i++)
    result = (result * base) % modulus;

  return result;
}

int main() {
  // constant bases and moduli
  int base = 123456781;
  int modulus = 666666666;
  int result;

  // exponent values
  int exponents[] = {2111222330, 2111222333, 2111222332, 2111222334, 2111222331, 2111222336, 2111222335, 2111222338, 2111222337, 2111222339};
  int num_exponents = sizeof(exponents) / sizeof(int);

  // compute and print the results
  for (int i = 0; i < num_exponents; i++) {
    result = compute(base, exponents[i], modulus);
    printf("Result is %d\n", result);
  }

  return 0;
}
