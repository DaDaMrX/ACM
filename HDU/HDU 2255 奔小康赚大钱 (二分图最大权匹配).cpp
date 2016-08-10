/*
HDU 2255 奔小康赚大钱 (二分图最大权匹配)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 310;

int s[N][N], visx[N], visy[N], match[N];
int lx[N], ly[N];
int n, m;
int hungarian(int x) {
	visx[x] = 1;
	for (int i = 1;i <= m;i++) {
		if (!visy[i] && lx[x] + ly[i] == s[x][i]) {
			visy[i] = 1;
			if (!match[i] || hungarian(match[i])) {
				match[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
int KM() {
	int sum = 0;
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	memset(match, 0, sizeof(match));
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			lx[i] = max(lx[i], s[i][j]);
	for (int i = 1;i <= n;i++) {
		while (1) {
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (hungarian(i))break;
			else {
				int temp = INF;
				for (int j = 1;j <= n;j++) {
					if (visx[j]) {
						for (int k = 1;k <= m;k++)
							if (!visy[k])
								temp = min(temp, lx[j] + ly[k] - s[j][k]);
					}
				}
				if (temp == INF) return -1;
				for (int j = 1;j <= n;j++) if (visx[j]) lx[j] -= temp;
				for (int j = 1;j <= m;j++) if (visy[j]) ly[j] += temp;
			}
		}
	}
	for (int i = 1;i <= m;i++) {
		if (match[i] != 0) {
			if (s[match[i]][i] != -INF) sum += s[match[i]][i];
			else return -1;
		}
	}
	return sum;
}

int main()
{
	while (~scanf("%d", &n))
	{
		m = n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &s[i][j]);
		printf("%d\n", KM());
	}
	return 0;
}