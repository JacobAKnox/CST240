#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int convert_to_int(char *string) {//takes the string and returns the int version
	size_t i;

	for (i = 0; i < strlen(string)-1; i++) {//loop over to make sure all the charcters are numbers
		if (isdigit(string[i]) == 0) {
			return -1;
		}
	}
	return atoi(string); //convert to int
}

int is_prime(int number) { // check if number is prime
	int flag = 0;
	int i;
	if (number == 0 || number == 1) { // 0 and 1 are not prime
		return 1;
	}
	if (number == 2) { // 2 is prime
		return 0;
	}

	for (i = 2; i <= number/2.0; i++) { //check that no ints from 2-half of number have a remainder of 0
		float remainder = number % i;
		if (remainder == 0) {
			flag = 1;
			break;
		}
	}
	return flag;
}

void print_number(char* n) {
	char *conversions[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
				"SIX", "SEVEN", "EIGHT", "NINE"}; //conversion table from int to string
	char str[2] = {'\0', '\0'};
	size_t i;

	for (i = 0; i < strlen(n); i++) {//loop backwards and print string for each char
		str[0] = n[i];
		printf("%s ", conversions[atoi(str)]);
	}
}


int main (int argc, char **argv) {
	int number = 0;
	size_t i;
	if (argc < 2) { //make sure agrs are passed
		printf("You must input at least one number as an argument\n");
		return 1;
	}

	for (i = 1; i < argc; i++) { //loop over each arg
		number = convert_to_int(argv[i]);
		if (number < 0) { // make sure it is positive and a number
			printf("Input value must be a integer (\"123\", \"333\", etc.) and positive\n");
			return 2;
		}

		print_number(argv[i]);
		if (is_prime(number) == 0) { //check for prime and print
			printf("IS Prime!\n");
		} else {
			printf("is NOT Prime!\n");
		}
	}
}
