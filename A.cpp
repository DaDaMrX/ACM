#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

int main()
{
	int n;
	scanf("%d", &n);
	printf("%s\n", n & 1 ? "contest" : "home");
	return 0;
}
