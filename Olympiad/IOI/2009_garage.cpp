#include <stdio.h>
#include <queue>
#define INF 987654321
using namespace std;
queue<int> q;
int N, M, cost[103], weight[2003], park_loc[2003], total, state[103];
int RMQ() {
	int res = INF;
	for(int j=1; j<=N; j++) res = (res > state[j] ? state[j] : res);
	return res;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) {
		scanf("%d", cost+i);
		state[i] = i;
	}
	for(int i=1; i<=M; i++) scanf("%d", weight+i);
	for(int i=0, x; i<2*M; i++) {
		scanf("%d", &x);
		if(x < 0) {
			if(!q.empty()) {
				park_loc[q.front()] = park_loc[-x];
				total += weight[q.front()] * cost[park_loc[q.front()]];
				q.pop();
			}
			else state[park_loc[-x]] = park_loc[-x];
			park_loc[-x] = 0;
		}
		else {
			int min = RMQ();
			if(min == INF) q.push(x);
			else {
				park_loc[x] = min;
				total += weight[x] * cost[min];
				state[min] = INF;
			}
		}
	}
	printf("%d", total);
}
