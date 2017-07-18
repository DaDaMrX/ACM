//CodeForces Gym 101149C Mathematical Field of Experiments
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 10;

int p, a[N];

int main()
{
	scanf("%d", &p);
	memset(a, -1, sizeof(a));
	for (int i = 0; i < p; i++) a[(ll)i * i % p] = i;
	for (int i = 0; i < p; i++) printf("%d ", a[i]);
	return 0;
}
