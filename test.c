#include <stdio.h>
#include <string.h>

char placeholder(char *input)
{
	input[0] += 10;
	return *input;
}

int main()
{
	char test[5];
	strcpy(test, "test");
	placeholder(test);
	printf("%s\n", test);
}
