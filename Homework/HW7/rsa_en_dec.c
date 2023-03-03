// This program computes base^exponent % modulus for HUGE numbers

// Jacob Knox CST 240 HW7 3/8/2023

#include <stdio.h>

int main() {
  // declare the variables
  int base = 123456781;
  int exponent = 2111222331;
  int modulus = 666666666;
  int result;
  result = 1;

  // do the computation
  for (int i = 0; i < exponent; i++)
    result = (result * base) % modulus;

  // print the result
  printf("Result is %d\n", result);

  return 0;
}
