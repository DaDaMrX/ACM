//Problem A Runes
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

char str[30], s[30];
bool book[10];

int calc(int a, char op, int b)
{
	int c;
	switch (op)
	{
		case '+': c = a + b; break;
		case '-': c = a - b; break;
		case '*': c = a * b; break;
	}
	return c;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		int len = strlen(str);

		int iop;
		for (int i = 1; i < len; i++)
			if (str[i] == '-' || str[i] == '+' || str[i] == '*')
			{
				iop = i;
				break;
			}
		
		int ieq;
		for (int i = 1; i < len; i++)
			if (str[i] == '=')
			{
				ieq = i;
				break;
			}
		
		memset(book, true, sizeof(book));
		for (int i = 1; i < len; i++)
			if (str[i] >= '0' && str[i] <= '9') 
				book[str[i] - '0'] = false;

		bool leader;
		if ((str[0] == '?' && iop > 1) || (str[iop + 1] == '?' && ieq > iop + 2) || (str[ieq + 1] == '?' && len > ieq + 2)) leader = true;
		else leader = false;
		
		char c;
		for (c = '0'; c <= '9'; c++)
		{
			if (!book[c - '0']) continue;
			if (c == '0' && leader) continue;
			if (c == '0')
			{
				bool b1 = s[0] == '-' && s[1] == '?';
				bool b2 = s[iop + 1] == '-' && s[iop + 2] == '?';
				bool b3 = s[ieq + 1] == '-' && s[ieq + 2] == '?';
				if (b1 || b2 || b3) continue;
			}

			strcpy(s, str);
			for (int i = 0; i < len; i++)
				if (s[i] == '?') s[i] = c;
			int a = atoi(s);
			int b = atoi(s + iop + 1);
			int c = atoi(s + ieq + 1);
			if (calc(a, s[iop], b) == c) break;
		}
		printf("%d\n", c <= '9' ? c - '0' : -1);
	}
	return 0;
}
