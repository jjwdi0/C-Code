#include <stdio.h>
#include <algorithm>
using namespace std;

struct rank{
	int score, prob, num;
}arr[2005];

int A[2005][2005], N, t, p;

bool cmp(rank x, rank y) { return x.score == y.score ? (x.prob == y.prob ? x.num < y.num : x.prob > y.prob) : x.score > y.score; }

int main() {
	scanf("%d %d %d", &N, &T, &p);
	for(int i=0; i<N; arr[i].num = i + 1, i++) for(int j=0; j<T; j++) scanf("%d", &A[i][j]);
	for(int i=0; i<T; i++) {
		int cnt = 0;
		for(int j=0; j<N; j++) cnt += A[j][i];
		cnt = N - cnt;
		for(int j=0; j<N; j++) if(A[j][i]==1) arr[j].score += cnt, arr[j].prob++;
	}
	sort(arr, arr + N, cmp);
	for(int i=0; i<N; i++) if(arr[i].num == p) return !printf("%d %d", arr[i].score, i+1);
}
