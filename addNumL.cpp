#include <iostream>
#include "ll.h"

using namespace std;

int main()
{
    LList a,b,ans;
    a.init(0,1);
    b.init(0,1);
    int na,nb;
    cin>>na>>nb;
    a.moveToStart();
    b.moveToStart();
    for (int i=0;i<na;i++)
    {
        int tmp;
        cin>>tmp;
        a.insert(tmp);
        a.next();
    }
    a.moveToStart();
    for (int i=0;i<nb;i++)
    {
        int tmp;cin>>tmp;
        b.insert(tmp);
        b.next();
    }
    b.moveToStart();
    ans.init(0,1);
    int carry=0;
    while(a.length() || b.length())
    {
        int tmp;
        if(a.length() && b.length()) {tmp=(a.getValue()+b.getValue()+carry)%10;carry=(a.remove()+b.remove()+carry)/10;}
        else if (a.length()) {tmp=(a.getValue()+carry)%10;carry=(a.remove()+carry)/10;}
        else if (b.length()) {tmp=(b.getValue()+carry)%10;carry=(b.remove()+carry)/10;}
        ans.insert(tmp);
        ans.next();
    }
    if(carry) ans.insert(carry);
    for (ans.moveToStart();ans.currPos()<ans.length();ans.next())
    {
        cout<<ans.getValue()<<" ";
    }
    cout<<endl;
}