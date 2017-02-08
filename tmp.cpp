#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

char str[30], s[30];

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
	printf("Hello\n");
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		int len = strlen(str);
		int iop, ieq;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == '+' || s[i] == '-' || s[i] == '*') iop = i;
			else if (s[i] == '=') ieq = i;
		}
		char c;
		for (c = '0'; c <= '9'; c++)
		{
			strcpy(s, str);
			for (int i = 0; i < len; i++)
				if (s[i] == '?') s[i] = c;
			int a = atoi(s);
			int b = atoi(s + iop + 1);
			int c = atoi(s + ieq + 1);
			if (calc(a, s[iop], b) == c) break;
		}
		printf("%d\n", c <= '9' ? c : -1);
	}
	return 0;
}

