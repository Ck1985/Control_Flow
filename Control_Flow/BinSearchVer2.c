/* Function binSearch: recusion model */

static int binSearchVer2(int x, int v[], int low, int high) {
	if (low <= high) {
		int mid;
		mid = (low + high) / 2;
		if (x == v[mid]) {
			return mid;
		}
		else if (x < v[mid]) {
			binSearchVer2(x, v, low, mid - 1);
		}
		else if (x > v[mid]) {
			binSearchVer2(x, v, mid + 1, high);
		}
	}
	else {
		return -1;
	}
}