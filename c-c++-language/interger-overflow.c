#include <stdio.h>

int main(int argc, char** argv)
{
	long i = -1; // variable i is converted to unsigned integer

	printf("%d\n", sizeof(i)); // long is 8 bytes

	printf("%ld\n", i);

	if (i < sizeof(i)) { 
	// here the return type of sizeof() is long unsigned int , so the i is already not -1
		printf("OK\n");
	}
	else {
		//If the operand that has unsigned integer type has rank greater or equal 
		//to the rank of the type of the other operand, then the operand with 
		//signed integer type is converted to the type of the operand with unsigned integer type.
		printf("error\n");
	}

	return 0;
}

