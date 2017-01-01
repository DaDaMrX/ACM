/********************************************************************************
CodeForces 746C Tram
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int s, x1, x2, t1, t2, p, d;
	scanf("%d%d%d%d%d%d%d", &s, &x1, &x2, &t1, &t2, &p, &d);
	int ans = abs(x2 - x1) * t2;
	if (p < x1 && x1 < x2)
	{
		if (d > 0)
		{
			ans = min(ans, (x2 - p) * t1);
		}
		else
		{
			ans = min(ans, (p + x2) * t1);
		}
	}
	else if (p < x2 && x2 < x1)
	{
		if (d > 0)
		{
			ans = min(ans, (s - p + s - x2) * t1);			
		}
		else
		{
			ans = min(ans, (p + s + s - x2) * t1);
		}		
	}
	else if (x1 < p && p < x2)
	{
		if (d > 0)
		{
			ans = min(ans, (s - p + s + x2) * t1);			
		}
		else
		{
			ans = min(ans, (p + x2) * t1);
		}
	}
	else if (x1 < x2 && x2 < p)
	{
		if (d > 0)
		{
			ans = min(ans, (s + s + x2 - p) * t1);			
		}
		else
		{
			ans = min(ans, (p + x2) * t1);
		}
	}
	else if (x2 < x1 && x1 < p)
	{
		if (d > 0)
		{
			ans = min(ans, (s - p + s - x2) * t1);			
		}
		else
		{
			ans = min(ans, (p - x2) * t1);
		}
	}
	else if (x2 < p && p < x1)
	{
		if (d > 0)
		{
			ans = min(ans, (s - p + s - x2) * t1);			
		}
		else
		{
			ans = min(ans, (p + s + s - x2) * t1);
		}
	}
	else if (p == x1 && p < x2)
	{
		if (d > 0)
		{
			ans = min(ans, (x2 - p) * t1);			
		}
		else
		{
			ans = min(ans, (p + x2) * t1);
		}
	}
	else if (p == x1 && p > x2)
	{
		if (d > 0)
		{
			ans = min(ans, (s - x1 + s - x2) * t1);			
		}
		else
		{
			ans = min(ans, (p - x2) * t1);
		}
	}
	else if (p == x2 && p > x1)
	{
		if (d > 0)
		{
			ans = min(ans, (s - p + s + x2) * t1);			
		}
		else
		{
			ans = min(ans, (p + x2) * t1);
		}
	}
	else if (p == x2 && p < x1)
	{
		if (d > 0)
		{
			ans = min(ans, (s - p + s + x2) * t1);			
		}
		else
		{
			ans = min(ans, (p + s + s - x2) * t1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
