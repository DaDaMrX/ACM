int n, k;
int rak[N], tmp[N];
bool cmp(int i, int j)
{
	if (rak[i] != rak[j]) return rak[i] < rak[j];
	int ri = i + k <= n ? rak[i + k] : -1;
	int rj = j + k <= n ? rak[j + k] : -1;
	return ri < rj;
}
void da(char s[], int sa[])
{
	n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		sa[i] = i;
		rak[i] = s[i];
	}
	sa[n] = n;
	rak[n] = -1;
	for (k = 1; k <= n; k *= 2)
	{
		sort(sa, sa + n + 1, cmp);
		tmp[sa[0]] = 0;
		for (int i = 1; i <= n; i++)
			tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
		memcpy(rak, tmp, sizeof(rak));
	}
}