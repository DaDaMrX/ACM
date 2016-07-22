#include <cstdio>
#include <cstring>
const int N = 1010;
const int INF = 0x7f7f7f7f;
int map[N][N], w[N], path[N][N];
int n;
void floyd()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			path[i][j] = j;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][k] < INF && map[k][j] < INF)
				{
					int cost;
					if ((cost = map[i][k] + w[k] + map[k][j]) < map[i][j])
					{
						map[i][j] = cost;
						path[i][j] = path[i][k];
					}
					else if (cost == map[i][j] && path[i][k] < path[i][j])
						path[i][j] = path[i][k];
				}
}
void printPath(int start, int finish)
{
	if (start == finish) printf("%d\n", finish);
	else
	{
		printf("%d-->", start);
		printPath(path[start][finish], finish);
	}
}
int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == -1) map[i][j] = INF;
			}
		for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
		floyd();
		int start, finish;
		while (scanf("%d%d", &start, &finish), ~start)
		{
			printf("From %d to %d :\n", start, finish);
			printf("Path: "); 
			printPath(start, finish); 
			printf("Total cost : ");
			if (finish == start) printf("0\n\n");
			else printf("%d\n\n", map[start][finish]);
		}
	}
	return 0;
}