#include<iostream>
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
    Node* head, * tail;
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
    Node* splitAtMid(Node* head) {
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL) {
            prev->next = NULL; // Split at middle
        }
        return slow; // slow is the head of the right half
    }
    Node* reverse(Node* rightHead) {
        Node* prev = NULL;
        Node* curr = rightHead;
        Node* nextNode = NULL;
        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // prev (lastNode) is head of reversed LL
    }
    Node* zigZagLL(Node* head)
    {
        bool flag=true;
        Node* temp=head;
        while(temp->next!=NULL)
        {
            if(flag)
            {
                if(temp->data > temp->next->data)
                    swap(temp->data,temp->next->data);
            }
            else
            {
                if(temp->data < temp->next->data)
                    swap(temp->data,temp->next->data);
            }
            temp=temp->next;
            flag=!flag;
        }
        return head;
    }
};
int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5); // 1->2->3->4->5
    ll.printList(ll.head);
    ll.head = ll.zigZagLL(ll.head);
    ll.printList(ll.head);
    return 0;
}
