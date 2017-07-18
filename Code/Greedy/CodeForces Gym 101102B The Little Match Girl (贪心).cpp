//CodeForces Gym101102B The Little Match Girl (贪心)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

char s[N];
int num[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
char big[10] = { 0, 0, 1, 7, 4, 5, 9, 8 };
int pri[6] = { 6, 7, 3, 5, 4, 2 };

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d%s", &n, s);
		int sum = 0;
		for (int i = 0; i < n; i++) 
			sum += num[s[i] - '0'];
		for (int i = 0; i < n; i++)
		{
			int j = 0;
			while (sum - pri[j] < (n - 1 - i) * 2 || sum - pri[j] > (n - 1 - i) * 7) j++;
			sum -= pri[j];
			printf("%d", big[pri[j]]);
		}
		printf("\n");
	}
	return 0;
}
