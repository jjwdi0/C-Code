#include <stdio.h>
#include <algorithm>
using namespace std;

struct data { int x, y, z; } t[102];
int n;
bool cmp(data a, data b) { return a.z > b.z; }

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d %d %d", &t[i].x, &t[i].y, &t[i].z);
	sort(t, t+n, cmp);
	printf("%d %d\n%d %d\n", t[0].x, t[0].y, t[1].x, t[1].y);
	for(int i=2; i<n; i++) {
		if(t[0].x==t[1].x && t[1].x==t[i].x) continue;
		else return !printf("%d %d", t[i].x, t[i].y);
	}
}
