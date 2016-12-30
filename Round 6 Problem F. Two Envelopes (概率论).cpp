/********************************************************************************
Round 6 Problem F. Two Envelopes (概率论)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%s\n", c > b ? "Stay with this envelope" : "Take another envelope");
	return 0;
}
