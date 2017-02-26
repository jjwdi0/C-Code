#include <stdio.h>
#include <queue>
using namespace std;
queue <int> q;
int a[100005], n, m;
void f() {
    while(!q.empty()) {
		if(a[m]) { printf("%d", a[m]); break; }
    	if(q.front() - 1 >= 0) {
			if(a[q.front()-1] == 0) {
				a[q.front()-1] = a[q.front()] + 1;
				q.push(q.front()-1);
			}
		}
    	if(q.front() + 1 <= 100000) {
			if(a[q.front()+1] == 0) {
				a[q.front()+1] = a[q.front()] + 1;
    			q.push(q.front()+1);
			}
		}
    	if(2 * q.front() <= 100000) {
			if(a[q.front()*2] == 0) {
				a[2*q.front()] = a[q.front()] + 1;
    			q.push(2 * q.front());
			}
		}
    	q.pop();
	}
}
int main() {
    scanf("%d %d", &n, &m);
    q.push(n);
    if(n == m) printf("0");
    else if(n > m) printf("%d", n - m);
    else f();
}
