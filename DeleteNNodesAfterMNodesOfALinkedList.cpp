#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head, *tail;
    List() {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL)
            head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void printList(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    int size(Node* head)
    {
        int count=0;
        Node* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    void popNthNode(Node* head,int pos)
    {
        Node* temp=head;
        if(pos==1) //delete at front
        {
            head=head->next;
            delete temp;
        }
        if(pos==size(head)) //delete at end
        {
            Node* prev=NULL;
            while(temp!=tail)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            delete tail;
            tail=prev;
        }
        else{
           int i=1; //delete at specific pos other than front and end
           Node* prev=NULL;
           while(i<pos)
           {
            i++;
            prev=temp;
            temp=temp->next;
           }
           prev->next=temp->next;
           delete temp;
        }
    }
    Node* delNAfterM(Node* head,int M,int N)
    {
        Node* prev=head;
        while(prev)
        {
            for(int i=0;i<M-1 && prev;i++)
            {
                prev=prev->next;
            }
            if(!prev)
                return head;
            Node* curr=prev;
            for(int i=0;i<N && curr;i++)
            {
                curr=curr->next;
            }
            prev->next=curr?curr->next:NULL;
            prev=prev->next;
        }
        return head;
    }
};
int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.printList(ll.head);

    ll.head=ll.delNAfterM(ll.head,2,2);
    ll.printList(ll.head);
}