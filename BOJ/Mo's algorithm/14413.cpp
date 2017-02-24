#include <bits/stdc++.h>
#define SQRT 1000
using namespace std;

struct query {
    int l, r, ti;
    bool operator < (const query &x) const {
        return l / SQRT == x.l / SQRT ? r < x.r : l < x.l;
    }
}T[500003];

int N, Q, A[500003], p;
int c[500003];
int output[500003];
map<int, int> m;
int ans;

void f(int v, int x) {
    if(c[v] == 2) ans--;
    c[v] += x;
    if(c[v] == 2) ans++;
}

int main() {
    scanf("%d %d", &N, &Q);
    for(int i=1; i<=N; i++) {
        scanf("%d", A+i);
        if(m.find(A[i]) == m.end()) m[A[i]] = ++p, A[i] = p;
        else A[i] = m[A[i]];
    }
    for(int i=0; i<Q; i++) {
        scanf("%d %d", &T[i].l, &T[i].r);
        T[i].ti = i;
    }
    sort(T, T+Q);
    int l = 1, r = 0;
    for(int i=0; i<Q; i++) {
        while(r < T[i].r) f(A[++r], 1);
        while(r > T[i].r) f(A[r--], -1);
        while(l < T[i].l) f(A[l++], -1);
        while(l > T[i].l) f(A[--l], 1);
        output[T[i].ti] = ans;
    }
    for(int i=0; i<Q; i++) printf("%d\n", output[i]);
}

