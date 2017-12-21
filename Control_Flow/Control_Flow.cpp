// Control_Flow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinSearch.c"

int binSearch(int x, int v[], int n);

int main()
{
	int myArray[] = { 1, 3, 6, 9, 12, 17, 20, 22, 25, 30 };
	int pos = binSearch(177, myArray, 10);
	printf("%d\n", pos);

    return 0;
}

