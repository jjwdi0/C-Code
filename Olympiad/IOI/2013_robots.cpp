#include "robots.h"
#include <bits/stdc++.h>
#define MAX_A 50000
#define MAX_B 50000
#define MAX_T 1000000
using namespace std;
typedef pair<int, pair<int, int>> tr;

priority_queue<tr> pq1, pq2;
tr R[1000003];
int c1[50003], c2[50003], P[50003], Q[50003];

bool f(int x, int A, int B, int T) {
	int cnt = 0;
	for(int i=0; i<T; i++) R[i].second.second = 0;
	for(int i=0; i<A; i++) c1[i] = 0;
	for(int i=0; i<B; i++) c2[i] = 0;
	sort(R, R+T);
	int j = 0;
	while(!pq1.empty()) pq1.pop();
	while(!pq2.empty()) pq2.pop();
	for(int i=0; i<A; i++) {
		while(j < T && R[j].first < P[i]) pq1.push({R[j].second.first, {R[j].first, j}}), j++;
		while(c1[i] < x && !pq1.empty()) {
			int ind = pq1.top().second.second; pq1.pop();
			c1[i]++;
			R[ind].second.second = 1;
		}
	}
	for(int i=0; i<T; i++) swap(R[i].first, R[i].second.first);
	sort(R, R+T);
	j = 0;
	for(int i=0; i<B; i++) {
		while(j < T && R[j].first < Q[i]) {
			if(!R[j].second.second) pq2.push({R[j].second.first, {R[j].first, j}});
			j++;
		}
		while(c2[i] < x && !pq2.empty()) {
			int ind = pq2.top().second.second; pq2.pop();
			c2[i]++;
			R[ind].second.second = 1;
		}
	}
	for(int i=0; i<T; i++) {
		cnt += R[i].second.second;
		swap(R[i].first, R[i].second.first);
	}
	return cnt == T;
}

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
	for(int i=0; i<T; i++) {
		R[i].first = W[i];
		R[i].second .first = S[i];
	}
	for(int i=0; i<A; i++) P[i] = X[i];
	for(int i=0; i<B; i++) Q[i] = Y[i];
	sort(P, P+A); sort(Q, Q+B);
	
	int lo = 0, hi = T;
	
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(f(mid, A, B, T)) hi = mid - 1;
		else lo = mid + 1;
	}
    return lo;
}
