#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define B 340
using namespace std;

struct Z {
    int x, y;
    bool operator < (const Z &A) const {
        return x < A.x;
    }
}A[100005];
int N, Q;
int idx[100005];
int Bucket[100005];
vector<int> v[B];

int find_idx(int x) { return lower_bound(idx, idx+N, x) - idx; }

int main() {
    scanf("%d %d", &N, &Q);
    for(int i=0; i<N; i++) scanf("%d %d", &A[i].x, &A[i].y);
    sort(A, A+N);
    for(int i=0; i<N; i++) idx[i] = A[i].x;
    for(int i=0; i<N; i++) Bucket[i] = A[i].y, v[i / B].push_back(A[i].y);
    for(int i=0; i<B; i++) sort(all(v[i]));
    for(int i=0, x, y, z, w; i<Q; i++) {
        scanf("%d %d %d %d", &x, &y, &z, &w);
        int s = lower_bound(idx, idx+N, x) - idx, e = upper_bound(idx, idx+N, y) - idx - 1;
        int ans = 0;
        if(s / B + 1 >= e / B) {
            for(int j=s; j<=e; j++) ans += (Bucket[j] >= z && Bucket[j] <= w);
            printf("%d\n", ans);
        }
        else {
            int s1 = s, e1 = e;
            while(s1 / B == s / B) ans += (Bucket[s1] >= z && Bucket[s1] <= w), s1++;
            while(e1 / B == e / B) ans += (Bucket[e1] >= z && Bucket[e1] <= w), e1--;
            for(int j=s1/B; j<=e1/B; j++) ans += (int)(upper_bound(all(v[j]), w) - lower_bound(all(v[j]), z));
            printf("%d\n", ans);
        }
    }
}

