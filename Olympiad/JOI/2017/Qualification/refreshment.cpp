#include <bits/stdc++.h>
using namespace std;

int N, M, C, ans;
char A[103][103];

int f(int x, int y) {
    int ret = 0;
    for(int i=0; i<x; i++) {
        for(int j=0; j<y;) {
            int idx = j;
            while(A[i][idx] == '#' && idx < y) idx++;
            int idx2 = idx;
            while(A[i][idx2] == '.' && idx < y) idx2++;
            if(idx2 - idx >= C) ret += idx2 - idx - C + 1;
            j = idx2;
        }
    }
    return ret;
}

int main() {
    scanf("%d %d %d", &N, &M, &C);
    for(int i=0; i<N; i++) scanf("%s", A[i]);
    ans += f(N, M);
    for(int i=0; i<max(N, M); i++) for(int j=i+1; j<max(N, M); j++) swap(A[i][j], A[j][i]);
    printf("%d\n", ans + f(M, N));
}

