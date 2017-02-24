#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

char a[1505], b[1505];
int alen, blen, i, j;
ll prime = 1234567891, hash[26], hash_temp;
set<ll> v[1505];

bool chk(int x) {
	hash_temp = 0;
	set<ll>::iterator it;
	for(int k=0; k<x; k++) hash_temp += hash[b[k]-'a'];
	it = v[x].find(hash_temp);
	if(it != v[x].end()) return true;
	for(int k=x; k<blen; k++) {
		hash_temp -= hash[b[k-x]-'a'];
		hash_temp += hash[b[k]-'a'];
		it = v[x].find(hash_temp);
		if(it != v[x].end()) return true;
	}
	return false;
}

int main() {
	scanf("%s %s", a, b);
	alen = strlen(a), blen = strlen(b);
	hash[0] = prime;
	for(i=1; i<26; i++) hash[i] = hash[i-1] * prime;
	for(i=0; i<alen; i++) {
		hash_temp = hash[a[i]-'a'];
		for(j=i+1; j<alen; j++) {
			hash_temp += hash[a[j]-'a'];
			v[j-i+1].insert(hash_temp);
		}
	}
	for(i=blen; i>0; i--) if(chk(i)) return printf("%d", i), 0;
	printf("0");
}
