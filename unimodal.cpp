#include <bits/stdc++.h>
using namespace std;

bool isIncreasing(vector<int> &v, int mid){
    if (v[mid]>v[mid-1] && v[mid]<v[mid+1]) return true;
    return false;
}

bool isUnimodal(vector<int> &v, int mid){
    if (v[mid]>v[mid-1] && v[mid]>v[mid+1]) return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    int i=1,j=n-2;
    int ans=-1;
    while (i<j){
        int m = (i+j)/2;
        if (isUnimodal(v,m)){
            ans=m;
            break;
        }
        else if (isIncreasing(v,m)){
            i = m+1;
        }
        else{
            j = m-1;
        }
    }
    cout << ans+1 <<" "<<v[ans]<< endl;
}