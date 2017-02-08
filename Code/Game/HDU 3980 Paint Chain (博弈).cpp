/*
HDU 3980 Paint Chain (博弈)
1.环形，在第一次涂m个后就称为链形，n<m特判
2.游戏拆分，一个状态n可以拆分为i和n-m-i，记忆化搜索sg值
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n, m;
int sg[N];

int get_sg(int n)
{
	if (~sg[n]) return sg[n];
	if (n < m) return sg[n] = 0;

	bool mex[N];
	memset(mex, false, sizeof(mex));
	int mid = (n - m) / 2;
	for (int i = 0; i <= mid; i++)
		mex[get_sg(i) ^ get_sg(n - m - i)] = true;

	int i = 0;
	while (mex[i]) i++;
	return sg[n] = i;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &m);
		printf("Case #%d: ", cas);
		if (n < m)
		{
			printf("abcdxyzk\n");
			continue;
		}
		memset(sg, -1, sizeof(sg));
		sg[0] = 0;
		if (get_sg(n - m)) printf("abcdxyzk\n");
		else printf("aekdycoin\n");
	}
	return 0;
}