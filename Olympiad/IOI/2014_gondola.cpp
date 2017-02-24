#include "gondola.h"
#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
 
int N;
vector<int> v;
vector<pr> rpc;
map<int, int> same;
 
ll pow(ll x, int y) {
    if(!y) return 1LL;
    ll u = pow(x, y / 2);
    return y & 1 ? u * u % MOD * x % MOD : u * u % MOD;
}
 
int valid(int n, int inputSeq[]) {
    N = n;
    int idx = -1;
    for(int i=0; i<N; i++) same[inputSeq[i]]++;
    for(auto it : same) if(it.second > 1) return 0;
    for(int i=0; i<N; i++) {
        if(inputSeq[i] <= N) { idx = i; break; }
    }
    if(idx < 0) return 1;
    int u = inputSeq[idx];
    for(int i=idx; i<idx+N; i++) {
        if(inputSeq[i % N] > N) continue;
        if(inputSeq[i % N] != (u + (i - idx) - 1) % N + 1) return 0;
    }
    return 1;
}
 
int replacement(int n, int gondolaSeq[], int replacementSeq[]) {
    N = n;
    int idx = 0, res = 0;
    for(int i=0; i<N; i++) {
        if(gondolaSeq[i] <= N) { idx = i; break; }
    }
    int u = gondolaSeq[idx] > N ? 1 : gondolaSeq[idx];
    for(int i=0; i<N; i++) if(gondolaSeq[i] > N) rpc.push_back(pr(gondolaSeq[i], i));
    sort(all(rpc));
    int p = N + 1;
    for(int i=0; i<sz(rpc); i++) {
        int t;
        if(rpc[i].second >= idx) t = (u + rpc[i].second - idx - 1) % N + 1;
        else t = (u + rpc[i].second + N - idx - 1) % N + 1;
        while(t < rpc[i].first) {
            replacementSeq[res++] = t;
            t = p++;
        }
    }
    return res;
}
 
int countReplacement(int n, int inputSeq[]) {
    N = n;
    if(!valid(N, inputSeq)) return 0;
    for(int i=0; i<N; i++) if(inputSeq[i] > N) v.push_back(inputSeq[i]);
    sort(all(v));
    ll res = (sz(v) == N ? N : 1LL), m = sz(v);
    int pre = N;
    for(int i=0; i<sz(v); i++) {
        res = res * pow(m, v[i] - pre - 1) % MOD;
        m--, pre = v[i];
    }
    return res;
}
