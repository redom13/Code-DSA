#include <bits/stdc++.h>
using namespace std;
#define INF 1e9 + 10

int kVis[100 * 100][100][100];
int kLevel[100 * 100][100][100];
int cellVis[100][100];
int m, n, q;

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < m && y < n;
}

void setLevel()
{
    for (int i = 0; i < 100 * 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                kLevel[i][j][k] = INF;
            }
        }
    }
}

vector<pair<int, int>> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
void BFS(pair<int, int> source, int i)
{
    queue<pair<int, int>> q;
    q.push(source);
    int x = source.first;
    int y = source.second;
    kVis[i][x][y] = 1;
    cellVis[x][y]++;
    kLevel[i][x][y] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        for (auto move : moves)
        {
            int childX = parent.first + move.first;
            int childY = parent.second + move.second;
            if (!isValid(childX, childY))
                continue;
            if (!kVis[i][childX][childY])
            {
                q.push({childX, childY});
                kVis[i][childX][childY] = 1;
                kLevel[i][childX][childY] = kLevel[i][parent.first][parent.second] + 1;
                cellVis[childX][childY]++;
            }
        }
    }
}

int main()
{
    setLevel();
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> m >> n >> q;
    int k[q];
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y >> k[i];
        pair<int, int> p = {x, y};
        BFS(p, i);
    }
    vector<pair<int, int>> cell;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout<<"Cell Visited: "<<cellVis[i][j]<<" ";
            if (cellVis[i][j] == q)
                cell.push_back({i, j});
        }
        // cout<<endl;
    }
    if (!cell.size())
    {
        cout << "-1" << endl;
        exit(1);
    }
    int minMove = INF, move;
    for (auto point : cell)
    {
        move = 0;
        for (int i = 0; i < q; i++)
        {
            if (k[i] >= kLevel[i][point.first][point.second] && kLevel[i][point.first][point.second])
            {
                move++;
            }
            else
                move += ceil(kLevel[i][point.first][point.second] / (float)k[i]);
        }
        minMove = min(minMove, move);
    }
    cout << minMove << endl;
}