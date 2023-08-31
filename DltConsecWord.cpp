#include <bits/stdc++.h>

using namespace std;

int removeConsecutiveSame(vector <string > v) 
    {
        stack<string>st;
        for (int i=0;i<v.size();i++)
        {
            if (!st.empty() && v[i]==st.top())
            {
                st.pop();
            }
            else st.push(v[i]);
        }
        return st.size();
    } 

int main()
{
    int n;
    cin>>n;
    vector<string>v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    cout<<removeConsecutiveSame(v)<<endl;
}