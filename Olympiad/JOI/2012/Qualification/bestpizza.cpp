#include <stdio.h>
#include <algorithm>
using namespace std;

int n, prc1, prc2, kal, kcal[102], maxx, price, efnc;

int main() {
    scanf("%d", &n);
    scanf("%d %d", &prc1, &prc2);
    scanf("%d", &kal);
    
    for(int i=0; i<n; i++) scanf("%d", kcal+i);
    sort(kcal, kcal+n);
    maxx = kal / prc1;
    for(int i=0; i<n; i++) {
		prc1 += prc2;
    	kal += kcal[n-i-1];
    	efnc = kal / prc1;
    	if(efnc > maxx) maxx = efnc;
	}
    printf("%d", maxx);
}
