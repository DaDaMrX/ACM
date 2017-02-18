// CodeForces Gym101086A My Friend of Misery (模拟)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
typedef pair<int, bool> pib;

stack<pib> s;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		while (!s.empty()) s.pop();
		for (int i = 1; i <= n; i++)
		{
			int a;
			char c[3];
			scanf("%d%s", &a, c);
			pib p;
			p.first = a;
			p.second = c[0] == '+' ? true : false;
			s.push(p);
		}

		int l = 0, r = INF;
        while (!s.empty())
		{
			pib p = s.top(); s.pop();
			if (p.second)
			{
				l += p.first + 25;
				r += p.first + 25;
			}
			else
			{
				r = min(r, p.first + 25);
			}
		}

		printf("%d\n", r - l);
	}
	return 0;
}