/* Function itoa_2: update and fix bug itoa */

#include <limits.h>

void reverse3_4(char s[]);

static void itoa_2(int n, char s[]) {
	int i = 0, sign;

	if ((sign = n) < 0) {
			n = -n;
	}
	if (n == INT_MIN) {
		do {
			s[i++] = -(n % 10) + '0';
		} while (-(n = n / 10) > 0);
	}
	else {
		do {
			s[i++] = (n % 10) + '0';
		} while ((n = n / 10) > 0);
	}

	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	
	reverse3_4(s);

	printf("%s\n", s);
}

static void reverse3_4(char s[]) {
	int i, j, c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		/*c = s[j];
		s[j] = s[i];
		s[i] = c;*/

		// Or
		c = s[j], s[j] = s[i], s[i] = c;
	}
}