#include <stdio.h>

int array[100000];

int main(){

	int n; scanf("%d", &n);
	array[0] =1 ;array[1] = 1;
	for(int i=2; i<=n ; i++){
		array[i] = array[i-1]+array[i-2];
	}
	printf("%d", array[n]);
}
