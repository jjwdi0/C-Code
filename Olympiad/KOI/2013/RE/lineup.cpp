#import<cstdio>

int A[1000003], N, mx;

int main() {
	scanf("%d", &N);
	for(int i=0, x; i<N; i++) {
		scanf("%d", &x);
		A[x] = A[x-1] + 1;
		if(mx < A[x]) mx = A[x];
	}
	printf("%d", N - mx);
}
