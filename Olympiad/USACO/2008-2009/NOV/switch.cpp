#include <stdio.h>
#include <vector>
#define SQRT 333
using namespace std;

int N, Q, rev[SQRT], sum[SQRT];
vector<int> v[SQRT];

int main() {
	scanf("%d %d", &N, &Q);
	for(int i=0; i<N; i++) v[i/SQRT].push_back(0);
	for(int i=0, x, y, z; i<Q; i++) {
		scanf("%d %d %d", &x, &y, &z);
		y--; z--;
		if(x) {
			int cnt = 0;
			if(y / SQRT + 1 >= z / SQRT) for(int i=y; i<=z; i++) cnt += (v[i/SQRT][i%SQRT] ^ rev[i/SQRT]);
			else {
				int s = y, e = z;
				while(s / SQRT == y / SQRT) cnt += (v[s/SQRT][s%SQRT] ^ rev[s/SQRT]), s++;
				while(e / SQRT == z / SQRT) cnt += (v[e/SQRT][e%SQRT] ^ rev[e/SQRT]), e--;
				for(int i=s/SQRT; i<=e/SQRT; i++) cnt += sum[i];
			}
			printf("%d\n", cnt);
		}
		else {
			if(y / SQRT + 1 >= z / SQRT) for(int i=y; i<=z; i++) sum[i/SQRT] += (v[i/SQRT][i%SQRT] ^ rev[i/SQRT] ? -1 : 1), v[i/SQRT][i%SQRT] ^= 1;
			else {
				int s = y, e = z;
				while(s / SQRT == y / SQRT) sum[s/SQRT] += (v[s/SQRT][s%SQRT] ^ rev[s/SQRT] ? -1 : 1), v[s/SQRT][s%SQRT] ^= 1, s++;
				while(e / SQRT == z / SQRT) sum[e/SQRT] += (v[e/SQRT][e%SQRT] ^ rev[e/SQRT]? -1 : 1), v[e/SQRT][e%SQRT] ^= 1, e--;
				for(int i=s/SQRT; i<=e/SQRT; i++) rev[i] ^= 1, sum[i] = (int)v[i].size() - sum[i];
			}
		}
	}
}
