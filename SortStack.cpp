#include <iostream>
#include "stack.cpp"

using namespace std;

template <typename T>
void show(stack<T> s)
{
    if (s.isEmpty())
        return;
    T x = s.pop();
    show(s);
    cout << x << " ";
}

int main()
{
    int n;
    cin>>n;
    stack<int>s1(n);
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s1.push(x);
    }
    show(s1);
    cout<<endl;
    stack<int>tmpStack;
    while (!s1.isEmpty())
    {
        int tmp=s1.pop();
        while (!tmpStack.isEmpty() && tmp<tmpStack.topValue())
        {
            s1.push(tmpStack.pop());
        }
        tmpStack.push(tmp);
    }
    show(tmpStack);
}