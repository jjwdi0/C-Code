#include <stdio.h>
#include <set>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, a[202][2];
set<pair<int, int>> s;
int gcd(int x, int y){ return y ? gcd(y, x%y) : x; }

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
		for(int j=0; j<i; j++) {
			int x = a[i][0] - a[j][0], y = a[i][1] - a[j][1];
			if(x == 0) { s.insert({INF, 1}); continue; }
			int g = gcd(x, y); x /= g; y /= g;
			if(x < 0) x = -x, y = -y;
			s.insert({y, x});
		}
	}
	printf("%d\n", s.size());
}
