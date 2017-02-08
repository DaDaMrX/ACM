/*
POJ 3537 Crosses and Crosses (博弈)
1.每一个子落下之后，左右两格的地方都不能落子，即转化为涂色问题，拆分
2.出现非法情况n<0，只需让其sg值为0即可，0不影响nim和
3.N=2e3，在本地跑会栈溢出，提交却可AC
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e3 + 10;

int sg[N];

int dfs(int n)
{
	if (n <= 0) return 0;
	if (~sg[n]) return sg[n];

	bool vis[N];
	memset(vis, false, sizeof(vis));
	int mid = n / 2 + 1;
	for (int i = 1; i <= mid; i++)
		vis[dfs(i - 3) ^ dfs(n - i - 2)] = true;

	int i = 0;
	while (vis[i]) i++;
	return sg[n] = i;
}

int main()
{
	int n;
	scanf("%d", &n);
	memset(sg, -1, sizeof(sg));
	int ans = dfs(n);
	if (ans) printf("1\n");
	else printf("2\n");	
	return 0;
}