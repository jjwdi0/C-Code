#include "card.h"
 
char A[53];
bool visited[53];
 
void card() {
    for(int i=1; i<=50; i++) A[i] = faceup(i);
    for(int i=1; i<=50; i++) if(!visited[i]) for(int j=i+1; j<=50; j++) if(A[i] == A[j]) {
        faceup(i), faceup(j);
        visited[i] = visited[j] = 1;
    }
}
