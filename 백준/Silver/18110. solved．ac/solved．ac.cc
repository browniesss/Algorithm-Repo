#include <iostream>
#include <math.h>

using namespace std;

int arr[1000001];

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ravg = 0, sum = 0;

	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	ravg = round(n * 0.15);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	qsort(arr, n, sizeof(int), cmp);
	
	for (int i = ravg; i < n - ravg; i++)
	{
		sum += arr[i];
	}
	cout << round(sum / (double)(n - (ravg * 2)));

	return 0;
}