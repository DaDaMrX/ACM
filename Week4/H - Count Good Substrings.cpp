#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

char s[N];

int main()
{
	scanf("%s", s);
	ll len = strlen(s);
	ll even = 0, odd = 0;
	ll even_a = 0, odd_a = 0, even_b = 0, odd_b = 0;
	for (int i = 0; i < len; i++)
	{
		if (i & 1)
		{
			if (s[i] == 'a')
			{
				even += even_a;
				odd += odd_a + 1;
				odd_a++;
			}
			else
			{
				even += even_b;
				odd += odd_b + 1;
				odd_b++;
			}
		}
		else
		{
			if (s[i] == 'a')
			{
				even += odd_a;
				odd += even_a + 1;
				even_a++;
			}
			else
			{
				even += odd_b;
				odd += even_b + 1;
				even_b++;
			}
		}
	}
	printf("%lld %lld\n", even, odd);
	return 0;
}
