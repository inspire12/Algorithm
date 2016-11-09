#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)

#include <stdio.h>

int n,k;

long long int dp[100003];
int coin[10003];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d", dp[k]);
}



//
//int coin[100000];
//int countCoin = 0;
//int Coin(int localK, int cal) {
//	if (localK < 0) return 0;
//	if (localK == 0) { 
//		countCoin++; 
//		return 0; 
//	}
//	
//	for (int i = cal; i < n; i++) {
//		Coin(localK - coin[i], i);
//	}
//}
//
//int main() {
//	scanf("%d%d", &n, &k);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &coin[i]);
//	}
//	sort( &coin[0], &coin[n - 1], greater<int>());
//	Coin(k, 0);
//	printf("%d\n", countCoin);
//}