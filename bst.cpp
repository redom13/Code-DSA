#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
public:
    T elem;
    Node *lc, *rc;
    Node(T elem = 0, Node *left = NULL, Node *right = NULL)
    {
        this->elem = elem;
        lc = left;
        rc = right;
    }
};

template <typename T>
class BinSearchTree
{
    
    Node<T> *insert(Node<T> *rt, T key)
    {
        if (rt == NULL)
        {
            rt = new Node<T>(key);
        }
        else if (key > rt->elem)
        {
            rt->rc = insert(rt->rc, key);
        }
        else if (key < rt->elem)
        {
            rt->lc = insert(rt->lc, key);
        }
        else
        {
            cout << "Duplicate keys are not allowed" << endl;
        }
        return rt;
    }
    Node<T> *findMax(Node<T> *root)
    {
        if (root == NULL)
            return NULL;
        if (root->rc == NULL)
        {
            return root;
        }
        return findMax(root->rc);
    }
    Node<T> *findMin(Node<T> *root) //  Returns the address of the min node
    {
        if (root == NULL)
            return NULL;
        if (root->lc == NULL)
        {
            return root;
        }
        return findMin(root->lc);
    }
    Node<T> *delMax(Node<T> *root)
    {
        if (root->rc == NULL)
        {
            Node<T> *tmp = root;
            root = root->lc;
            delete tmp;
            return root;
        }
        root->rc = delMax(root->rc);
        return root;
    }
    Node<T> *delMin(Node<T> *root) // Returns the address of root after deletion
    {
        if (root->lc == NULL)
        {
            Node<T> *tmp = root;
            root = root->rc;
            delete tmp;
            return root;
        }
        root->lc = delMin(root->lc);
        return root;
    }
    Node<T> *delAny(Node<T> *root, T key)
    {
        if (root == NULL) // Key not found
        {
            return NULL;
        }
        if (key > root->elem)
        {
            root->rc = delAny(root->rc, key);
        }
        else if (key < root->elem)
        {
            root->lc = delAny(root->lc, key);
        }
        else // Key found
        {
            if (root->lc == NULL && root->rc == NULL) // Both child empty
            {
                delete root;
                return NULL;
            }
            else if (root->lc == NULL) // Left child empty
            {
                Node<T> *tmp = root;
                root = root->rc;
                delete tmp;
            }
            else if (root->rc == NULL) // Right child empty
            {
                Node<T> *tmp = root;
                root = root->lc;
                delete tmp;
            }
            else // Both non-empty child
            {
                Node<T> *tmp = findMin(root->rc);
                root->elem = tmp->elem;
                root->rc = delMin(root->rc);
            }
        }
        return root;
    }
    bool finD(Node<T> *root, T key)
    {
        if (root == NULL)
        {
            return false;
        }
        if (key > root->elem)
        {
            return finD(root->rc, key);
        }
        else if (key < root->elem)
        {
            return finD(root->lc, key);
        }
        else
            return true;
    }
    void in(Node<T> *root)
    {
        if (root == NULL)
            return;
        in(root->lc);
        cout << root->elem << " ";
        in(root->rc);
    }
    void pre(Node<T> *root)
    {
        if (root == NULL)
            return;
        cout << root->elem << " ";
        pre(root->lc);
        pre(root->rc);
    }
    void post(Node<T> *root)
    {
        if (root == NULL)
            return;
        post(root->lc);
        post(root->rc);
        cout << root->elem << " ";
    }
    void prinT(Node<T> *root)
    {
        if (root == NULL)
            return;
        cout << root->elem;
        if (root->lc == NULL && root->rc == NULL)
        {
            // cout<<",";
            return;
        }
        cout << "(";
        prinT(root->lc);
        cout << ",";
        prinT(root->rc);
        cout << ")";
    }

public:
    Node<T> *root;
    BinSearchTree()
    {
        root = NULL;
    }
    void Insert(T key)
    {
        root = insert(root, key);
        //Print();
    }
    void Delete(T key)
    {
        if (!finD(root, key))
        {
            // cout << "The element does not exist. Could not delete\n";
            //Print();
            return;
        }
        root = delAny(root, key);
        //Print();
    }
    void Traversal(string s)
    {
        if (s == "In")
        {
            in(root);
            cout << endl;
        }
        else if (s == "Pre")
        {
            pre(root);
            cout << endl;
        }
        else if (s == "Post")
        {
            post(root);
            cout << endl;
        }
    }
    void Find(T key)
    {
        if (finD(root, key))
            cout << "found" << endl;
        else
            cout << "not found" << endl;
    }
    void Print()
    {
        cout << "(";
        prinT(root);
        cout << ")\n";
    }
};

// int main()
// {
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
//     BinSearchTree<int> b;
//     // b.Find(1);
//     // b.Insert(8);
//     // b.Insert(10);
//     // b.Insert(3);
//     // b.Insert(1);
//     // b.Insert(14);
//     // b.Insert(6);
//     // b.Insert(4);
//     // b.Insert(13);
//     // b.Insert(7);
//     // b.Traversal("In");
//     // b.Traversal("Pre");
//     // b.Traversal("Post");
//     // b.Delete(8);
//     // b.Delete(1);
//     // b.Delete(10);
//     // b.Delete(10);
//     // b.Find(4);
//     char c;
//     while (cin>>c)
//     {
//         if (c=='I')
//         {
//             int n;
//             cin>>n;
//             b.Insert(n);
//             b.Print();
//         }
//         else if (c=='D')
//         {
//             int n;
//             cin>>n;
//             b.Delete(n);
//             b.Print();
//         }
//         else if (c=='F')
//         {
//             int n;
//             cin>>n;
//             b.Find(n);
//         }
//         else if (c=='T')
//         {
//             string s;
//             cin>>s;
//             b.Traversal(s);
//         }
//     }
// }