#include <bits/stdc++.h>

using namespace std;

vector<int>NSNGE(vector<int>&v)
{
    stack<int>st;
    vector<int>nge(v.size()),nse(v.size()),ans(v.size());
    for (int i=0;i<v.size();i++)
    {
        while (!st.empty() && v[i]>v[st.top()])
        {
            nge[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()){
        nge[st.top()]=-1;
        st.pop();
    }
    for (int i=0;i<v.size();i++)
    {
        while (!st.empty() && v[i]<v[st.top()])
        {
            nse[st.top()]=v[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()){
        nse[st.top()]=-1;
        st.pop();
    }
    for (int i=0;i<ans.size();i++)
    {
        if(nge[i]!=-1) ans[i]=nse[nge[i]];
        else ans[i]=-1;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    vector<int>ans=NSNGE(v);
    for (auto val:ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;;
}