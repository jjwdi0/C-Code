#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

int N, mn[5003] = { 1e9 }, idx;
char A[5003], B[5003];
vector<int> v;

int f(int x) {
    int res = 0;
    v.clear();
    for(int i=0; i<N; i++) B[i] = A[i];
    for(int i=0; i<N; i++) {
        int flip_cnt = (int)(upper_bound(all(v), i) - lower_bound(all(v), i - x + 1));
        if(i > N - x) {
            if((flip_cnt & 1 && B[i] == 'F') || (flip_cnt % 2 == 0 && B[i] == 'B')) return 1e9;
        }
        else if((flip_cnt & 1 && B[i] == 'F') || (flip_cnt % 2 == 0 && B[i] == 'B')) {
            v.push_back(i);
            res++;
        }
    }
    return res;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf(" %c", A+i);
    for(int i=1; i<=N; i++) mn[i] = f(i);
    for(int i=1; i<=N; i++) if(mn[idx] > mn[i]) idx = i;
    printf("%d %d\n", idx, mn[idx]);
}
