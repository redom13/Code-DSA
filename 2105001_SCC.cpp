#include <bits/stdc++.h>
using namespace std;
#define MAX 2000
#define pb push_back
int n;
vector<int> g[52], rev_g[52];
int visited[52];
stack<int> st;
int noOfSCC = 1;
int SCC[52];
int val[52];
void dfs1(int src)
{
    visited[src] = 1;
    for (auto child : g[src])
    {
        if (!visited[child])
            dfs1(child);
    }
    st.push(src);
}

void dfs2(int src)
{
    visited[src] = 1;

    for (auto child : rev_g[src])
    {
        if (!visited[child])
            dfs2(child);
    }
    SCC[src] = noOfSCC;
}

int main()
{
    freopen("in99_.txt","r",stdin);
    freopen("out_mine.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1;
         if (cin.peek()=='\n'){
             s2=s1;
        }
        else cin>>s2;
        if (s1[0] == '~' && s2[0] == '~')
        {
            g[s1[1] - 'a'].pb(s2[1] - 'a' + 26);
            g[s2[1] - 'a'].pb(s1[1] - 'a' + 26);
            rev_g[s2[1] - 'a' + 26].push_back(s1[1] - 'a');
            rev_g[s1[1] - 'a' + 26].push_back(s2[1] - 'a');
        }
        else if (s1[0] == '~')
        {
            g[s1[1] - 'a'].pb(s2[0] - 'a');
            g[s2[0] - 'a' + 26].pb(s1[1] - 'a' + 26);
            rev_g[s2[0] - 'a'].pb(s1[1] - 'a');
            rev_g[s1[1] - 'a' + 26].pb(s2[0] - 'a' + 26);
        }
        else if (s2[0] == '~')
        {
            rev_g[s1[0] - 'a'].pb(s2[1] - 'a');
            rev_g[s2[1] - 'a' + 26].pb(s1[0] - 'a' + 26);
            g[s2[1] - 'a'].pb(s1[0] - 'a');
            g[s1[0] - 'a' + 26].pb(s2[1] - 'a' + 26);
        }
        else
        {
            g[s1[0] - 'a' + 26].pb(s2[0] - 'a');
            g[s2[0] - 'a' + 26].pb(s1[0] - 'a');
            rev_g[s2[0] - 'a'].pb(s1[0] - 'a' + 26);
            rev_g[s1[0] - 'a'].pb(s2[0] - 'a' + 26);
        }
    }
    for (int i = 0; i < 52; i++)
    {
        if ((g[i].size() || g[(i+26)%52].size())  && !visited[i])
            dfs1(i);
    }
    memset(visited, 0, sizeof(visited));
    //cout<<visited[0]<<endl;
    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        if ((rev_g[i].size() || rev_g[(i+26)%52].size()) && !visited[i])
        {
            dfs2(i);
            noOfSCC++;
        }
    }
    //cout<<SCC[0]<<" "<<SCC[26]<<endl;
    for (int i = 0; i < 26; i++)
    {
        if (g[i].size() || g[i+26].size())
        {
            if (SCC[i]==SCC[i+26]){
            cout << "No valid assignment possible" << endl;
            return 0;
            }
            else if (SCC[i]<SCC[i+26]){
                val[i+26]=1;
                val[i]=0;
            }
            else{
                val[i]=1;
                val[i+26]=0;
            }
        }
    }
    //cout << "Satisfiable" << endl;
    for (int i=0;i<26;i++){
        if (g[i].size() || g[i+26].size()){
            if (val[i]) {
                cout<<(char)('a'+i)<<" true"<<endl;
            }
            else cout<<(char)('a'+i)<<" false"<<endl;
        }
    }
}