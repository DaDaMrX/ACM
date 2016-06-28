#include <cstdio>  
#include <cstring>  
#define N 30  
struct point  
{  
    int x, y;  
};  
point map[N][N];  
int sum;  
int p, q;  
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };  
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };  
bool dfs(int x, int y, int step)  
{  
    if (step == sum) return true;     
    int newx, newy;  
    for (int i = 0; i < 8; i++)  
    {  
        newx = x + dx[i]; newy = y + dy[i];  
        if (newx < 1 || newx > q || newy < 1 || newy > p || map[newx][newy].x != -1) continue;  
        map[x][y].x = newx; map[x][y].y = newy;  
        if (dfs(newx, newy, step + 1)) return true;  
        map[x][y].x = -1; map[x][y].y = -1;  
    }  
    return false;  
}  
void route(int x, int y)  
{  
    if (x == -1) return;  
    printf("%c%d", x + 'A' - 1, y);  
    route(map[x][y].x, map[x][y].y);  
}  
int main()  
{  
    int T;  
    scanf("%d", &T);  
    for (int I = 1; I <= T; I++)  
    {  
        scanf("%d%d", &p, &q);  
        printf("Scenario #%d:\n", I);  
        sum = p * q;  
        memset(map, -1, sizeof(map));  
  
        bool flag = false;  
        for (int i = 1; i <= q; i++)  
        {  
            for (int j = 1; j <= p; j++)  
            {  
                if (dfs(i, j, 1))  
                {  
                    route(i, j);  
                    flag = true;  
                    break;  
                }  
            }  
            if (flag) break;  
        }  
        if (!flag) printf("impossible");  
        printf("\n\n");  
    }  
    return 0;  
}