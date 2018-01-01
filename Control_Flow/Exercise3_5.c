/* Function itob(n, s, b) convert integer n into a base b 
   character representation in string s */

#include <string.h>

void reverse3_5(char s[]);
void addOneBinary(char binArray[]);
void notBit(char s[]);
void convertBinary(int decimal, char s[]);

static void itob(int n, char s[], int b) {
	switch (b) {
	case 2:
		convertBinary(n, s);
		break;
	case 8: 
		break;
	case 16:

		break;
	default:
		break;
	}
}

static void convertHexal(int decimal, char s[]) {
	int i, sign;


}

static void convertBinary(int decimal, char s[]) {
	if (decimal >= 0) {
		int i = 0;

		do {
			s[i++] = decimal % 2 + '0';
		} while ((decimal = (decimal / 2)) > 0);

		s[i] = '\0';

		reverse3_5(s);
	}
	else {
		int i = 0, decimal2 = - decimal;

		do {
			s[i++] = decimal2 % 2 + '0';
		} while ((decimal2 = (decimal2 / 2)) > 0);

		reverse3_5(s);
		notBit(s);
		addOneBinary(s);

		s[i] = '\0';
	}
}

static void reverse3_5(char s[]) {
	int i, j, c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		/*c = s[j];
		s[j] = s[i];
		s[i] = c;*/

		// Or
		c = s[j], s[j] = s[i], s[i] = c;
	}
}

static void addOneBinary(char binArray[]) {
	int index, remember;
	char bit;

	index = strlen(binArray) - 1;
	bit = binArray[index];
	remember = 0;

	do {
		if (bit == '0' && remember == 0) {
			if (index == (strlen(binArray) - 1)) {
				binArray[index--] = '1';
				bit = binArray[index];
				remember = 0;
			}
			else {
				bit = binArray[index - 1] = '0';
				bit = binArray[index];
				remember = 0;
			}
		}
		else if (bit == '0' && remember == 1) {
			if (index == (strlen(binArray) - 1)) {
				bit = binArray[index--] = '0';
				bit = binArray[index];
				remember = 1;
			}
			else {
				bit = binArray[index--] = '1';
				bit = binArray[index];
				remember = 0;
			}
		}
		else if (bit == '1' && remember == 0) {
			if (index == (strlen(binArray) - 1)) {
				bit = binArray[index--] = '0';
				bit = binArray[index];
				remember = 1;
			}
			else {
				bit = binArray[index--] = '1';
				bit = binArray[index];
				remember = 0;
			}
		}
		else if (bit == '1' && remember == 1) {
			if (index == (strlen(binArray) - 1)) {
				bit = binArray[index--] = '0';
				bit = binArray[index];
				remember = 1;
			}
			else {
				bit = binArray[index--] = '0';
				bit = binArray[index];
				remember = 1;

			}
		}
	} while (remember != 0 && (index > 0 || index == 0));
}

static void notBit(char s[]) {
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '0') {
			s[i] = '1';
		}
		else {
			s[i] = '0';
		}
	}
}