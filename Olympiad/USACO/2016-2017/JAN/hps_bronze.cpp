#include <bits/stdc++.h>
using namespace std;

int N, A[103][2], ans;
int hps[3] = { 1, 2, 3 };

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d", &A[i][0], &A[i][1]);
    do {
        int cnt = 0;
        for(int i=0; i<N; i++) {
            if(A[i][0] == hps[0] && A[i][1] == hps[1]) cnt++;
            if(A[i][0] == hps[1] && A[i][1] == hps[2]) cnt++;
            if(A[i][0] == hps[2] && A[i][1] == hps[0]) cnt++;
        }
        ans = max(ans, cnt);
    }while(next_permutation(hps, hps + 3));
    printf("%d\n", ans);
}

