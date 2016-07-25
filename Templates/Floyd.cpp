/*
Floyd algorithm
有向图 无向图均可
自己到自己的距离可以为初始化为0，也可以求出
执行有限次后会退出，map[i][i]<0说明有负环
*/

//1. Floyd
int map[N][N];
int n, m;
void floyd()
{
	for (int i = 1; i <= n; i++) map[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][k] < INF && map[k][j] < INF)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

//2. Floyd + 路径还原
int map[N][N], pre[N][N];
int n, m;
void floyd()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pre[i][j] = i;
	for (int i = 1; i <= n; i++) map[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][k] < INF && map[k][j] < INF)
				{
					int sum = map[i][k] + map[k][j];
					if (sum < map[i][j])
					{
						map[i][j] = sum;
						pre[i][j] = pre[k][j];
					}
				}
}
void printPath(int from, int to)
{
	if (from == to)
	{
		printf("%d", from);
		return;
	}
	printPath(from, pre[from][to]);
	printf("-->%d", to);
}

//3. Floyd + 字典序路径
?