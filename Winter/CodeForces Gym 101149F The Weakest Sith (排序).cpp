//CodeForces Gym 101149F The Weakest Sith (排序)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

struct Triple
{
	int a, b, c, i;
} t[N];

bool operator<(Triple& t1, Triple& t2)
{
	int cnt = 0;
	if (t1.a < t2.a) cnt++;
	if (t1.b < t2.b) cnt++;
	if (t1.c < t2.c) cnt++;
	return cnt >= 2;
}

int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d%d", &t[i].a, &t[i].b, &t[i].c), t[i].i = i +1;
	//sort(t, t + n);
    for (int i = n - 1; i > 0; i--)
        if (t[i] < t[i - 1]) swap(t[i], t[i - 1]);
	int i;
	for (i = 0; i < n; i++)
		if (t[i] < t[0]) break;
	if (i < n)
	{
		printf("0\n");
		return 0;
	}
	printf("1\n%d\n", t[0].i);
	return 0;
}
