#include <iostream>
#include <vector>
#include "stack.cpp"

vector<int>Lnge(vector<int>&v)
{
    vector<int>nge(v.size());
    stack<int>st;
    for (int i=v.size()-1;i>=0;i--)
    {
        while(!st.isEmpty() && v[i]>v[st.topValue()])
        {
            nge[st.pop()]=i+1;
        }
        st.push(i);
    }
    while (!st.isEmpty())
    {
        nge[st.pop()]=0;
    }
    return nge;
}

vector<int>Rnge(vector<int>&v)
{
    vector<int>nge(v.size());
    stack<int>st;
    for (int i=0;i<v.size();i++)
    {
        while(!st.isEmpty() && v[i]>v[st.topValue()])
        {
            nge[st.pop()]=i+1;
        }
        st.push(i);
    }
    while (!st.isEmpty())
    {
        nge[st.pop()]=0;
    }
    return nge;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>L=Lnge(v),R=Rnge(v);
    int mx=-1;
    for (int i=0;i<n;i++)
    {
        mx=max(mx,L[i]*R[i]);
    }
    cout<<mx<<endl;
}