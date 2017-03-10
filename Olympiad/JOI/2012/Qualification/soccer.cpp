#include <stdio.h>
#include <algorithm>
using namespace std;

struct point{ int num, score, rank; } t[103];
int n;
bool cmp(const point &x, const point &y) { return x.score > y.score; }
bool cmp2(const point &x, const point &y) { return x.num < y.num; }

int main() {
	scanf("%d", &n);
	for(int i=0; i < n * (n - 1) / 2; i++) {
		int t1, t2, t3, t4;
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		if(t3 > t4) t[t1].score += 3;
		else if(t3 < t4) t[t2].score += 3;
		else t[t1].score++, t[t2].score++;
	}
	for(int i=1; i<=n; i++) t[i].num = i;
	sort(t + 1, t + n + 1, cmp);
	for(int i=1; i<=n; i++) {
		if(t[i].score != t[i-1].score) t[i].rank = i;
		else t[i].rank = t[i-1].rank;
	}
	sort(t + 1, t + n + 1, cmp2);
	for(int i=1; i<=n; i++) printf("%d\n", t[i].rank);
}
