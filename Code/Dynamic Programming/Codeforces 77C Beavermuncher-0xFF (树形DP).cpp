#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

struct Edge
{
	int to, next;
} e[N * 2];
int head[N], num;
int n, m;
bool vis[N];

ll dp[N];
int val[N];

void add(int u, int v)
{
	e[num].to = v;
	e[num].next = head[u];
	head[u] = num++;
}

bool cmp(int a, int b) { return a > b; }
void dfs(int u)
{
	vis[u] = true;
	dp[u] = 1;
	int sum = 0;
	vector<ll> vec; vec.clear();
	for (int i = head[u]; i != -1; i = e[i].next)
	{
		int v = e[i].to;
		if (vis[v]) continue;
		val[v]--;
		dfs(v);
		vec.push_back(dp[v]);
		sum += val[v];
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < vec.size() && val[u]; i++)
	{
		dp[u] += vec[i] + 1;
		val[u]--;
	}
	int minx = min(val[u], sum);
	dp[u] += minx * 2;
	val[u] -= minx;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	memset(head, -1, sizeof(head));
	num = 0;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	int root;
	scanf("%d", &root);

	memset(vis, false, sizeof(vis));
	dfs(root);
	printf("%I64d\n", dp[root] - 1);
	return 0;
}