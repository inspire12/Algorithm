#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define inf 987654 
#define unused 99999
int check[5];
int dist[20] = { unused ,inf,inf ,inf ,inf ,inf };
int preDist[20] = { unused ,inf,inf ,inf ,inf ,inf };
int graph[5][5] = { { 0, 10, 3 ,inf, inf },
{ inf, 0, 1, 2, inf },
{ inf, 4, 0, 8, 2 },
{ inf, inf, inf, 0, 7 },
{ inf, inf, inf, inf, 9 } };

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
typedef struct minHeap {
	int array[10];
	int size;
	
}minHeap;

int rightChild(int i) {
	return 2 * i + 1;
}
int leftChild(int i) {
	return 2 * i;
}
int parent(int i) {
	return i / 2;
}

void minHeapify(minHeap *h, int i) {
	int smallest;
	int l = leftChild(i);
	int r = rightChild(i);
	if (l <= h->size && dist[h->array[l]] < dist[h->array[i]]) {
		smallest = l;
	}
	else {
		smallest = i;
	}
	if (r <= h->size && dist[h->array[r]] < dist[h->array[smallest]])
	{
		smallest = r;
	}
	if (smallest != i) {
		swap(&h->array[i], &h->array[smallest]);
		minHeapify(h, smallest);
	}
}


void buildMinHeap(minHeap* h) {
	for (int i = h->size ; i >= 1; i--) {
		minHeapify(h, i);
	}
}

int isEmpty(minHeap* h) {
	return h->size == 0 ? 1 : 0;
}
void push(minHeap* h, int x) {
	h->array[++h->size]= x;
	buildMinHeap(h);
}
int pop(minHeap* h) {
	if (isEmpty(h))return 0;
	
	int top = h->array[1];
	swap(&h->array[1],&h->array[h->size] );
	h->array[h->size] = inf;
	h->size--;
	buildMinHeap(h);
	return top;
}

char printVertex(int i) {
	switch (i)
	{
	case 1:
		return 'A';
		break;
	case 2:
		return 'B';
		break;
	case 3:
		return 'C';
		break;
	case 4:
		return 'D';
		break;
	case 5:
		return 'E';
		break;
	default:
		break;
	}
}
int isPQ(minHeap* h, int k) {
	for (int i = 1; i <= h->size; i++) {
		if (h->array[i] == k) return 0;
	}
	return 1;
}
printDist(minHeap* h) {
	int s = h->size; int i = 0;
	while(s--) {
		i++; if (isPQ(h, i)) { s++; continue; }
		if (dist[i] == preDist[i]) {
			printf("Q[%d] : d[%c] = %d\n", i-1, printVertex(i), dist[i]);
		}
		else {
			printf("Q[%d] : d[%c] = %d -> d[%c] = %d\n", i-1, printVertex(i), preDist[i], printVertex(i), dist[i]);
		}
	}
	printf("\n\n");
}
void dijkstra(int start,int size) {
	minHeap* h = (minHeap*)malloc(sizeof(minHeap));
	h->size = 0; h->array[0] = unused;
	dist[start] = 0; int count = 0; preDist[start] = 0;
	for (int i = 1; i <= size; i++) {
		push(h, i);
	}
	while (!isEmpty(h)) {
		int top = pop(h);
		printf("------------------------------------------------------\n");
		
		printf("S[%d] : d[%c] = %d\n", count,printVertex(top), dist[top]); count++;
		
		printf("------------------------------------------------------\n");
		for (int i = 1; i <= size; i++) {
			if (graph[top-1][i-1]!=inf) {	//연결	
				if (dist[i] > dist[top] + graph[top-1][i-1]) {
					dist[i] = dist[top] + graph[top-1][i-1];
					buildMinHeap(h);
				}
			}
		}
		printDist(h);
		for(int i=1; i<=size; i++){
			preDist[i] = dist[i];
		}
	}
}

int main() {	
	
	int input = 0; //A
	printf("dijkstra's algorithm으로 계산한 결과는 다음과 같습니다.\n");
	
	//printf("S[%d] : d[%c] = %d\n");

	dijkstra(1, 5);
}

