/* Function expand(s1, s2): expands shorthand notation in s1 
   into complete list in s2 such as a-z into abc .... xyz */

#include <string.h>

static void expand(char s1[], char s2[]) {
	int index_1, index_2 = 0;

	for (index_1 = 0; index_1 < strlen(s1); index_1++) {
		if (s1[index_1] == '-') {
			if (index_1 == 0) {
				s2[index_2++] = s1[index_1];
			}
			else if ((index_1 > 0) && (s1[index_1 - 1] == ' ' || s1[index_1] == '\t')) {
				s2[index_2++] = s1[index_1];
			}
			else if ((index_1 > 0) && (s1[index_1 + 1] == '-')) {
				s2[index_2++] = s1[index_1];
			}
			else {
			}
		}
		else {
			s2[index_2++] = s1[index_1];
		}
	}
}
