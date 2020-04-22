/*
 * UWU TRANSLATOR
 */

#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 8

/* get string of arbitrary size */
static size_t
getsd(char **buf) //written by 0x1bi
{
	int c, n = INIT_SIZE;
	char *ptr = (*buf = (char *) malloc(n));
	while ((c = getchar()) != 0xA) {
		*ptr++ = c;
		if ((ptr - *buf) == n) {
			*buf = (char *) realloc(*buf, (n *= 2));
			ptr = *buf + n/2;
		}
	}
	*ptr = '\0';
	return n;
}

/* change string into uwu */
static void
uwu(char *s)
{
	if (!s)
		return;
	for (; *s != '\0'; s++) {
		switch (*s) {
		case 'L':
		case 'l':
			*s += 11;
			break;
		case 'R':
		case 'r':
			*s += 5;
			break;
		}
	}
}

int
main(int argc, char *argv[])
{

	char *s = NULL;

	printf("Enter a phrase: ");
	getsd(&s);

	uwu(s);
	printf("\nuwu: %s\n", s);

	free(s);

}
