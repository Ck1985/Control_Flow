/* Algorithm sellsort: sorting v[0] .... v[n - 1] into increasing order */

static void sellsort(char v[], int n) {
	int i, j, gap, temp;

	for (gap = n / 2; n > 0; gap = gap / 2) {
		for (j = gap; j < n; j++) {
			for (i = j - gap; (i >= 0) && (v[i] > v[i + gap]); i = i - gap) {
				temp = v[i];
				v[i] = v[i + gap];
				v[i + gap] = temp;
			}
		}
	}
}