# 单调栈 #

## 功能 ##
在O(n)的时间内得到以序列中每个点为最小（大）值的最大区间

## 描述 ##
以要得到数组`a[]`中以每个元素为最小值（并不严格最小）能够向右延拓到的最远位置为例，维护一个单调递增（并不严格递增）的栈，
从左向右扫描，若当前`a[i]`不满足单调性质，即`a[i]`小于等于栈顶元素时，则将栈顶元素弹出，直到满足性质或栈为空

从左向右扫描，则记录`right[]`数组，当新元素a[i]加入，且不满足单调栈性质，栈顶元素需要弹出时，要弹出元素向右延拓的最大位置便已经确定，
此时记录被弹出元素的`right[]`值，为`i-1`，若多个元素弹出，其`right[]`值均为`i-1`。
当所有元素均已扫描完毕，栈中仍有剩余元素时，说明它们均可延拓到数组最右端，记录`right[]`值为`n`。

若要得到每个元素向左延拓的边界，只需同样维护单调递增的栈，从右向左扫描。当某一元素不满足性质需弹出时，记录其`left[]`值为`i+1`，
当扫描完毕而栈中仍有剩余元素时，记录其`left[]`值为`1`。

为能定位元素的位置，栈中记录的是元素的下标而不是元素自身的值。

类似，根据不同的需求选择单调性不同的栈，递增或递减，严格单调或不严格单调。

亦可扫描一遍而同时记录`right[]`和`left[]`值，但须单独处理相等的情况。
同上文的例子，从左向右扫描，`right[]`值同上，在弹出时记录，`left[]`值在入栈时记录。
对于扫描到的当前元素`a[i]`，若`a[i]`大于栈顶元素，则说明`a[i]`不能向左拓展，即`a[i]`的`left[]`值为自身，`left[i]=i`，
若`a[i]`与栈顶元素相等，则`a[i]`的`left[]`值为栈顶元素的`left[]`值，若`a[i]`小于栈顶元素，则说明`a[i]`至少可以拓展到当前栈顶元素，
`a[i]`的`left[]`值为栈顶元素的`left[]`值（注意，是栈顶元素的`left[]`值，而不仅仅是栈顶元素的位置，
因为栈顶元素的左边可能已经弹出了若干个比它大的元素），若连续弹栈，则连续更新。可以看出，同时更新`left[]和right[]`值，
虽然只扫描一遍，但增加了相等时的判断，且在改变栈的单调性时不便修改，故一般选择左右各扫描一遍。

```C++
int st[N], top;
int right[N];
void monotone_toright(int n)
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
void monotone_toleft(int n)
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
```

# 单调队列 #

## 功能 ##
在O(n)的时间内得到序列中所有长度为k的区间中的最大（小）值

```C++
deque<int> dq;
dq.clear();
for (int i = 1; i < k; i++)
{
	while (!dq.empty() && a[i] < a[dq.back()]) dq.pop_back();
	dq.push_back(i);
}
for (int i = k; i <= n; i++)
{
	while (!dq.empty() && a[i] < a[dq.back()]) dq.pop_back();
	dq.push_back(i);
	while (!dq.empty() && i - dq.front() + 1 > k) dq.pop_front();

	printf("%d ", a[dq.front()]);
}
```