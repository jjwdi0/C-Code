#include <bits/stdc++.h>
using namespace std;

string cow[7] = {
    "Bessie",
    "Maggie",
    "Elsie",
    "Henrietta",
    "Gertie",
    "Daisy",
    "Annabelle"
};
int N, score[7];

int main() {
    cin >> N;
    while(N--) {
        string r;
        int add;
        cin >> r >> add;
        for(int i=0; i<7; i++) {
            if(cow[i] == r) {
                score[i] += add;
                break;
            }
        }
    }
    int mx = 1e9;
    for(int i=0; i<7; i++) mx = min(mx, score[i]);
    int mx1 = 1e9;
    for(int i=0; i<7; i++) if(score[i] > mx) mx1 = min(mx1, score[i]);
    int cnt = 0;
    for(int i=0; i<7; i++) if(score[i] == mx1) cnt++;
    if(cnt != 1) puts("Tie");
    else {
        for(int i=0; i<7; i++) if(score[i] == mx1) cout << cow[i] << endl;
    }
}

