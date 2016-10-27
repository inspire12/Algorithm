#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <cstring>
using namespace std;

int input[1000001];
long long int ans;

void mergeSort(int left, int right) {
	if (left == right) return;

	int mid = (left + right) / 2;

	mergeSort(left, mid);
	mergeSort(mid + 1, right);

	static int tmp[1000001];
	int t = 0;
	int i1 = left;
	int i2 = mid + 1;
	while (i1 <= mid && i2 <= right) {
		if (input[i1] < input[i2])
			tmp[t++] = input[i1++];
		else
			tmp[t++] = input[i2++],
			ans += mid - i1 + 1;
	}
	while (i1 <= mid) tmp[t++] = input[i1++];
	while (i2 <= right) tmp[t++] = input[i2++];

	memcpy(input + left, tmp, t * sizeof(int));
}



int main() {

	FILE *file = fopen("data07_inversion.txt", "r");
	int i = 0;
	while (!feof(file)) {
		fscanf(file, "%d,", &input[i]);
		i++;
	}
	fclose(file);

	mergeSort(0, i - 1);

	printf("%lld\n", ans);

	return 0;
}

