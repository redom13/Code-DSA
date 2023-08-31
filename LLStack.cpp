#include <iostream>

using namespace std;

class link{
    public:
    int data;
    link*next;
};

class Stack{
    link*topp;
    int length;
    public:
    Stack(int size)
    {
        length=size;
        topp=NULL;
    }
    Stack()
    {
        length=0;
        topp=NULL;
    }
    void push(int n)
    {
        link*tmp=new link;
        tmp->data=n;
        tmp->next=topp;
        topp=tmp;
        length++;
    }
    int pop()
    {
        link*tmp=topp;
        topp=topp->next;
        int it=tmp->data;
        delete tmp;
        length--;
        return it;
    }
    int top()
    {
        return topp->data;
    }
    int size()
    {
        return length;
    }
    ~Stack()
    {
        while (topp!=NULL)
        {
            link*tmp=topp;
            topp=topp->next;
            delete tmp;
        }
        length=0;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;
    while(st.size())
    {
        cout<<st.pop()<<endl;
    }
}