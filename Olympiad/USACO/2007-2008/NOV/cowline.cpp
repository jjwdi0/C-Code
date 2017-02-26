#include <bits/stdc++.h>
using namespace std;

string str, rev_str, ans;
int n;

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		char t;
		scanf("\n%c", &t);
		str = str + t;
		rev_str = t + rev_str;
	}
	int len = str.length();
	int lo = 0, hi = len - 1;
	while(lo <= hi) {
		if(str.substr(lo) < rev_str.substr(len - hi - 1)) ans = ans + str[lo++];
		else ans = ans + str[hi--];
	}
	for(int i=0; i<len; i++) {
		cout << ans[i];
		if(i % 80 == 79) puts("");
	}
}
