#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define p pair<int,int>
#define f first
#define s second
#define FOR(i,n) for (int i=0;i<n;i++)  

int main(){
    int n,i;
    cin>>n;
    vector<p>wait;
    FOR(i,n){
        int x;
        cin>>x;
        wait.pb({x,i+1});
    }
    sort(wait.begin(),wait.end());
    float avg=0,prev=0;
    FOR(i,n){
        cout<<wait[i].second<<" ";
        avg+=prev;
        prev+=wait[i].first;
    }
    cout<<endl;
    cout<<avg/n<<endl;
}