#include <bits/stdc++.h>

using namespace std;
#define pb push_back
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int countStation()
{
    int count = 1;
    sort(v.begin(),v.end(),cmp);
    vector<pair<int,int>>tmp=v,helper;
    while (true){
        int ans=tmp[0].second;
        for (int i=1;i<tmp.size();i++){
            if (tmp[i].first<ans){
                helper.pb(tmp[i]);
            }
            else {
                ans=tmp[i].second;
            }
        }
        tmp=helper;
        helper.clear();
        //cout<<"Temp Size: "<<tmp.size()<<endl;
        if (!tmp.size()) break;
        count++;
    }
    return count;
}

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.pb({x, y});
    }
    cout<<countStation()<<endl;
}