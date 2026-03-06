int comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1; 	/* no match */
}

int binsearch_mod(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low+high) / 2;
	while (low <= high && x != v[mid]) {
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low+high) / 2;
	}
	if (x == v[mid])
		return mid;	/* found match */
	else
		return -1; 	/* no match */
}
