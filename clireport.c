#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	printf("CLIReport: %d arguments\n", argc);
	for (int i = 0; i < argc; i++) {
		char* argument = argv[i];
		printf("%04d: %s\n", (unsigned)strlen(argument), argument);
	}
	return 0;
}
