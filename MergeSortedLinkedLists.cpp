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
    void printList() {
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
            prev = slow; // previous of slow
            slow = slow->next;
            fast = fast->next->next; // move fast pointer by 2 steps
        }
        if (prev != NULL)
            prev->next = NULL; // split at middle
        return slow; // slow = rightHead
    }
    Node* merge(Node* left, Node* right) {
        List ans; // creating object of List named ans => new LL
        Node* i = left;
        Node* j = right;
        while (i != NULL && j != NULL) {
            if (i->data < j->data) {
                ans.push_back(i->data);
                i = i->next;
            }
            else {
                ans.push_back(j->data);
                j = j->next;
            }
        }
        while (i != NULL) {
            ans.push_back(i->data);
            i = i->next;
        }
        while (j != NULL) {
            ans.push_back(j->data);
            j = j->next;
        }
        return ans.head;
    }
    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL)
            return head;
        Node* rightHead = splitAtMid(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);
        return merge(left, right);
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5); // 5->4->3->2->1->NULL
    cout << "Original list: ";
    ll.printList();

    ll.head = ll.mergeSort(ll.head);
    cout << "Sorted list: ";
    ll.printList();

    return 0;
}
