#define _CRT_SECURE_NO_WARNINGS 
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
using namespace std;

struct Coord {
	double x, y;
	bool operator<(const Coord& rhs) const {
		if (x == rhs.x) {
			return y < rhs.y;
		}
		else return x < rhs.x;
	}
	bool operator==(const Coord& rhs) const {
		if (x == rhs.x && y == rhs.y) return true;
		else return false;
	}
}co[100001];

double spow(Coord& cos, Coord& coe) {
	if (cos == coe) return 0LL;
	return (coe.x - cos.x)*(coe.x - cos.x) + (coe.y - cos.y)*(coe.y - cos.y);
}
double solve(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) {
		return spow(co[e], co[s]);
	}
	int mid = (s + e) / 2;
	double t, d = spow(co[e], co[s]);
	if (s != mid)
		if (d > (t = solve(s, mid))) d = t;

	if (e != mid + 1)
		if (d > (t = solve(mid + 1, e))) d = t;

	int i, j;
	for (i = mid; i >= s; i--) {
		for (j = mid + 1; j <= e; j++) {
			t = co[j].x - co[i].x;
			if (t*t >= d) {
				break;
			}
			else {
				t = spow(co[j], co[i]);
				if (d > t) d = t;
			}
		}
		if (j == mid + 1) break;
	}
	return sqrt(d);
}
int main() {

	FILE *file = fopen("data07_closest.txt", "r");
	int i = 0;
	while (!feof(file)) {
		fscanf(file, "%lf,%lf\n", &co[i].x, &co[i].y);
		i++;
	}
	fclose(file);
	sort(co, co + i);
	printf("%.3lf", solve(0, i - 1));
	return 0;
}
