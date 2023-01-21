#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int CtoF(int c) { //converts an int from celsius to fahrenheit
	return (c * 9/5) + 32;
}

int FtoC(int f) { //converts an int from fahrenheit to celsius
	return (f - 32) * 5/9;
}

void print_temps(char str[], size_t len) { //prints the temp in both F and C
	int temp;
	char units;

	temp = atoi(str);
	units = str[len-1];

	if (units == 'C') {
		printf("Celsius degree is %d\n", temp);
		printf("Fahrenheit degree is %d\n", CtoF(temp));
	} else {
		printf("Celsius degree is %d\n", FtoC(temp));
		printf("Fahrenheit degree is %d\n", temp);
	}
}

int get_C_or_F() { //gets C or F units from user
	char c;

	printf("Enter C for Celsius, F for Fahrenheit: ");
	scanf(" %c", &c);

	while (c != 'C' && c != 'F') {
		printf("Wrong character, must enter C for Celsius, F for Fahrenheit: ");
		scanf(" %c", &c);	
	}
	
	return c;
}

void check_units(char str[], size_t *len) { // makes sure the units are C or F, and prompts if they are not
	if (str[*len-1] != 'C' && str[*len-1] != 'F') {
		str[*len] = get_C_or_F();
		str[++*len] = '\0';
	}
}

int normalize(char str[], size_t *len) { //makes sure the string is in the format of an integer followed by a charcter
	size_t i;

	if (isdigit(str[*len-1])) {
		str[*len] = 'C';
		str[++*len] = '\0';
	}
	
	for (i = 0; i < *len-1; i++) {
		if (isdigit(str[i]) == 0) {
			return -1;
		}
	}
	
	return 0;
} //returns 0 if the string is only numbers and an optional charcter, -1 if it is not
 //adds a C to the end of the string if it is only numbers

int main() {
	char str[100];
	size_t len;

	printf("Enter string with integer appended by \\0 or a single charcter: ");
	scanf("%s", str); //get string from user

	len = strlen(str);

	if (normalize(str, &len) == -1) { //make sure the string is in the correct format
		printf("Wrong input, must be integer appended by \\0 or a single charcter\n");
		return 1;
	}
	check_units(str, &len); //make sure the units are C or F
	print_temps(str, len); //print the temps in both C and F
}
