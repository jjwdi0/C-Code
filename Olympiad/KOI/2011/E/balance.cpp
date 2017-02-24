#include <stdio.h>
#include <algorithm>
using namespace std;

int N, A[1000005], k = 1;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", A+i);
    sort(A, A + N);
    if(A[0] == 1){
    	for(int i=1; i<N; i++) {
    		if(k + 1 < A[i]) return !printf("%d", k+1);
    		k += A[i];
    	}
    	printf("%d", k + 1);
	}
    else printf("1");
}
