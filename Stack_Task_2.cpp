#include <iostream>
#include <cstdlib>
#include <string>
#include "stack.cpp"

using namespace std;

void isBalanced(string str)
{
    for (int i=0;i<str.length();i++)
    {
        if (!isdigit(str[i]) && str[i]!='(' && str[i]!=')' && str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/')
        {
            cout<<"Not valid"<<endl;
            exit(1);
        }
    }
    stack<char> brackets;
    stack<char> all;
    bool flagBrac = true;
    bool flagAll = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            brackets.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (brackets.isEmpty())
            {
                flagBrac = false;
                break;
            }
            char c = brackets.pop();
            if (c != '(')
            {
                flagBrac = false;
                break;
            }
        }
    }
    if (!brackets.isEmpty())
        flagBrac = false;
    if (!flagBrac)
    {
        cout << "Not valid" << endl;
        exit(1);
    }
    int n = str.length();
    if (str[0] == '+' || str[0] == '*' || str[0] == '/' || str[n - 1] == '+' || str[n - 1] == '-' || str[n - 1] == '*' || str[n - 1] == '/')
    {
        cout << "Not valid" << endl;
        exit(1);
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == ')')
            all.push(str[i]);
        else if (!isdigit(str[i]))
        {
            char c = 0;
            if (!all.isEmpty())
                c = all.topValue();
            if (str[i-1]=='+' || str[i-1]=='-' || str[i-1]=='*' || str[i-1]=='/')
            {
                flagAll = false;
                break;
            }
            all.push(str[i]);
        }
    }
    if (!flagAll)
    {
        cout << "Not valid" << endl;
        exit(1);
    }
    else
        cout << "Valid expression" << endl;
}

int order(char operation)
{
    if (operation == '+' || operation == '-')
        return 1;
    if (operation == '*' || operation == '/')
        return 2;
    return 0; // So that the case of parenthesis is handled
}

float calculate(float a, float b, char operation)
{
    switch (operation)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

int main()
{
    string str;
    cin >> str;
    isBalanced(str);
    stack<float> value;
    stack<char> symbols;
    stack<int> position;
    char check = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            continue;
        if (str[i] == '(')
        {
            symbols.push(str[i]);
        }
        else if (isdigit(str[i]))
        {
            bool negative = false;
            char prev, b4prev;
            /*if (symbols.length() >= 1)
            {
                prev = symbols.pop();
                b4prev = symbols.topValue();
                symbols.push(prev);
                if (prev == '-' && b4prev == '(')
                    negative = true;
                prev=symbols.topValue();
                if (check=='(' && prev=='-') negative=true;
            }*/
            int val = 0;
            // The number can have more than one digit
            while (i < str.length() && isdigit(str[i]))
            {
                val = val * 10 + str[i] - '0';
                i++;
            }
            // The for loop will increment i,so i is reduced to balance that
            i--;
            /*if (negative)
            {
                val = -1 * val;
                symbols.pop(); // The negative sign b4 the number is omitted so that when
                // ')' is found,only the binary '-' is considered
            }*/
            value.push(val);
        }
        else if (str[i] == ')')
        {
            char c = 0;
            float ans;
            while ((c = symbols.pop()) != '(')
            {
                if (c == '-' && str[position.pop()] == '(')
                {
                    ans = value.pop();
                    value.push(-1 * ans);
                    continue;
                }
                float b = value.pop();
                float a = value.pop();
                /*if (c == '/' && b == 0)
                {
                    cout << "Undefined" << endl;
                    exit(1);
                }*/
                ans = calculate(a, b, c); // No need to check precedence in this case cz that will be dealt in the case of operators
                value.push(ans);
            }
        }
        else // In case of operators
        {
            char c = 0;
            // Order of parenthesis is taken 0,so that this loop ends when meets parenthesis
            while (!symbols.isEmpty() && order(c = symbols.topValue()) >= order(str[i]))
            {
                // If I used symbols.pop() above,it would still pop while checking the order even if
                // the 2nd condition is false
                if (order(c) >= order(str[i]))
                    symbols.pop();
                float b = value.pop();
                float a = value.pop();
                /*if (c == '/' && b == 0)
                {
                    cout << "Undefined" << endl;
                    exit(1);
                }*/
                float ans = calculate(a, b, c);
                value.push(ans);
            }
            if (str[i] == '-')
                position.push(i - 1);
            symbols.push(str[i]);
        }
    }
    // When the whole string is traversed,there will be at least 1 operator & 2 operands
    // Also there won't be any parenthesis
    // Precedence issues are dealt earlier
    while (!symbols.isEmpty())
    {
        char c = symbols.pop();
        float ans;
        if (c == '-' && !position.isEmpty() && position.pop() == -1)
        {
            ans = value.pop();
            value.push(-1 * ans);
            continue;
        }
        float b = value.pop();
        float a = value.pop();
        /*if (c == '/' && b == 0)
        {
            cout << "Undefined" << endl;
            exit(1);
        }*/
        ans = calculate(a, b, c);
        value.push(ans);
    }
    cout << "Computed value: " << value.topValue() << endl;
    return 0;
}