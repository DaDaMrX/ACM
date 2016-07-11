#include <cstdio>
#include <cstring>
using namespace std;
#define N 20010
char a[N];
int n;
int main()
{
	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++) scanf("%c%*c", &a[i]);
	a[n] = '\n';
	int left = 0;
	int right = n - 1;
	int cmp, counter = 0;
	while (left <= right)
	{
		int i = left, j = right;
		while (i < j && !(cmp = a[i] - a[j])) i++, j--;
		if (i > j)
		{
			i--;
			while (left <= i)
			{
				printf("%c", a[left]);
				counter++;
				if (!(counter % 80)) printf("\n");
				printf("%c", a[left]);
				counter++;
				if (!(counter % 80)) printf("\n");
				left++;
			}
			break;
		}
		if (cmp < 0)
		{
			printf("%c", a[left++]);
			counter++;
			if (!(counter % 80)) printf("\n");
		}
		else
		{
			printf("%c", a[right--]);
			counter++;
			if (!(counter % 80)) printf("\n");
		}
	}
	if ((counter % 80)) printf("\n");
	return 0;
}
