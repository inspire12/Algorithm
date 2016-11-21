#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct itemem {
	int item;
	int value;
	int weight;
}item;

item knap[100];
int opt[100][100];
char optCount[100][100][100];

int main() {
	FILE* file = fopen("data11.txt", "r");
	int size = 0;
	int i, v, w;

	while (fscanf(file, "%d,%d,%d", &i, &v, &w) > 0) {
		size++;
		knap[i].item = i; knap[i].value = v; knap[i].weight = w;
	}
	fclose(file);

	//각각 구현 top down?

	int W; scanf("%d", &W);
	//table [0]은 0으로 초기화
	for (int count = 0; count <= size; count++) { // 몇번째 item
		for (int i = 0; i <= W; i++) {  //i 가 배낭의 w 
			if (i < knap[count].weight) {
				opt[count][i] = opt[count - 1][i];
			}
			else {
				int a, b; 	a = opt[count - 1][i]; b = opt[count - 1][i - knap[count].weight] + knap[count].value;
				if (a > b) {
					opt[count][i] = a;
					strcpy(optCount[count][i], optCount[count - 1][i]);
				}
				else {
					opt[count][i] = b; char buf[65];
					strcpy(optCount[count][i], optCount[count - 1][i - knap[count].weight]);
					sprintf(buf, "%d", count);
					
					strcat(optCount[count][i], buf);
					strcat(optCount[count][i], " ");
				}
			}
			printf("%d ", opt[count][i]);
		}
		printf("\n");
	}
	printf("max : %d\n", opt[size][W]);

	printf("%s", optCount[size][W]);
}
