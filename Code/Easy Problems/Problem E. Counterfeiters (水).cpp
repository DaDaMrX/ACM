/********************************************************************************
Problem E. Counterfeiters (水)
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
	double p, q;
	scanf("%lf%lf", &p, &q);
	p /= 100; q /= 100;
	printf("%.15f\n", (p * p + q * q) / (p + q));
	return 0;
}
