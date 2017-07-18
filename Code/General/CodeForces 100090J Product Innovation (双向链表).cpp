/********************************************************************************
Problem J. Product Innovation (双向链表)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

int n, p, q;
list<int> l;
list<int>::iterator it;

int main()
{
	scanf("%d%d", &n, &p);
	l.clear();
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		l.push_back(x);
	}
	it = l.begin();
	for (int i = 1; i < p; i++) it++;

	scanf("%d", &q);
	while (q--)
	{
		char s[15];
		scanf("%s", s);
		int len = strlen(s);
		if (len == 5)
		{
			printf("%d\n", *it);
		}
		else if (len == 8)
		{
			if (it != l.begin()) it--;
		}
		else if (len == 9)
		{
			it++;
			if (it == l.end()) it--;
		}
		else if (len == 10)
		{
			int x;
			scanf("%d", &x);
			it = l.insert(it, x);
			it++;
		}
		else
		{
			int x;
			scanf("%d", &x);
			it++;
			if (it == l.end())
			{
				l.push_back(x);
				it = l.end();
				it--; it--;
				continue;
			}
			it = l.insert(it, x);
			it--;
		}
	}
	return 0;
}
