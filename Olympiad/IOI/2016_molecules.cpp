#include "molecules.h"
#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
 
vector<int> v, A;
vector<int> ans;
ll L, R;
 
bool cmp(const int &x, const int &y) {return A[x] < A[y];}
 
vector<int> find_subset(int l, int u, vector<int> w) {
    A = w;
    for(int i=0; i<sz(w); i++) v.push_back(i);
    sort(all(v), cmp);
    for(int i=0; i<sz(w); i++) {
        L += w[v[i]], R += w[v[sz(w)-i-1]];
        if(R >= l && L <= u) {
            int j = i;
            while(l > L) L = L - w[v[j-i]] + w[v[j+1]], j++;
            for(int k=j-i; k<=j; k++) ans.push_back(v[k]);
            return ans;
        }
    }
    return ans;
}
