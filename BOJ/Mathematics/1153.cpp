#include <stdio.h>
#include <vector>
using namespace std;

int N;
bool chk[1000005];
vector<int> v;

int main() {
	scanf("%d", &N);
	if(N < 8) return puts("-1"), 0;
	if(N & 1) printf("2 3 "), N -= 5;
	else printf("2 2 "), N -= 4;
	for(int i=2; i*i<=1000000; i++) if(!chk[i]) for(int j=i*i; j<=1000000; j+=i) chk[j] = 1;
	for(int i=2; i<=1000000; i++) if(!chk[i]) v.push_back(i);
	for(auto it : v) {
		if(!chk[N - it]) return !printf("%d %d\n", it, N - it);
	}
}
