#include <stdio.h>

int A[25];

int main() {
    for(int k=0; k<20; k++) A[k] = k + 1;
    for(int k=0;, q, w k<10; k++) {
		scanf("%d %d", &q, &w);
        for(i = q; i< q + (w - q + 1) / 2; i++) j = A[i-1], A[i-1] = A[w - i + q - 1], A[w - i + q - 1] = j;
	}
    for(int i=0; i<20; i++) printf("%d ", a[i]);
}
