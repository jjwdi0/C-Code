#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int N;

int main() {
	scanf("%d", &N);
	for(int i=0, x; i<N; i++) {
		scanf("%d", &x);
		auto it = lower_bound(v.begin(), v.end(), x);
		if(it == v.end()) v.push_back(x);
		else *it = x;
	}
	printf("%d", v.size());
}
