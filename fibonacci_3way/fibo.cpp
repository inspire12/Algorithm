#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <vector>
using namespace std;

long long int dp_array[1000];

long long int fibo_recursion(int n);
long long int fibo_array(int n);
long long int fibo_squaring(int n);

int main() {
	printf("¹æ¹ý\n");
	printf("1 : Recursion\n");
	printf("2 : Array\n");
	printf("3 : Recursive sqaring\n");

	int input; scanf("%d", &input);

	for (int i = 0; i <= 90; i++) {
		time_t startTime = clock()/CLOCKS_PER_SEC;
		printf("f<%d> = %lld \t %lf sec\n", i, input == 1 ? 
			fibo_recursion(i) : input == 2 ? fibo_array(i) : fibo_squaring(i), (double)clock()/ CLOCKS_PER_SEC - startTime);
	}
	return 0;
}

long long int fibo_recursion(int n) {
	if (n<2) return 1;
	return fibo_recursion(n - 1) + fibo_recursion(n - 2);
}

long long int fibo_array(int n) {
	dp_array[0] = 1;  dp_array[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp_array[i] = dp_array[i - 1] + dp_array[i - 2];
	}
	return dp_array[n];
}


vector<vector<long long int> > operator * (const vector<vector<long long int> >&a, const vector<vector<long long int> >&b) {
	int n = a.size();
	vector<vector<long long int> > c(n, vector<long long>(n));
	for (int i = 0; i<n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}
long long int fibo_squaring(int n) {
	n = n + 1;
	if (n < 0 ) {
		return 1;
	}
	vector<vector<long long int> > matrixToAns = { {1,0},{0,1} };
	vector<vector<long long int> > matrix = { { 1,1 },{ 1,0 } };
	while (n > 0) {
		if (n % 2 == 1) {
			matrixToAns = matrixToAns * matrix;
		}
		matrix = matrix * matrix;
		n /= 2;
	}
	return matrixToAns[0][1];
}

