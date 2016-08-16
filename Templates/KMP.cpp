int next[N];
bool kmp(char text[], char pattern[])
{
	int lt = strlen(text);
	int lp = strlen(pattern);
	for (int i = 0, j = -1; i <= lp; i++, j++) //i为前缀长度，j为前缀的前缀等于后缀的长度，j严格小于i，起始next[0]=-1  i<=lp
	{
		next[i] = j;
		while (~j && pattern[i] != pattern[j]) j = next[j]; //若相等，跳出，加一；若不相等，回退，回退到-1就不再继续
	}
	int ans = 0;
	for (int i = 0, j = 0; i <= lt; i++, j++)
	{
		if (j == lp) return true;
		while (~j && text[i] != pattern[j]) j = next[j];  //j两层含义：之前匹配的长度为j，要比较模式串第j个
	}
	return false;
}