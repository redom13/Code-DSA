#include <iostream>
#include "stack.cpp"

using namespace std;

template <typename T>
void show(stack<T> s)
{
    if (s.isEmpty())
        return;
    T x = s.pop();
    show(s);
    cout << x << " ";
}

int main()
{
    int x, k;
    cin >> x >> k;
    cout << "Enter the data type: " << endl;
    string str;
    cin >> str;
    if (str == "int")
    {
        stack<int> s(x);
        for (int i = 0; i < k; i++)
        {
            int it;
            cin >> it;
            s.push(it);
        }
        cout << "< ";
        show(s);
        cout << ">\n";
        int q = -1, p;
        int tmp;
        while (q)
        {
            cin >> q >> p;
            switch (q)
            {
            case 1:
                s.clear();
                cout << "< ";
                show(s);
                cout << ">\n";
                break;
            case 2:
                s.push(p);
                cout << "< ";
                show(s);
                cout << ">\n";
                break;
            case 3:
                tmp = s.pop();
                cout << "< ";
                show(s);
                cout << ">\n";
                if (tmp != -1)
                    cout << tmp << endl;
                break;
            case 4:
                cout << "< ";
                show(s);
                cout << ">\n";
                cout << s.length() << endl;
                break;
            case 5:
                cout << "< ";
                show(s);
                cout << ">\n";
                if (s.topValue() != -1)
                    cout << s.topValue() << endl;
                break;
            case 6:
                cout << "< ";
                show(s);
                cout << ">\n";
                if (s.isEmpty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            default:
                break;
            }
        }
    }
    else if (str == "char")
    {
        stack<char> s(x);
        for (int i = 0; i < k; i++)
        {
            char it;
            cin >> it;
            s.push(it);
        }
        cout << "< ";
        show(s);
        cout << ">\n";
        int q = -1;
        char tmp, p;
        while (q)
        {
            cin >> q >> p;
            switch (q)
            {
            case 1:
                s.clear();
                cout << "< ";
                show(s);
                cout << ">\n";
                break;
            case 2:
                s.push(p);
                cout << "< ";
                show(s);
                cout << ">\n";
                break;
            case 3:
                tmp = s.pop();
                cout << "< ";
                show(s);
                cout << ">\n";
                if (tmp != -1)
                    cout << tmp << endl;
                break;
            case 4:
                cout << "< ";
                show(s);
                cout << ">\n";
                cout << s.length() << endl;
                break;
            case 5:
                cout << "< ";
                show(s);
                cout << ">\n";
                if (s.topValue() != -1)
                    cout << s.topValue() << endl;
                break;
            case 6:
                cout << "< ";
                show(s);
                cout << ">\n";
                if (s.isEmpty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            default:
                break;
            }
        }
    }
    else if (str == "float")
    {
        stack<float> s(x);
        for (int i = 0; i < k; i++)
        {
            float it;
            cin >> it;
            s.push(it);
        }
        cout << "< ";
        show(s);
        cout << ">\n";
        int q = -1;
        float p;
        float tmp;
        while (q)
        {
            cin >> q >> p;
            switch (q)
            {
            case 1:
                s.clear();
                cout << "< ";
                show(s);
                cout << ">\n";
                break;
            case 2:
                s.push(p);
                cout << "< ";
                show(s);
                cout << ">\n";
                break;
            case 3:
                tmp = s.pop();
                cout << "< ";
                show(s);
                cout << ">\n";
                if (tmp != -1)
                    cout << tmp << endl;
                break;
            case 4:
                cout << "< ";
                show(s);
                cout << ">\n";
                cout << s.length() << endl;
                break;
            case 5:
                cout << "< ";
                show(s);
                cout << ">\n";
                if (s.topValue() != -1)
                    cout << s.topValue() << endl;
                break;
            case 6:
                cout << "< ";
                show(s);
                cout << ">\n";
                if (s.isEmpty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
                break;
            default:
                break;
            }
        }
    }
    return 0;
}