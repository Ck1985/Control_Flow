/* Function itob(n, s, b) convert integer n into a base b 
   character representation in string s */

#include <string.h>

#define NIBBLELEN 4
#define MAXLINE 1000

void reverse3_5(char s[]);
void addOneBinary(char binArray[]);
void notBit(char s[], int actLen);
char mapBinToHexal(char nibble[NIBBLELEN]);
void convertBinary(int decimal, char s[]);
void convertHexal(int decimal, char s[]);
void convertBinaryToHexal(char s[], char hex[]);

static void itob(int n, char s[], int b) {
	switch (b) {
	case 2:
		convertBinary(n, s);
		printf("Representation binary of %d: ", n);
		printf("0b%s\n", s);
		break;
	case 16: 
		convertHexal(n, s);
		break;
	case 8:
		// The same code done good code ^^ hehehehe...
		break;
	default:
		break;
	}
}

static void convertHexal(int decimal, char s[]) {
	if (decimal >= 0) {
		int i = 0, checkCharacter;
		do {
			checkCharacter = decimal % 16;
			if (((checkCharacter > 0) || (checkCharacter == 0)) && ((checkCharacter < 9) || (checkCharacter == 9))) {
				s[i++] = checkCharacter + '0';
			}
			else {
				s[i++] = checkCharacter + '7';
			}
		} while ((decimal = (decimal / 16)) > 0);
		s[i] = '\0';
		reverse3_5(s);
	}
	else {
		int i = 0, decimalTemp = -decimal;
		char hex[MAXLINE];
		for (int i = 0; i < MAXLINE; i++) {
			hex[i] = '\0';
		}
		do {
			s[i++] = decimalTemp % 2 + '0';
		} while ((decimalTemp = (decimalTemp / 2)) > 0);
		int fracBit = i;
		for (int k = 1; k <= 32 - fracBit; k++) {
			s[i++] = '1';
		}
		reverse3_5(s);
		notBit(s, 32 - fracBit);
		addOneBinary(s);
		convertBinaryToHexal(s, hex);
		printf("Representation hexaldecimal of %d: ", decimal);
		printf("0x%s\n", hex);
	}
}

static void convertBinary(int decimal, char s[]) {
	if (decimal >= 0) {
		int i = 0;
		do {
			s[i++] = decimal % 2 + '0';
		} while ((decimal = (decimal / 2)) > 0);
		int fracBit = i;
		for (int k = 1; k <= 32 - fracBit; k++) {
			s[i++] = '0';
		}
		s[i] = '\0';
		reverse3_5(s);
	}
	else {
		int i = 0, decimal2 = - decimal;
		do {
			s[i++] = decimal2 % 2 + '0';
		} while ((decimal2 = (decimal2 / 2)) > 0);
		int fracBit = i;
		for (int k = 1; k <= 32 - fracBit; k++) {
			s[i++] = '1';
		}
		reverse3_5(s);
		notBit(s, 32 - fracBit);
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

static void notBit(char s[], int start) {
	for (int i = start; i < strlen(s); i++) {
		if (s[i] == '0') {
			s[i] = '1';
		}
		else {
			s[i] = '0';
		}
	}
}

static void convertBinaryToHexal(char s[], char hex[MAXLINE]) {
	char nibble[NIBBLELEN], presenHex;
	int indexHex = 0;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < NIBBLELEN; j++) {
			nibble[j] = s[i++];
		}
		presenHex = mapBinToHexal(nibble);
		hex[indexHex++] = presenHex;
		i--;
	}
	hex[indexHex] = '\0';
}

static char mapBinToHexal(char nibble[NIBBLELEN]) {
	int nibbleInt[NIBBLELEN], index = 0, index_2 = 0, presenIntHex = 0;
	char presenHex;
	for (int i = 0; i < NIBBLELEN; i++) {
		if (nibble[i] == '0') {
			nibbleInt[index++] = 0;
		}
		else {
			nibbleInt[index++] = 1;
		}
	}
	for (int j = NIBBLELEN - 1; j >= 0; j--) {
		int power = 1;
		for (int p = 1; p <= j; p++) {
			power = power * 2;
		}
		presenIntHex = presenIntHex + nibbleInt[index_2++] * power;	
	}
	if ((presenIntHex > 0 || presenIntHex == 0) && (presenIntHex < 9 || presenIntHex == 9)) {
		presenHex = presenIntHex + '0';
	}
	else {
		presenHex = presenIntHex + '7';
	}
	return presenHex;
}