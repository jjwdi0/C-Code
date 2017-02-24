#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 100000000;

int N, A[300005], L[300005][2], R[300005][2];
ll ans;
stack<int> s;

void monotone_stack(int x) {
    s.push(0);
    for(int i=1; i<=N; i++) {
        while(A[s.top()] >= A[i]) {
            R[s.top()][x] = i;
            s.pop();
        }
        L[i][x] = s.top();
        s.push(i);
    }
    while(!s.empty()) R[s.top()][x] = N + 1, s.pop();
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", A+i);
    monotone_stack(0);
    for(int i=1; i<=N; i++) A[i] = MN - A[i];
    monotone_stack(1);
    for(int i=1; i<=N; i++) ans += 1LL * (MN - A[i]) * (1LL * (i - L[i][1]) * (R[i][1] - i) - 1LL * (i - L[i][0]) * (R[i][0] - i));
    printf("%lld", ans);
}

