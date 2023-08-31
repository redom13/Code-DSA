#include <bits/stdc++.h>

using namespace std;

template <typename T>class Bnode
{
public:
    T val;
    Bnode<T> *left;
    Bnode<T> *right;
    Bnode(T elem, Bnode<T> *l = NULL, Bnode<T> *r = NULL)
    {
        val = elem;
        left = l;
        right = r;
    }
};

template <typename T>
Bnode<T> *insert(Bnode<T> *rt, T key)
{
    if (rt == NULL)
    {
        rt = new Bnode<T>(key);
    }
    else if (key > rt->val)
    {
        rt->left = insert(rt->left, key);
    }
    else if (key < rt->val)
    {
        rt->right = insert(rt->right, key);
    }
    else
    {
    cout << "Duplate keys are not allowed" << endl;
    }
    return rt;
}

template <typename T>
void leaf(Bnode<T> *rt)
{
    if (rt == NULL)
        return;
    if (rt->left == NULL && rt->right == NULL)
    {
    cout << rt->val << " ";
        return;
    }
    leaf(rt->left);
    leaf(rt->right);
}

int main()
{
    Bnode<int> *root = NULL;
    int n;
cin >> n;
    while (n--)
    {
        int x;
    cin >> x;
        root = insert(root, x);
    }
    leaf(root);
}