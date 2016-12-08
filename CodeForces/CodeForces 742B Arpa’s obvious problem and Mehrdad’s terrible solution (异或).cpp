/************************************************************
CodeForces 742B Arpa’s obvious problem and Mehrdad’s terrible solution (异或)
x ^ x ^ y = y
x ^ y = z --> y = x ^ z
************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int n, x;
int cnt[N];

int main()
{
	scanf("%d%d", &n, &x);
	memset(cnt, 0, sizeof(cnt));
	while (n--)
	{
		int t;
		scanf("%d", &t);
		cnt[t]++;
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		if ((i ^ x) >= 0 && (i ^ x) < N)
			ans += cnt[i] * cnt[i ^ x];
	printf("%d\n", ans / 2);
	return 0;
}
