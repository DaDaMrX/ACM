// Week1 G - Antisymmetry (Manacher) 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;


char s[N];
int n;

char ss[2 * N];
int ma[2 * N];

bool check(char c1, char c2)
{
	return c1 == '0' && c2 == '1' || c1 == '1' && c2 == '0' 
		|| c1 == '#' && c2 == '#';
}

void manacher()
{
	int len = n;
    int l=0;
    ss[l++] = '$';
    ss[l++] = '#';
    for(int i = 0; i < len; i++)
    {   
        ss[l++] = s[i];
        ss[l++] = '#';
    }
    ss[l] = 0;
    int mx = 0, id = 0;
    for(int i = 0; i < l; i++)
    {
        ma[i] = mx > i ? min(ma[2 * id - i], mx - i) : 1;
        while (check(ss[i + ma[i]], ss[i - ma[i]])) ma[i]++;
        if (ss[i] == '#' && i + ma[i] > mx) mx=i + ma[i], id = i;
	}
}

int main()
{
	scanf("%d%s", &n, s);
	manacher();
	ll ans = 0;
	for (int i = 0; i < 2 * n + 1; i++)
		if (ss[i] == '#')
			ans += ma[i] / 2;
	printf("%lld\n", ans);
	return 0;
}	
