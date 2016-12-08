/*
priority_queue
*/
#include <queueu>
#include <functional>
priority_queue<int> q;
priority_queue<int, vector<int>, greater<int> > q;

/*
Heap

init()
push(x)
top()
pop()
*/
int heap[N], n;

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1;}
inline int P(int i) { return i >> 1; }

void init() 
{ 
    n = 0;
}

void up(int i)
{
    if (i == 1) return;
    if (heap[i] < heap[P(i)])
    {
        swap(heap[i], heap[P(i)]);
        up(P(i));
    } 
}
void push(int x)
{
    heap[++n] = x;
    up(n);
}

int top()
{
    return heap[1];
}

void down(int i)
{
    int mini = i;
    if (L(i) <= n && heap[L(i)] < heap[mini]) mini = L(i);
    if (R(i) <= n && heap[R(i)] < heap[mini]) mini = R(i);
    if (mini != i)
    {
        swap(heap[i], heap[mini]);
        down(mini);
    }
}
void pop()
{
    heap[1] = heap[n--];
    down(1);
}