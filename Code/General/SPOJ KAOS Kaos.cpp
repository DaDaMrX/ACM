#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int bit[N], n;
inline int lowbit(int i) { return i & -i; }
void init()
{
	memset(bit, 0, sizeof(bit));
}
void add(int i, int key)
{
	for (; i <= n; i += lowbit(i)) bit[i] += key;
}
int sum(int i)
{
	int ans = 0;
	for (; i; i -= lowbit(i)) ans += bit[i];
	return ans;
}

struct Str
{
	string str;
	int id;
} s[N];

char t[15];

bool cmp(Str s1, Str s2)
{
	return s1.str < s2.str;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", t);
		s[i].str = string(t);
	} 
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		s[i].id = i;
		reverse(s[i].str.begin(), s[i].str.end());
	}
	sort(s + 1, s + n + 1, cmp);
	// for (int i = 1; i <= n; i++) cout << s[i].str << ' ' << s[i].id << endl;
	init();
	ll ans = 0;
	for (int i = n; i >= 1; i--)
	{
		add(s[i].id, 1);
		// printf("%d\n", sum(s[i].id) - 1);
		ans += sum(s[i].id - 1);
	}
	printf("%lld\n", ans);
	return 0;
}
