#include <iostream>
#include "stack.cpp"

using namespace std;

long long getMaxArea(long long arr[], int n)
{
    long long larr[n],rarr[n],area[n];
    stack<int>sl,sr;
    for (int i=n-1;i>=0;i--)
    {
        while (!sl.isEmpty() && arr[i]<arr[sl.topValue()])
        {
            larr[sl.pop()]=i;
        }
        sl.push(i);
    }
    while (!sl.isEmpty())
    {
        larr[sl.pop()]=-1;
    }
    for (int i=0;i<n;i++)
    {
        while (!sl.isEmpty() && arr[i]<arr[sl.topValue()])
        {
            rarr[sl.pop()]=i;
        }
        sl.push(i);
    }
    while (!sl.isEmpty())
    {
        rarr[sl.pop()]=n;
    }
    long long mx=-1;
    for (int i=0;i<n;i++)
    {
        area[i]=(rarr[i]-larr[i]-1)*arr[i];
        mx=max(mx,area[i]);
    }
    return mx;
}

int main()
{
    int n;
    cin>>n;
    long long arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<getMaxArea(arr,n)<<endl;
}