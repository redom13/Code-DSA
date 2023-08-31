#include <iostream>

using namespace std;

class LList{
    int size,curPos;
    class Link{
        public:
        int elem; // These 2 variables r public,but as Link is not
        Link*next; // These 2 variables can't be accessed from outside
    };
    Link*head,*curr,*tail;
    
    public:
        void init(int k,int x)
        {
            tail=curr=head=new Link;
            size=k;
            curPos=0;
            for (int i=0;i<k;i++)
            {
                Link *tmp=new Link;
                cin>>tmp->elem;
                tail->next=tmp;
                //tmp=tail->next; -->This line gives segmentation fault
                // Cz tail->next does not hold any memory,but tail does
                if(i<k-1) tail=tmp;
            }
            //tail->next->next=NULL;
            //show();
        }
        void insert(int num)
        {
            Link*tmp=new Link;
            tmp->elem=num;
            tmp->next=curr->next;
            curr->next=tmp;
            if (tail==curr && size!=0) tail=curr->next;
            if (tail->next==curr) tail=curr;
            size++;
            //show();
            //cout<<-1<<endl;
            return;
        }
        int remove()
        {
            if (size==0)
            {
                cout<<"List is empty. Nothing to remove."<<endl;
                return -1;
            }
            if (curr==tail->next)
            {
                cout<<"Nothing to remove."<<endl;
                return -1;
            }
            int it=curr->next->elem;
            Link* tmp=curr->next;
            if (tail==curr && tail!=head)
            {
                tail=head;
                while(tail->next!=curr)
                {
                    tail=tail->next;
                }
            }
            if (curr->next==tail) tail=curr;
            curr->next=curr->next->next;
            delete tmp;
            size--;
            /*if (curPos==size) 
            {
                Link*tmp=head;
                while(tmp->next!=curr) tmp=tmp->next;
                curr=tmp;
            }*/
            //show();
            return it;
        }
        void moveToStart()
        {
            curr=head;
            curPos=0;
            //show();
            //cout<<-1<<endl;
            return;
        }
        void moveToEnd()
        {
            curr=tail;
            curPos=size-1;
            //show();
            //cout<<-1<<endl;
            return;
        }
        int length()
        {
            //show();
            return size;
        }
        void prev()
        {
            if (curr==head)
            {
                cout<<"U cannot perform prev operation here. There is no element before this one"<<endl;
                return;
            }
            Link*tmp=head;
            while(tmp->next!=curr) tmp=tmp->next;
            curr=tmp;
            //show();
            //cout<<-1<<endl;
            return;
        }
        void next()
        {
            if (curr==tail->next)
            {
                cout<<"U cannot perform next operation here. There is no element after this one"<<endl;
                return;
            }
            curr=curr->next;
            //show();
            //cout<<-1<<endl;
            return;
        }
        int currPos()
        {
            int ans=0;
            for (Link*tmp=head->next;tmp!=curr->next;tmp=tmp->next)
            {
                ans++;
            }
            //show();
            return ans;
        }
        void moveToPos(int pos)
        {
            if (pos<0 || pos>size)
            {
                cout<<"Invalid Position"<<endl;
                return;
            }
            curr=head;
            curPos=0;
            while (curPos!=pos)
            {
                curr=curr->next;
                curPos++;
            }
            //show();
            //cout<<-1<<endl;
            return;
        }
        int getValue()
        {
            //show();
            if (size==0)
            {
                cout<<"The list is empty!"<<endl;
                return -1;
            }
            if (curr==tail->next)
            {
                cout<<"No value at this position"<<endl;
                return -1;
            }
            return curr->next->elem;
        }
};