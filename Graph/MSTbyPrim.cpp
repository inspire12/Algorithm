#define _CRT_SECURE_NO_WARNINGS
/* Prim's Algorithm 
	make a tree? 
	save a edge?
	how to know graph is not cycle
	dynamic list as malloc
*/
#include <stdio.h>
#include <vector>
#include <queue>
#define inf 987654321
#define unused 9999999
using namespace std;
//
//typedef struct edge {
//	int u,v,w;
//	bool operator>(const edge e) const {
//		return w > e.w;
//	}
//};
//queue? priorty for
// a1,b2,c3,d4,e5,f6,g7,h8,i9
int key[10];
int parentVertex[10];

int graph[10][10] =
{
	{unused,unused, unused, unused, unused, unused, unused, unused, unused, unused},
	{ unused,inf,4,inf,inf,inf,inf,inf,8,inf},
	{ unused,4,inf,8,inf,inf,inf,inf,11,inf},
	{ unused,inf,8,inf,7,inf,4,inf,inf,2},
	{ unused,inf,inf,7,inf,9,14,inf, inf, inf},
	{ unused,inf,inf,inf,9,inf,10,inf,inf ,inf},
	{ unused,inf,inf, 4, 14, 10,inf, 2,inf, inf},
	{ unused,inf, inf, inf, inf, inf,2,inf, 1,6},
	{ unused,8,inf,inf, inf, inf, inf, 7, inf,1},
	{ unused,inf, inf, 2,inf, inf, 6,7, inf }
};
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
	if (l <= h->size && key[h->array[l]] < key[h->array[i]]) {
		smallest = l;
	}
	else {
		smallest = i;
	}
	if (r <= h->size && key[h->array[r]] < key[h->array[smallest]])
	{
		smallest = r;
	}
	if (smallest != i) {
		swap(&h->array[i], &h->array[smallest]);
		minHeapify(h, smallest);
	}
}
void buildMinHeap(minHeap* h) {
	for (int i = h->size; i >= 1; i--) {
		minHeapify(h, i);
	}
}
int isEmpty(minHeap* h) {
	return h->size == 0 ? 1 : 0;
}
void push(minHeap* h, int x) {
	h->array[++h->size] = x;
	buildMinHeap(h);
}
int pop(minHeap* h) {
	if (isEmpty(h))return 0;
	int top = h->array[1];
	swap(&h->array[1], &h->array[h->size]);
	h->array[h->size] = inf;
	h->size--;
	buildMinHeap(h);
	return top;
}

int isNotPQ(minHeap* h, int k) {
	for (int i = 1; i <= h->size; i++) {
		if (h->array[i] == k) return 1;
	}
	return 0;
}
char printVertex(int i) {
	switch (i)
	{
	case 1:
		return 'a';
		break;
	case 2:
		return 'b';
		break;
	case 3:
		return 'c';
		break;
	case 4:
		return 'd';
		break;
	case 5:
		return 'e';
		break;
	case 6:
		return 'f';
		break;
	case 7:
		return 'g';
		break;
	case 8:
		return 'h';
		break;
	case 9:
		return 'i';
		break;
	default:
		break;
	}
}
int spanningTree[9][9];
int main() {
	int start =1; //arbitary chosen point
	minHeap* pq = (minHeap*)malloc(sizeof(minHeap));
	pq->size = 0;
	for (int i = 1; i <= 9; i++) {
		if (i == start) key[i] = 0;
		else key[i] = inf;
		push(pq, i);
	}
	while(!isEmpty(pq)){
		buildMinHeap(pq);
		int u = pop(pq);
		if (parentVertex[u] == 0) {
			printf("w< ,%c> = %d\n", printVertex(u),key[parentVertex[u]]);
		}else{
			printf("w<%c,%c> = %d\n", printVertex(parentVertex[u]), printVertex(u), key[u]);
		}
		for (int v = 1; v <= 9; v++) {
			if (graph[u][v] != inf) {
				if (isNotPQ(pq,v) && key[v] > graph[u][v]){
					key[v] = graph[u][v];
					parentVertex[v] = u;
					
				}
			}
		}
	}
	int sum = 0;
	for (int i =1;i<=9;i++) {
		sum += key[i];
	}
	printf("w<MST> = %d\n",sum);

}