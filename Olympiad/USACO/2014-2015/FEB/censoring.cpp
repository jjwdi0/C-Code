#include <bits/stdc++.h>
using namespace std;

string a, b, ans;

int main() {
	cin >> a >> b;
	for(int i=0; i<a.length(); i++) {
		ans += a[i];
		if(ans.length() >= b.length() && ans.substr(ans.length() - b.length()) == b) ans.resize(ans.size() - b.size());
	}
	cout << ans;
}
