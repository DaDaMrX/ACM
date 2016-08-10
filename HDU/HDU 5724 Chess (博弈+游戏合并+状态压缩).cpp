/*
HDU 5724 Chess (博弈+游戏合并+状态压缩)
1.每行相互独立，是多个游戏的并，每一行中，棋子互相影响，不是简单的并
2.每一行完全相同，考虑每一行的各种状态，20列，1<<20=1e6，用状态压缩
3.对每一个状态S，枚举S的每一个1；对于每一个1，找到它后面第一个为0的位置，移动
4.对于此题，状态S是有序的，因为是向后移，数值大的状态的后继一定是数值小的状态，
故直接从小到大递推状态的sg值，不需要dfs
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int sg[1 << 20];
bool vis[25];

void set_sg()
{
	int states = 1 << 20;
	for (int S = 0; S < states; S++)
	{
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < 20; i++)
			if (S & 1 << i)
			{
				int j = i - 1;
				while (j >= 0 && (S & 1 << j)) j--;
				if (j < 0) continue;
				vis[sg[S & ~(1 << i) | (1 << j)]] = true;
			}
		int i = 0;
		while (vis[i]) i++;
		sg[S] = i;
	}
}

int main()
{
	set_sg();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int nim = 0;
		while (n--)
		{
			int m;
			scanf("%d", &m);
			int S = 0;
			while (m--)
			{
				int t;
				scanf("%d", &t);
				t = 20 - t;
				S |= 1 << t;
			}
			nim ^= sg[S];
		}
		if (nim) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}