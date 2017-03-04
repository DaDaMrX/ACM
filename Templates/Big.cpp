struct Big
{
	int a[N], len;
	bool sign;
	int power = 4, base = 10000;

	void reverse(char s[])
	{
		int len = strlen(s);
		int mid = len / 2 - 1;
		for (int i = 0; i <= mid; i++) swap(s[i], s[len - 1 - i]);
	}
	Big()
	{
		memset(a, 0, sizeof(a));
		sign = true;
		len = 1;
	};
	Big(char s[])
	{
		memset(a, 0, sizeof(a));
		sign = true;

		reverse(s);
		int ls = strlen(s);
		if (s[ls - 1] == '-') sign = false, ls--;

		len = -1;
		int w;
		for (int i = 0; i < ls; i++)
		{
			if (i % power == 0) a[++len] = 0, w = 1;
			a[len] += (s[i] - '0') * w;
			w *= 10;
		}
		len++;
	}
	Big(int x)
	{
		memset(a, 0, sizeof(a));
		if (x >= 0) sign = true;
		else sign = false, x = -x;

		a[0] = x;
		len = 0;
		while (a[len])
		{
			a[len + 1] = a[len] / base;
			a[len] %= base;
			len++;
		}
	}
	void print()
	{
		if (!sign) printf("-");
		printf("%d", a[len - 1]);
		for (int i = len - 2; i >= 0; i--) printf("%0*d", power, a[i]);
		printf("\n");
	}
};

bool operator<(Big& a, Big&b)
{
	if (!a.sign && b.sign) return true;
	if (a.sign && !b.sign) return false;
	if (a.sign)
	{
		if (a.len < b.len) return true;
		if (a.len > b.len) return false;
	}
	else
	{
		if (a.len < b.len) return false;
		if (a.len > b.len) return true;
	}

	bool flag = false;
	for (int i = a.len - 1; i >= 0; i--)
		if (a.a[i] < b.a[i])
		{
			flag = true;
			break;
		}

	return a.sign ? flag : !flag;
}

Big operator+(Big& a, Big& b)
{
	Big c;
	c.len = max(a.len, b.len);
	for (int i = 0; i < c.len; i++)
	{
		c.a[i] += a.a[i] + b.a[i];
		c.a[i + 1] = c.a[i] / c.base;
		c.a[i] %= c.base;
	}
	if (c.a[c.len]) c.len++;
	return c;
}

Big operator-(Big& a, Big& b)
{
	Big c;
	if (a < b) swap(a, b), c.sign = false;
	c.len = max(a.len, b.len);
	for (int i = 0; i < c.len; i++)
	{
		if (a.a[i] < b.a[i]) a.a[i + 1]--, a.a[i] += a.base;
		c.a[i] = a.a[i] - b.a[i];
	}
	while (c.len > 1 && c.a[c.len - 1] == 0) c.len--;
	return c;
}

Big operator*(Big& a, Big& b)
{
	Big c;
	c.sign = !(a.sign ^ b.sign);
	c.len = a.len + b.len - 1;
	for (int i = 0; i < a.len; i++)
		for (int j = 0; j < b.len; j++)
		{
			c.a[i + j] += a.a[i] * b.a[j];
			c.a[i + j + 1] += c.a[i + j] / c.base;
			c.a[i + j] %= c.base;
		}
	if (c.a[c.len]) c.len++;
	return c;
}

Big operator*(Big& a, int x)
{
	Big c;
	c.sign = a.sign;
	if (x < 0) c.sign = !c.sign, x = -x;
	for (int i = 0; i < a.len; i++)
	{
		c.a[i] += a.a[i] * x;
		c.a[i + 1] = c.a[i] / c.base;
		c.a[i] %= c.base;
	}
	c.len = a.len;
	if (c.a[c.len]) c.len++;
	return c;	
}

Big operator/(Big& a, int x)
{
	Big c;
	c.sign = a.sign;
	if (x < 0) c.sign = !c.sign, x = -x;
	for (int i = a.len - 1; i >= 0; i--)
	{
		c.a[i] = a.a[i] / x;
		a.a[i - 1] += a.a[i] % x * a.base;
	}
	c.len = a.len;
	if (!c.a[c.len - 1]) c.len--;
	return c;
}

Big power(int x, int n)
{
	Big a(x);
	Big ans(1);
	while (n)
	{
		if (n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}