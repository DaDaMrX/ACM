// Problem J palprime
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 25;

char s[N];

int btoi(char s[])
{
	int len = strlen(s);
	int ans = 0;
	for (int i = len - 1; i >= 0; i--)
		if (s[i] == '1')
			ans += 1 << (len - 1 - i);
	return ans;
}

int btoi(char s[])
{
	int len = strlen(s);
	int ans = 0;
	for (int i = 0; i < len; i++) 
	{
		ans <<= 1;
		if (s[i] == '1') ans += 1;
	}
	return ans;
}

void reverse(char s[])
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) 
		swap(s[i], s[len - 1 - i]);
}

char s1[N], s2[N];
bool pal(int x)
{
	itoa(x, s1, 2);
	strcpy(s2, s1);
	reverse(s2);
	return strcmp(s1, s2) == 0;
}

bool prime(int n)
{
	if (n == 0 || n == 1) return false;
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
		if (n % i == 0) return false;
	return true; 
}

int main()
{
	while (~scanf("%s", s))
	{
		int x = btoi(s);
		while (!pal(x) || !prime(x)) x++;
		itoa(x, s, 2);
		printf("%s\n", s);
	}
	return 0;
}
