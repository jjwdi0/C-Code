#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, D[3005];
int A[3005][3005], sc[3005][3005];
vector<int> v;

int f(int x, int s, int e) {
    return A[x][e] - A[x][s-1] - A[x-1][e] + A[x-1][s-1];
}

void trace(int x) {
    if(x == 0) return;
    for(int i=x-1; i>=0; i--) {
        if(D[x] == D[i] + sc[i+1][x]) {
            trace(i);
            v.push_back(x - i);
            return;
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        for(int x;;) {
            scanf("%d", &x);
            if(!x) break;
            A[i][x] = A[x][i] = 1;
        }
    }
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
    for(int i=1; i<=N; i++) for(int j=i; j<=N; j++) sc[i][j] = sc[i][j-1] - f(j, i, j) * 2 + (j - i) + f(j, j + 1, N);
    for(int i=1; i<=N; i++) {
        D[i] = 2e9;
        for(int j=0; j<i; j++) D[i] = min(D[i], D[j] + sc[j+1][i]);
    }
    printf("%d\n", D[N]);
    trace(N);
    printf("%d ", v.size());
    for(int i=0; i<v.size(); i++) printf("%d ", v[i]);
}
