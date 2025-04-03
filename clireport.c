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
	
	int exitCode;
	if ((argc >= 3) && (strncmp(argv[1], "--exit", 7) == 0)) {
		char *endptr = NULL;
		errno = 0;
		exitCode = (int) strtol(argv[2], &endptr, 10);
		
		if ((errno != 0) || *endptr) {
			printf("Exit code \"%s\" is not valid, using -1 instead\n", argv[2]);
			exitCode = -1;
		} else {
			printf("Exit code \"%s\" (%d) is valid\n", argv[2], exitCode);
		}
	} else {
		printf("Exit code was not specified\n");
		exitCode = 0;
	}
	
	// Use both for portability
	exit(exitCode);
	return exitCode;
}
