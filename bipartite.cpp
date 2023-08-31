#include <bits/stdc++.h>
using namespace std;

vector<int>g[210];
vector<int>visited(210),level(210);

#define RED 2
#define GREEN 1
#define WHITE 0

bool isBipartite(int source){
    queue<int>q;
    q.push(0);
    visited[0]=RED;
    while (!q.empty()){
        int parent=q.front();
        
        q.pop();
        for (int child:g[parent]){
            if (!visited[child]){
                level[child]=level[parent]+1;
                if (level[child]%2==0) visited[child]=RED;
                else visited[child]=GREEN;
                q.push(child);
            }
            else if (visited[child]==visited[parent]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int nodes,edges;
    while (cin>>nodes && nodes){
        cin>>edges;
        for (int i=0;i<edges;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if (isBipartite(0)){
            cout<<"BICOLORABLE"<<endl;
        }
        else cout<<"NOT BICOLORABLE"<<endl;
    }
}