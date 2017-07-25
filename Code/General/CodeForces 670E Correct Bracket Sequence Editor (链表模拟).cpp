#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>
#include <stack>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;

char s[N];

int main()
{
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	scanf("%s", s);
	list<char> l(s, s + n);
	list<char>::iterator it = l.begin();
	p--;
	while(p--) it++;
	scanf("%s", s);
	for (int i = 0; i < m; i++)
	{
		if (s[i] == 'L')
		{
			it--;
			continue;
		}
		else if (s[i] == 'R')
		{
			it++;
			continue;
		}
		if (*it == '(')
		{
			stack<char> st;
			st.push(*it);
			list<char>::iterator it2 = it;
			it2++;
			while (!st.empty())
			{
				if (*it2 == '(') st.push(*it2), it2++;
				else st.pop(), it2++;
			}
			it = l.erase(it, it2);
			if (it == l.end()) it--;
		}
		else
		{
			stack<char> st;
			st.push(*it);
			list<char>::iterator it2 = it;
			it2--;
			while (!st.empty())
			{
				if (*it2 == ')') st.push(*it2), it2--;
				else st.pop(), it2--;
			}
			it2++; it++;
			it = l.erase(it2, it);
			if (it == l.end()) it--;
		}
	}
	for (it = l.begin(); it != l.end(); it++) printf("%c", *it);
	printf("\n");
	return 0;
}