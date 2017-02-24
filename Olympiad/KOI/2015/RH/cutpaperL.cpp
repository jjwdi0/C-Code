#include <stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))

int W1, H1, W2, H2, D[55][55][55][55], R[55][55];

int main() {
    scanf("%d %d %d %d", &W1, &H1, &W2, &H2);
    for(int i = 1; i <= W1; i++) for(int j = 1; j <= H1; j++) {
        R[i][j] = 1e9;
        if(i == j) R[i][j] = 1;
        else {             
            for(int k = 1; k < i; k++) R[i][j] = min(R[i][j], R[k][j] + R[i-k][j]);
            for(int k = 1; k < j; k++) R[i][j] = min(R[i][j], R[i][k] + R[i][j-k]);
        }
    }
    for(int w1=2; w1<=W1; w1++) for(int h1=2; h1<=H1; h1++) for(int w2=1; w2<w1; w2++) for(int h2=1; h2<h1; h2++) {
    	D[w1][h1][w2][h2] = 1e9;
        for(int k = 1; k < w1-w2; k++) D[w1][h1][w2][h2] = min(D[w1][h1][w2][h2], R[k][h1] + D[w1-k][h1][w2][h2]);
        D[w1][h1][w2][h2] = min(D[w1][h1][w2][h2], R[w1-w2][h1] + R[w2][h1-h2]);
        for(int k = w1-w2+1; k < w1; k++) D[w1][h1][w2][h2] = min(D[w1][h1][w2][h2], D[k][h1][k-(w1-w2)][h2] + R[w1-k][h1-h2]);
        for(int k = 1; k < h2; k++) D[w1][h1][w2][h2] = min(D[w1][h1][w2][h2], R[w1-w2][k] + D[w1][h1-k][w2][h2-k]);
        D[w1][h1][w2][h2] = min(D[w1][h1][w2][h2], R[w1-w2][h2] + R[w1][h1-h2]);
        for(int k = h2+1; k < h1; k++) D[w1][h1][w2][h2] = min(D[w1][h1][w2][h2], D[w1][k][w2][h2] + R[w1][h1-k]);
    }
    printf("%d\n", D[W1][H1][W2][H2]);
}
