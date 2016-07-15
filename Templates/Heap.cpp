/*
priority_queue
*/
#include <queue>
using namespace std;
priority_queue<int> q;
priority_queue<int, vector<int>, greater<int> > q;

/*
Heap

push(x)
top()
pop()
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 20
int heap[N], size;
inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1;}
inline int P(int i) { return i >> 1; }
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
    heap[++size] = x;
    up(size);
}
int top()
{
    return heap[1];
}
void down(int i)
{
    int mini = i;
    if (L(i) <= size && heap[L(i)] < heap[mini]) mini = L(i);
    if (R(i) <= size && heap[R(i)] < heap[mini]) mini = R(i);
    if (mini != i)
    {
        swap(heap[i], heap[mini]);
        down(mini);
    }
}
void pop()
{
    heap[1] = heap[size--];
    down(1);
}