#include <bits/stdc++.h>
using namespace std;

string A;
int ans;

bool f() {
    for(int i=0; i<A.length()-1; i++) if(A[i] == A[i+1]) return false;
    return true;
}

int main() {
    cin >> A;
    sort(A.begin(), A.end());
    do ans += f(); while(next_permutation(A.begin(), A.end()));
    printf("%d\n", ans);
}

