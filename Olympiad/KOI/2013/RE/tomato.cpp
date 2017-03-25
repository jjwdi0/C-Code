#include "stdio.h"

int max = 0, queue[3][1000005], front, rear;
int check[105][105][105], tom[105][105][105];

void bfs(int m, int n, int o) {
    int x,y,z;
    while(front < rear) {
        x = queue[0][front];
        y = queue[1][front];
        z = queue[2][front++];
        if(x + 1 < m && tom[x+1][y][z] == 0 && (!check[x+1][y][z] || check[x+1][y][z] > check[x][y][z] + 1)) {
            check[x+1][y][z] = check[x][y][z] + 1;
            queue[0][rear] = x + 1;
            queue[1][rear] = y;
            queue[2][rear++] = z;
        }
        if(x > 0 && tom[x-1][y][z] == 0 && (!check[x-1][y][z] || check[x-1][y][z] > check[x][y][z] + 1)) {
            check[x-1][y][z] = check[x][y][z] + 1;
            queue[0][rear] = x - 1;
            queue[1][rear] = y;
            queue[2][rear++] = z;
        }
        if(y + 1 < n && tom[x][y+1][z] == 0 && (!check[x][y+1][z] || check[x][y+1][z] > check[x][y][z]+1)) {
            check[x][y+1][z] = check[x][y][z] + 1;
            queue[0][rear] = x;
            queue[1][rear] = y + 1;
            queue[2][rear++] = z;
        }
        if(y > 0 && tom[x][y-1][z] == 0 && (!check[x][y-1][z] || check[x][y-1][z] > check[x][y][z] + 1)) {
            check[x][y-1][z] = check[x][y][z] + 1;
            queue[0][rear] = x;
            queue[1][rear] = y - 1;
            queue[2][rear++] = z;
        }
        if(z + 1 < o && tom[x][y][z+1] == 0 && (!check[x][y][z+1] || check[x][y][z+1] > check[x][y][z] + 1)) {
            check[x][y][z+1] = check[x][y][z] + 1;
            queue[0][rear] = x;
            queue[1][rear] = y;
            queue[2][rear++] = z + 1;
        }
        if(z > 0 && tom[x][y][z-1] == 0 && (!check[x][y][z-1] || check[x][y][z-1] > check[x][y][z] + 1)) {
            check[x][y][z-1] = check[x][y][z] + 1;
            queue[0][rear] = x;
            queue[1][rear] = y;
            queue[2][rear++] = z - 1;
        }
    }
}

int main() {
    int x, y, z, flag = 0;
    scanf("%d %d %d", &y, &x, &z);
    for(int k=0; k<z; k++) for(int i=0; i<x; i++) for(int j=0; j<y; j++) scanf("%d", &tom[i][j][k]);
    for(int k=0; k<z; k++) for(int i=0; i<x; i++) for(int j=0; j<y; j++) if(tom[i][j][k] == 1){
        front = 0, rear = 0;
        check[i][j][k] = 1;
        queue[0][rear] = i;
        queue[1][rear] = j;
        queue[2][rear++] = k;
    	bfs(x,y,z);
    }
    for(int k=0; k<z; k++) for(int i=0; i<x; i++) for(int j=0; j<y; j++) if(tom[i][j][k] == 0 && !check[i][j][k]) flag = 1;
    if(flag==1) printf("-1\n");
    else {
        for(int k=0; k<z; k++) for(int i=0; i<x; i++) for(int j=0; j<y; j++) if(check[i][j][k] > max) max = check[i][j][k];
        printf("%d\n",max - 1);
    }
}
