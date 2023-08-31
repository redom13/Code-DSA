#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
int vis[N],level[N],parent[N];

void BFS(int source,int dest){
    vis[source]=1;
    for (auto child:graph[source]){
        if (!vis[child]) {
            parent[child]=source;
            level[child]=level[source]+1;
            if (child==dest) return;
            BFS(child,dest);
        }
    }
    return;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    int source,dest;
    cin>>source>>dest;
    BFS(source,dest);
    if (level[dest]==0 && source!=dest){
        cout<<-1<<endl;
        exit(1);
    }
    cout<<level[dest]<<endl;
    stack<int>s;
    int i=dest;
    while (i!=source){
        s.push(i);
        i=parent[i];
    }
    s.push(source);
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}