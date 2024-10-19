#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class List
{
    public:
    Node* head,*tail;
    List()
    {
        head=NULL;
        tail=NULL;
    }
    void push_front(int val)
    {
        Node* newNode=new Node(val);
        if(head==NULL)
            head=tail=newNode;
        else
        {
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int val)
    {
        Node* newNode=new Node(val);
        if(head==NULL)
            head=tail=newNode;
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void printList()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void insertAtMiddle(int val,int pos)
    {
        Node* newNode=new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++)
        {
            if(temp==NULL)
            {
                cout<<"\nInvalid position";
                return;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void pop_front()
    {
        Node* temp=head;
        if(head==NULL)
            {
                cout<<"\nlinked list is empty";
                return;
            }
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void pop_back(){
        if(head==NULL)
        {
            cout<<"\nLinked list is empty";
            return;
        }
        Node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        } //temp points to 2nd last node
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    int iterSearch(int key)
    {
        Node* temp=head;
        int idx=0;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }
    int helper(Node* temp,int key)
    {
        if(temp==NULL)
            return -1; //key doesn't exist
        if(temp->data==key)
            return 0; //idx of head
        int idx=helper(temp->next,key);
        if(idx==-1)
            return -1; //key does not exist -> no need to add 1 => return 0; => incorrect
        return idx+1; //otherwise keep adding 1
    }
    int recSearch(int key)
    {
        return helper(head,key);
    }

    bool isCycle(Node* head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next; //1step
            fast=fast->next->next; //2 steps 

            if(slow==fast)
            {
                cout<<"\nCycle exists"<<endl;
                return true;
            }
        }
        cout<<"\nCycle does not exist";
        return false;
    }
    void removeCycle(Node* head)
    {
        //detect cycle
        Node* slow=head;
        Node* fast=head;
        bool isCycle=false;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next; //1step
            fast=fast->next->next; //2 steps 

            if(slow==fast)
            {
                cout<<"\nCycle exists"<<endl;
                isCycle=true;
                break;
            }
        }
        if(isCycle==false)
        {
            cout<<"\nCycle does not exist";
            isCycle=false;
        }
        slow=head; //cycle exists
        if(slow==head) //tail->next = head =>Last node is connected with first node
        {
            while(fast->next!=slow)
            {
                fast=fast->next;
            }
            fast->next=NULL; //remove cycle
            cout<<"\nCycle has been removed";
        }
        else{
            Node* prev=fast; //prev of fast
            while(fast!=slow)
            {
                slow=slow->next;
                prev=fast;
                fast=fast->next;
            }
            prev->next=NULL; //remove cycle
            cout<<"\nCycle has been removed"<<endl;
        }
    }
};
int main()
{
    List ll;
    /*ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1); //1->2->3->4->5
    ll.printList();*/
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.tail->next=ll.head; //cycle create
    ll.isCycle(ll.head);
    ll.removeCycle(ll.head);

    ll.pop_back();
    ll.printList();

    ll.pop_front();
    ll.printList();

    ll.insertAtMiddle(100,2);
    ll.printList();

    cout<<"\n100 is found at idx:"<<ll.iterSearch(100);
    cout<<"\n100 is found at idx:"<<ll.recSearch(100)<<endl;
    return 0;
}