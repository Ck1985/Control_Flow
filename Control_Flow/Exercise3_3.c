/* Function expand(s1, s2): expands shorthand notation in s1 
   into complete list in s2 such as a-z into abc .... xyz */

#include <string.h>

static void expand(char s1[], char s2[]) {
	int index_1, index_2 = 0;

	for (index_1 = 0; index_1 < strlen(s1); index_1++) {
		if (s1[index_1] == '-') {
			int k = 2, countSign = 1;
			while (s1[index_1 + k] == '-') {
				countSign++;
				k = k + 2;
			}
			if (countSign > 1) {
				for (int i = 1; i <= k + 1; i++) {
					s2[index_2++] = s1[index_1++];
				}
				index_1--;
			}
			else {
				if (index_1 == 0) {
					s2[index_2++] = s1[index_1];
				}
				else if ((!((s1[index_1 - 1] >= 48) && (s1[index_1 - 1] <= 57))) && (!((s1[index_1 - 1] >= 65) && (s1[index_1 - 1] <= 90))) && (!((s1[index_1 - 1] >= 97) && (s1[index_1 - 1] <= 122)))) {
					s2[index_2++] = s1[index_1];
				}
				else if ((!((s1[index_1 + 1] >= 48) && (s1[index_1 + 1] <= 57))) && (!((s1[index_1 + 1] >= 65) && (s1[index_1 + 1] <= 90))) && (!((s1[index_1 + 1] >= 97) && (s1[index_1 + 1] <= 122)))) {
					s2[index_2++] = s1[index_1];
				}
				else {
					int next;
					next = s1[index_1 - 1];
					for (int i = 1; i < (s1[index_1 + 1] - s1[index_1 - 1]); i++) {
						s2[index_2++] = ++next;
					}
				}
			}
		}
		else {
			s2[index_2++] = s1[index_1];
		}
	}

	printf("s1 = %s\ns2 = %s\n", s1, s2);
}
