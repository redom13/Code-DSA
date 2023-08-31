#include <bits/stdc++.h>
#include "bst.cpp"

using namespace std;

void storeInOrder(Node<int>* root,vector<int>&v)
{
    if (root==NULL) return;
    storeInOrder(root->lc,v);
    v.push_back(root->elem);
    storeInOrder(root->rc,v);
}

int SumKSmallest(Node<int>*root,int k)
{
    vector<int>v;
    storeInOrder(root,v);
    int sum=0;
    for (int i=0;i<k;i++) sum+=v[i];
    return sum;
}

int main()
{
    BinSearchTree<int>b;
    int n,k;
    cin>>n>>k;
    while (n--)
    {
        int x;
        cin>>x;
        b.Insert(x);
    }
    cout<<SumKSmallest(b.root,k);
    //b.Traversal("In");
}