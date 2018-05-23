#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *ptr;
	char *ptr2;
	if(argc < 3) {
		printf("Usage: %s <environment var> <target program name>\n", argv[0]);
		exit(0);
	}
	ptr = getenv(argv[1]); /* Get env var location. */
	ptr2 = ptr;
	ptr2 += (strlen(argv[0]) - strlen(argv[2]))*2; /* Adjust for program name. */
	printf("%s will be at %p with value = %s\n", argv[1], ptr2, ptr);
	return 0;
}