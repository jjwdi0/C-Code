#include "ricehub.h"
#define MAX_N 100005
typedef long long ll;
 
int max(int X, int Y){return X>Y?X:Y;}
int besthub(int R, int L, int X[], ll B) {
	int ans = 0;
	int i = 1, j = 1;
	ll cnt = 0LL, A[MAX_N];
	for(int i=R-1; i>=0; i--) X[i+1] = X[i];
	A[0] = 0LL;
	for(int i=1; i<=R; i++) A[i] = A[i-1] + X[i];
	while(i <= R && j <= R) {
		int mid = i + j >> 1;
		while(X[(i+j)/2] * (ll)((i+j)/2 - i + 1) - (A[(i+j)/2] - A[i-1]) + A[j] - X[(i+j)/2] * (ll)(j - (i+j)/2 + 1) - A[(i+j)/2 - 1] > B && i < j) i++;
		ans = max(ans, j - i + 1);
		j++;
	}
	return ans;
}
