#include<vector>
#include<queue>
#include<functional.h>
using namespace std;
struct Q
{
    int key,cnt;
    bool operator <(const Q &a,const Q &b)
    {
        return a.key<b.key;
    }
    bool operator >(const Q &a,const Q &b)
    {
        return a.key>b.key;
    }
}
struct Less
{
    bool operator () (const Q &a,const Q &b)
    {
        return a.key<b.key;
    }
}
priority_queue<int> heap;//大根堆
priority_queue<int,vector<int>,gerater<int>> heap;//小根堆
priority_queue<Q,vector<Q>,less<Q>> heap//结构体堆
int main()
{
    scanf("%d",&n);
    for(int i=1;<=n;i++)
    {
        scanf("%d",&a);
        heap.push(a);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",heap.top);
        heap.pop();
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&b.key,&b.cnt);
        heap.puse(b);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",heap.top().key,heap.top().cnt);
        heap.pop;
    }
}
