#include <bits/stdc++.h>
using namespace std;

int N, ans;
map<string, vector<string>> m;
string T[200005][2];

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> T[i][0] >> T[i][1];
		m[T[i][1]].push_back(T[i][0]);
	}
	for(int i=0; i<N; i++) {
		if(m.find(T[i][0].substr(0, 2)) == m.end() || T[i][0].substr(0, 2) == T[i][1]) continue;
		for(auto it : m[T[i][0].substr(0, 2)]) {
			if(it == T[i][0] && T[i][1] == T[i][0].substr(0, 2)) continue;
			if(it.substr(0, 2) == T[i][1]) ans++;
		}
	}
	cout << ans / 2 << endl;
}
