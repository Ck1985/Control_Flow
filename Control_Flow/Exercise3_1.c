/* Function binSearchVer3: 1 test in loop */

static int binSearchVer3(int x, int arrayCheck[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (n - 1) / 2;

	while (low <= high && x != arrayCheck[mid]) {
		if (x < arrayCheck[mid]) {
			high = mid - 1;
		}
		else if (x > arrayCheck[mid]) {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}

	if (x == arrayCheck[mid]) {
		return mid;
	}

	if (low > high && x != arrayCheck[mid]) {
		return -1;
	}
}