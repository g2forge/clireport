#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
	printf("CLIReport: %d arguments\n", argc);
	for (int i = 0; i < argc; i++) {
		char* argument = argv[i];
		printf("%04d: %s\n", (unsigned)strlen(argument), argument);
	}
	
	if ((strncmp(argv[1], "--exit", 7) == 0) && (argc >= 3)) {
		char *endptr = NULL;
		errno = 0;
		int exitCode = (int) strtol(argv[2], &endptr, 10);
		
		if ((errno != 0) || *endptr) {
			printf ("Exit code \"%s\" is not valid\n", argv[2]);
		}
		
		return exitCode;
	}
	
	return 0;
}
