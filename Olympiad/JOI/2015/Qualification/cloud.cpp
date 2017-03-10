#include <bits/stdc++.h>
using namespace std;

int N, M, B[103][103];
char A[103][103];

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%s", A[i]);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) B[i][j] = -1;
	for(int count=0; count<M; count++) {
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(A[i][j] == 'c' && B[i][j] < 0) B[i][j] = count;
		for(int i=0; i<N; i++) A[i][M-1] = '.';
		for(int i=M-2; i>=0; i--) for(int j=0; j<N; j++) swap(A[j][i], A[j][i+1]);
	}
	for(int i=0; i<N; puts(""),i++) for(int j=0; j<M; j++) printf("%d ", B[i][j]);
}
