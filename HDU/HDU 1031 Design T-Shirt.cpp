#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100
struct node
{
	int no;
	double data;
}a[N];
bool cmp1(node a, node b)
{
	if (a.data != b.data) return a.data > b.data;
	return a.no < b.no;
}
bool cmp2(node a, node b)
{
	return a.no > b.no;
}
int main()
{
	int n, m, k;
	while (~scanf("%d%d%d", &n, &m, &k))
	{
		memset(a, 0, sizeof(a));
		for (int j = 1; j <= m; j++) a[j].no = j;
		double t;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				scanf("%lf", &t);
				a[j].data += t;
			}

		sort(a + 1, a + 1 + m, cmp1);
		sort(a + 1, a + 1 + k, cmp2);
		for (int i = 1; i < k; i++) cout << a[i].no << ' ';
		cout << a[k].no << endl;
	}
	return 0;
}