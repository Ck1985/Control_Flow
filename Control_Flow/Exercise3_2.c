/* function escape(s,t): Convert escape character to visible character \n \t
   when copies t to s */

static void escape(char s[], char t[]) {
	int indexT = 0, indexS = 0;

	while (t[indexT] != '\0') {
		switch (t[indexT]) {
		case '\n':
			s[indexS] = '\\';
			indexS++;
			s[indexS++] = 'n';
			indexT++;
			break;
		case '\t':
			s[indexS] = '\\';
			indexS++;
			s[indexS++] = 't';
			indexT++;
			break;
		default:
			s[indexS++] = t[indexT++];
			break;
		}
	}

	printf("%s\n", s);
}

static void invisibleEscape(char s[], char t[]) {
	int indexS = 0, indexT = 0;

	while (t[indexT] != '\0') {
		s[indexS++] = t[indexT++];
	}

	printf("%s\n", s);
}