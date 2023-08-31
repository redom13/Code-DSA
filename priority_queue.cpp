#include <bits/stdc++.h>
#include "heap.cpp"

using namespace std;

class Priority_Queue{
    MaxHeap<int>h;
    public:
    Priority_Queue(int size=10)
    {
        MaxHeap<int>tmp(size);
        h=tmp;
    }
    void push(int n)
    {
        h.insert(n);
    }
    int pop()
    {
        int ans=h.removeMax();
        return ans;
    }
    int length()
    {
        return h.curSize();
    }
    bool empty()
    {
        return !h.curSize();
    }
    int front()
    {
        return h.getMax();
    }
};

int main()
{
    Priority_Queue q;
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    cout<<"Max value: "<<q.front()<<endl;
    cout<<"Size: "<<q.length()<<endl;
    while (!q.empty())
    {
        cout<<q.pop()<<" ";
    }
    cout<<endl;
}