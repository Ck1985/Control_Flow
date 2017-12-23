// Control_Flow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinSearch.c"
#include "BinSearchVer2.c"
#include "Exercise3_1.c"

#include <time.h>

int binSearch(int x, int v[], int n);
int binSearchVer2(int x, int v[], int low, int high);
int binSearchVer3(int x, int v[], int n);

int myArray[] = {1,3,6,9,12,17,20,22,25,30,58,64,98,100,110,120,130,150};

int measureTimeCPUUsedVer1();
int measureTimeCPUUsedVer2();
int measureTimeCPUUsedVer3();

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
	measureTimeCPUUsedVer3();
	/* -------------------------------------------- */

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

