#include <bits/stdc++.h>
#include "2105001_header.cpp"
using namespace std;
int main()
{
    freopen("in2.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    Priority_Queue<int> p;
    int choice = -1;
    int i,n;
    while (choice != 7 && cin >> choice)
    {

        // cout << "1. Insert\n2. FindMax\n3. ExtractMax\n4. IncreaseKey\n";
        // cout << "5. DecreaseKey\n6. Print\n7. Terminate" << endl;
        // cout << "Enter your choice: " << endl;
        switch (choice)
        {
        case 1:
            cin >> n;
            p.Insert(n);
            break;
        case 2:
            cout << "Max: " << p.FindMax() << endl;
            break;
        case 3:
            cout << "Max: " << p.ExtractMax() << " has been extracted" << endl;
            break;
        case 4:
            cin >> i >> n;
            p.IncreaseKey(i, n);
            break;
        case 5:
            cin >> i >> n;
            p.DecreaseKey(i, n);
            break;
        case 6:
            p.Print();
            break;
        case 7:
            p.Sort();
            p.Print();
            break;
        default:
            break;
        }
    }
}