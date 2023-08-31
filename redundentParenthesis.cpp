#include <bits/stdc++.h>

using namespace std;

bool isRedundent(string s)
{
    stack<char>st;
    bool is=false;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]!=')') st.push(s[i]);
        else{
            bool flag= false;
            while (st.top()!='(')
            {
                if(st.top()=='+' || st.top()=='-' ||st.top()=='*' ||st.top()=='/') flag=true;
                st.pop();
            }
            if (!flag) {is =true;break;}
            else st.pop();
        }
    }
    if (is) return true;
    else return false;
}

int main(){
    string s;
    cin>>s;
    if (isRedundent(s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}