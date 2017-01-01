/********************************************************************************
Problem C. Graph Restoration (Floyd)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 310;

int n; 
ll adj[N][N], map[N][N];

void floyd()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

bool check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] != adj[i][j])
				return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%I64d", &adj[i][j]);
			map[i][j] = adj[i][j];
		}
	floyd();
	if (!check())
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++) printf("%I64d ", adj[i][j]);
		printf("%I64d\n", adj[i][n - 1]);
	}
	return 0;
}
