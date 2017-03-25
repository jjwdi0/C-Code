#include <stdio.h>

int n, chk[10], det;
char a[11], ans[11];

void maxf(int x) {
    if(x == 0) {
    	for(int p=9; p>=0; p--) {
    	    if(chk[p] == 0) {
    	    	ans[x] = p + '0';
    	     	chk[p] = 1;
    	    	maxf(x + 1);
    	    	chk[p] = 0;
    	    	if(det) return;
			}
    	}
	}
    if(x > n) {
        puts(ans);
        det = 1;
        return;
    }
    else if(a[x-1] == '<') {
        for(int p=ans[x-1]-'0'; p<=9; p++) if(chk[p] == 0) {
            chk[p] = 1;
            ans[x] = p + '0';
            maxf(x + 1);
            chk[p] = 0;
            if(det == 1) return;
        }
    }
    else {
        for(int p=ans[x-1]-'0'; p>=0; p--) if(chk[p] == 0) {
            chk[p] = 1;
            ans[x] = p + '0';
            maxf(x + 1);
            chk[p] = 0;
            if(det == 1) return;
        }
    }
}

void minf(int x) {
    if(x == 0) for(int p=0; p<=9; p++) {
        if(chk[p] == 0) {
        	ans[x] = p + '0';
        	chk[p] = 1;
        	maxf(x + 1);
        	chk[p] = 0;
        	if(det) return;
		}
    }
    if(x > n) {
        puts(ans);
        det = 1;
        return;
    }
    else if(a[x-1] == '<') {
        for(int p=ans[x-1]-'0'; p<=9; p++) if(chk[p] == 0) {
            chk[p] = 1;
            ans[x] = p + '0';
            maxf(x + 1);
            chk[p] = 0;
            if(det == 1) return;
        }
    }
    else {
        for(int p=ans[x-1]-'0'; p>=0; p--) if(chk[p] == 0) {
            chk[p] = 1;
            ans[x] = p + '0';
            maxf(x + 1);
            chk[p] = 0;
            if(det == 1) return;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf(" %c", a+i);
    maxf(0);
    det = 0;
    minf(0);
}
