#include <stdio.h>
#include <time.h>

long long int array[1000];

long long int fibo_recursion(int n);
long long int fibo_array(int n);
long long int fibo_squaring(int n);

int main(){
	printf("방법\n");
	printf("1 : Recursion\n");
	printf("2 : Array\n");
	printf("3 : Recursive sqaring\n");

	int input; scanf("%d",&input);

	for(int i=0; i<= 90; i++){
		time_t startTime = clock();
		printf("f<%d> = %lld \t %lf sec\n",i, input==0?fibo_recursion(i):input==1?fibo_array(i):fibo_squaring(i),(double)clock() - startTime );
	}
	return 0;
}

long long int fibo_recursion(int n){
	if(n<2) return 1;
	return fibo_recursion(n-1) + fibo_recursion(n-2);
}

long long int fibo_array(int n){
	array[0] = 1;  array[1] = 1;
	for(int i=2; i<= n; i++){
		array[i] = array[i-1] + array[i-2];
	}
	return array[n];
}
long long int fibo_squaring(int n){
	return 0;
}

