#include <stdio.h>

char A[5][15];
int N;

int main() {
    for(int i=0; i<5; i++) scanf("%s", A[i]);
    for(int j=0; j<15; j++) for(int i=0; i<5; i++) if(A[i][j]) printf("%c", A[i][j]);
}
