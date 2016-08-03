int st[N], top;
int right[N];
void monotone_left(int n)
{
	top = 0;
	for (int i = 1; i <= n; i++)
	{
		while (top && a[i] < a[st[top]])
		{
			right[st[top]] = i - 1;
			top--;
		}
		st[++top] = i;
	}
	while (top)
	{
		right[st[top]] = n;
		top--;
	}
}
int left[N];
void monotone_right(int n)
{
	top = 0;
	for (int i = n; i >= 1; i--)
	{
		while (top && a[i] < a[st[top]])
		{
			left[st[top]] = i + 1;
			top--;
		}
		st[++top] = i;
	}
	while (top)
	{
		left[st[top]] = 1;
		top--;
	}
}