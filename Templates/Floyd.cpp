#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 20
#define INF 0x7f7f7f7f
int map[N][N];
int n, m;
void floyd(int n)
{
        for (int i = 1; i <= n; i++) map[i][i] = 0;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (map[i][k] < INF && map[k][j] < INF)
                        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
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
        floyd(n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < n; j++) printf("%d ", &map[i][j]);
            printf("%d\n", map[i][n]);
        }
    }
    return 0;
}

/*
Sample Input
7 10
1 2 2
2 5 10
5 7 5
1 3 5
2 3 4
2 4 6
5 6 3
6 7 9
3 4 2
4 6 1

Sample Output
0 2 5 7 11 8 16
2 0 4 6 10 7 15
5 4 0 2 6 3 11
7 6 2 0 4 1 9
11 10 6 4 0 3 5
8 7 3 1 3 0 8
16 15 11 9 5 8 0

*/
