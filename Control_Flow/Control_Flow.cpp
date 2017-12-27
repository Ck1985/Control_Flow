// Control_Flow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinSearch.c"
#include "BinSearchVer2.c"
#include "Exercise3_1.c"
#include "Exercise3_2.c"
#include "Exercise3_3.c"
#include "SellSortAlgorithm.c"

//#include<stdio.h>
//#define MAXLINE 100

#include <time.h>
#include <ctype.h>
#include <string.h>

int binSearch(int x, int v[], int n);
int binSearchVer2(int x, int v[], int low, int high);
int binSearchVer3(int x, int v[], int n);
void escape(char s[], char t[]);
void invisibleEscape(char s[], char t[]);

//int mgetline(char s[], int maxlimit);
//void expand(char s1[], char s2[]);

int myArray[] = {1,3,6,9,12,17,20,22,25,30,58,64,98,100,110,120,130,150};

int measureTimeCPUUsedVer1();
int measureTimeCPUUsedVer2();
int measureTimeCPUUsedVer3();
int atoi(char s[]);
void sellsort(char v[], int n);
void reverse(char s[]);
void expand(char s1[], char s2[]);

int main()
{
	/* ------------- Else if----------------------- */
	//int myArray[] = { 1, 3, 6, 9, 12, 17, 20, 22, 25, 30 };
	//int pos = binSearch(177, myArray, 10);
	//int pos = binSearchVer2(255, myArray, 0, 9);
	//int pos = binSearchVer3(4, myArray, 10);
	//printf("%d\n", pos);
	//printf("Measure the difference run-time of 3 version binSearch: \n");
	
	//measureTimeCPUUsedVer1();
	//measureTimeCPUUsedVer2();
	//measureTimeCPUUsedVer3();
	/* -------------------------------------------- */

	/* ------------- Switch -------------------- */
	// Counting digits, white space, others
	/*int c, i, nWhite, nOther, nDigits[10], countDigits = 0;

	nWhite = nOther = 0;
	for (int index = 0; index < 10; index++) {
		nDigits[index] = 0;
	}

	while ((c = getchar()) != EOF) {
		switch (c) {
		case '0': case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			nDigits[c - '0']++;
			break;
		case '\n':
		case '\t':
		case ' ':
			nWhite++;
			break;
		default:
			nOther++;
			break;
		}
	}

	for (int j = 0; j < 10; ++j) {
		if (nDigits[j] != 0) {
			countDigits = countDigits + nDigits[j];
		}
		else {
			continue;
		}
	}

	printf("Total digits: %d\n", countDigits);
	printf("Total white space: %d\n", nWhite);
	printf("Total other : %d\n", nOther);*/

	/*char t[] = "abcd\t\tabcd\nabc";
	char s[20];
	for (int i = 0; i < 20; i++) {
		s[i] = '\0';
	}
	//escape(s, t);
	invisibleEscape(s, t);*/
	/* ----------------------------------------- */

	/* ------------- Loops while and for--------- */
	//atoi(char s[]);

	//shellsort(char s[], int n);

	/*char s1[MAXLINE], s2[MAXLINE];

	mgetline(s1, MAXLINE);

	expand(s1, s2);

	printf("%s", s2);*/

	char s1[] = "abc-ghj";
	char s2[15];
	for (int i = 0; i < 15; i++) {
		s2[i] = '\0';
	}
	expand(s1, s2);
	/* ------------------------------------------ */

    return 0;
}

int measureTimeCPUUsedVer1() {
	clock_t start_time, end_time;
	double total_time;
	extern int myArray[18];

	start_time = clock();
	printf("Starting time of binSearchVer1: %ld\n", start_time);
	binSearch(20, myArray, 18);
	//for (int i = 0; i < 100000000; i++)
	//	;
	end_time = clock();
	printf("Ending time of binsearchVer1: %ld\n", end_time);
	total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Total time has taken of CPU (binsearchVer1) is (seconds): %f\n", total_time);
	return total_time;
}

int measureTimeCPUUsedVer2() {
	clock_t start_time, end_time;
	double total_time;
	extern int myArray[18];

	start_time = clock();
	printf("Starting time of binSearchVer2: %ld\n", start_time);
	binSearchVer2(20, myArray, 0, 17);
	end_time = clock();
	printf("Ending time of binarySearchVer2: %ld\n", end_time);
	total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Total time has taken of CPU (binserachVer2) is (seconds): %f\n", total_time);
	return total_time;
}

int measureTimeCPUUsedVer3() {
	clock_t start_time, end_time;
	double total_time;

	extern int myArray[18];

	start_time = clock();
	printf("Starting time of binSearchVer3: %ld\n", start_time);
	binSearchVer3(20, myArray, 18);
	end_time = clock();
	printf("Ending time of binarySearchVer3: %ld\n", end_time);
	total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Total time has taken of CPUD (binSearchVer) is (seconds): %f\n", total_time);
	return total_time;
}

/* Function atoi: Convert String s into Integer Version 2 */
int atoi(char s[]) {
	int i, n, sign;

	for (i = 0; isspace(s[i]); ++i) {		// skip white spaces 
		;
	}

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-') {		// skip sign
		i++;
	}

	for (n = 0; isdigit(s[i]); i++) {
		n = 10 * n + (s[i] - '0');
	}
	return sign * n;
}

/* Function reverse: reverse string s in place */

void reverse(char s[]) {
	int i, j, c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		/*c = s[j];
		s[j] = s[i];
		s[i] = c;*/

		// Or
		c = s[j], s[j] = s[i], s[i] = c;
	}
}

// Source code
/*int mgetline(char s[], int lim)
{
	int i, c;

	for (i = 0; i<lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
}

void expand(char s1[], char s2[])
{
	int i, j, c;

	i = j = 0;

	while ((c = s1[i++]) != '\0')
		if (s1[i] == '-' && s1[i + 1] >= c)
		{
			i++;
			while (c<s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;

	s2[j] = '\0';
}*/

