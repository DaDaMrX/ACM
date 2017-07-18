// CodeForces Gym101086L Chance (水)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

char s[35];
bool prime[25] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 
					  1, 0, 1, 0, 0, 0, 1, 0, 1, 0 };
int sum[N];
bool check(int x)
{
	itoa(x, s, 2);
	int len = strlen(s);
	int cnt = 0;
	for (int i = 0; i < len; i++)
		if (s[i] == '1') cnt++;
	return prime[cnt];
}

int main()
{
	sum[0] = 0;
	for (int i = 1; i < N; i++)
		sum[i] = check(i) ? sum[i - 1] + 1 : sum[i - 1];
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", sum[r] - sum[l - 1]);
	}
	return 0;
}
