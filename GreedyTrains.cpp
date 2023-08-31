#include <bits/stdc++.h>
using namespace std;
#define vp vector<pair<int, int>>
#define p pair<int, int>

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    vp times;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        times.push_back(make_pair(x, 2)); // 2 for arrival
        times.push_back(make_pair(y, 1)); // 1 for departure
    }
    sort(times.begin(), times.end());
    int max_platforms=0,platforms = 0;
    for (int i = 0; i < times.size(); i++)
    {
        if (times[i].second == 1)
        {
            platforms--;
        }
        else
        {
            platforms++;
        }
        max_platforms = max(max_platforms, platforms);
    }
    cout << max_platforms << endl;
}