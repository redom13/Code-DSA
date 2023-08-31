#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define p pair<int,int>
bool cmp(p a,p b){
    return a.first>b.first;
}

vector<int>isTaken;


int main(){
    int n;
    cin>>n;
    vector<p>tasks(n),copy(n);
    vector<int>res;
    int mx=-1;
    for (int i=0;i<n;i++){
        cin>>tasks[i].first>>tasks[i].second;
        copy[i].first=tasks[i].first;
        copy[i].second=i+1;
        mx=max(mx,tasks[i].second);
    }
    isTaken.resize(mx+1);
    sort(tasks.begin(),tasks.end(),cmp);
    sort(copy.begin(),copy.end(),cmp);
    int ans=0;
    for (int i=0;i<n;i++){
        for (int j=tasks[i].second;j>0;j--){
            if (!isTaken[j]) {
                isTaken[j]=1;
                ans+=tasks[i].first;
                res.pb(copy[i].second);
                break;
            }
        }
    }
    sort(res.begin(),res.end());
    for (auto result:res){
        cout<<result<<" ";
    }
    cout<<endl<<ans<<endl;
}