// CodeForces Gym10097G Repair
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

ll a, b, a1, b1, a2, b2;

bool check()
{
	if (a1 + a2 <= a && max(b1, b2) <= b) return true;
	if (a1 + a2 <= b && max(b1, b2) <= a) return true;

	if (a1 + b2 <= a && max(b1, a2) <= b) return true;
	if (a1 + b2 <= b && max(b1, a2) <= a) return true;
	
	if (b1 + b2 <= a && max(a1, a2) <= b) return true;
	if (b1 + b2 <= b && max(a1, a2) <= a) return true;

	if (b1 + a2 <= a && max(a1, b2) <= b) return true;
	if (b1 + a2 <= b && max(a1, b2) <= a) return true;

	return false;
}

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &a, &b, &a1, &b1, &a2, &b2);
	printf("%s\n", check() ? "YES" : "NO");
	return 0;
}

