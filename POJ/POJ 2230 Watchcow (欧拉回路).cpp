#include <cstdio>
#include <vector>
using namespace std;
#define N 10010
vector<int> edge[N];
int n, m;
void euler(int x)
{
	for (int i = 0; i < edge[x].size(); i++)
	{
		int to = edge[x][i];
		if (to == -1) continue;
		edge[x][i] = -1;
		euler(to);
	}
	printf("%d\n", x);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	euler(1);
	return 0;
}
