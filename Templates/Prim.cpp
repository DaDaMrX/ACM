/*
Prim algorithm
O(n^2)

Input: map[N][N]
Use: dis[N], vis[N]
Output: ans

PS:
    1. Like dijkstra algorithm
    2. 找到最近点，标记，更新
    2. dis[N]数组记录的不是每个点到起点的距离，而是到最小生成树的距离，更新是有不同
    3. 如何判断不连通？
*/

#include <cstdio>
#include <cstring>
#define N 20
int map[N][N], dis[N];
bool vis[N];
int n, m;
int prim()
{
    memset(dis, 0x7f, sizeof(dis));
    dis[1] = 0;
    memset(vis, true, sizeof(vis));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int mini = -1;
        for (int j = 1; j <= n; j++)
            if (vis[j] && (mini == -1 || dis[j] < dis[mini]))
                mini = j;
        vis[mini] = false;
        ans += dis[mini];
        for (int j = 1; j <= n; j++)
            if (vis[j] && map[mini][j] < dis[j])
                dis[j] = map[mini][j];
    }
    return ans;
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(map, 0x7f, sizeof(map));
        for (int i = 1; i <= m; i++)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            if (w < map[a][b]) map[a][b] = map[b][a] = w;
        }
        printf("%d\n", prim());
    }
    return 0;
}

/*
Sample Input
7 11
1 3 1
2 3 2
3 4 3
4 6 5
2 5 10
3 6 7
4 7 5
4 6 1
5 6 5
6 7 8
3 4 7

Sample Output
17
*/
