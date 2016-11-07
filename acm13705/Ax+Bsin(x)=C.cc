#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)

#include <stdio.h>
#include <math.h>
#define range 100000
int a, b, c;
double mid;
double binarySearch(double low,double high) {
	if (low > high - 0.00000000000001) return mid;
	mid = (low + high) / 2;
	double h = a*mid + b* sin(mid);
	if (h > c) return binarySearch(low, mid);
	else  return binarySearch(mid, high);	
}

int main() {
	 scanf("%d%d%d", &a, &b, &c);
	// decreased fx
	
	 printf("%.6lf\n", binarySearch(0,range));
	 /* Using Kepler's law

	double e = -b / a, E, M = c / a;
	E = M;
	for (int k = 1; k <= range; k++) {
		E = M + e*sin(E);
	}
	printf("%.6lf\n", E);*/
	
}