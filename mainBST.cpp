#include <bits/stdc++.h>
#include "bst.cpp"

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    BinSearchTree<int> b;
    // b.Find(1);
    // b.Insert(8);
    // b.Insert(10);
    // b.Insert(3);
    // b.Insert(1);
    // b.Insert(14);
    // b.Insert(6);
    // b.Insert(4);
    // b.Insert(13);
    // b.Insert(7);
    // b.Traversal("In");
    // b.Traversal("Pre");
    // b.Traversal("Post");
    // b.Delete(8);
    // b.Delete(1);
    // b.Delete(10);
    // b.Delete(10);
    // b.Find(4);
    char c;
    while (cin>>c)
    {
        if (c=='I')
        {
            int n;
            cin>>n;
            b.Insert(n);
            b.Print();
        }
        else if (c=='D')
        {
            int n;
            cin>>n;
            b.Delete(n);
            b.Print();
        }
        else if (c=='F')
        {
            int n;
            cin>>n;
            b.Find(n);
        }
        else if (c=='T')
        {
            string s;
            cin>>s;
            b.Traversal(s);
        }
    }
}