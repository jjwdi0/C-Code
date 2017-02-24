#include <stdio.h>
typedef long long ll;

int alen, blen, ans, cnt, num[500], cur[500];
char A[3005], B[3000005];

int main()
{
	scanf("%d %d", &alen, &blen);
	scanf("%s %s", A, B);
	for(int i=0; i<alen; i++) num[A[i]]++;
	for(int i='a'; i<='z'; i++) if(cur[i] == num[i]) cnt++;
	for(int i='A'; i<='Z'; i++) if(cur[i] == num[i]) cnt++;
	for(int i=0; i<alen; i++) {
		if(cur[B[i]] == num[B[i]]) cnt--;
		cur[B[i]]++;
		if(cur[B[i]] == num[B[i]]) cnt++;
	}
	for(int i=alen; i<=blen; i++) {
		if(cnt == 52) ans++;
		if(cur[B[i-alen]] == num[B[i-alen]]) cnt--;
		cur[B[i-alen]]--;
		if(cur[B[i-alen]] == num[B[i-alen]]) cnt++;
		if(cur[B[i]] == num[B[i]]) cnt--;
		cur[B[i]]++;
		if(cur[B[i]] == num[B[i]]) cnt++;
	}
	printf("%d\n", ans);
}
