1. Shortest path: map初始化为INF，可以用来比较，但相加的话会溢出成为负值。
2. Shortest path: 输入边的时候需注意，可能有重边，保留权值最小的边。
3. 遇到加或乘的时候要注意，数据本身不溢出，加或乘之后就有可能溢出。
4. 数学模型-现实问题
5. 题目中不仅给出数据规模n，而且给出数据大小的范围时，要注意是否要用long long
6. Wrong Answer：long long，特判，%lf，cmath  