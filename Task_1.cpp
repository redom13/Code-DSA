#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> graph[N];

int vis[N], level[N], parent[N];

int BFS(int source, int dest)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    parent[source] = -1;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (auto child : graph[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
        if (vis[dest])
            return level[dest];
    }
    return -1;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    int source, dest;
    cin >> source >> dest;
    int moves = BFS(source, dest);
    cout << moves << endl;
    if (moves == -1)
        return 0;
    stack<int> s;
    int i = dest;
    while (i != source)
    {
        s.push(i);
        i = parent[i];
    }
    s.push(source);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}