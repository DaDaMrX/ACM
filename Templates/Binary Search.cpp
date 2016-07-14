//Binary Search
/*
整数二分：
初始化left为不满足题意的值，right为满足题意的值，即范围为(left, right]
然后检查终点mid是否满足题意，缩小范围
当right-left==1时，即可确定解为right 
*/
int binary(int minx, int maxx)
{
    int left = minx - 1, right = maxx;
    while (right - left > 1)
    {
        int mid = left + (right - left >> 1);
        if (check(mid)) right = mid;
        else left = mid;
    }
    return right;
}

/*
实数二分
*/
const double eps = 1e-5;
double binary(double minx, double maxx)
{
    double left = minx, right = maxx;
    while (right - left > eps)
    {
        double mid = left + (right - left) / 2;
        if (check(mdi)) right = mid;
        else left = mid;
    }
    return left;
}