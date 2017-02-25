#include <bits/stdc++.h>
using namespace std;

char A[55];
int ans;

bool cross(char x, char y) {
    int X[2], Y[2], i1 = 0, i2 = 0;
    for(int i=0; i<52; i++) {
        if(A[i] == x) X[i1++] = i;
        if(A[i] == y) Y[i2++] = i;
    }
    if(X[0] < Y[0] && Y[0] < X[1] && X[1] < Y[1]) return true;
    if(Y[0] < X[0] && X[0] < Y[1] && Y[1] < X[1]) return true;
    return false;
}

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    scanf("%s", A);
    for(int i=0; i<26; i++) for(int j=i+1; j<26; j++) ans += cross(i + 'A', j + 'A');
    printf("%d\n", ans);
}
