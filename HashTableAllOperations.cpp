#include<iostream>
#include<string>
using namespace std;
class Node
{
    public:
    string key;
    int val;
    Node* next;
    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }
    ~Node(){
        if(next!=NULL)
        {
            delete next;
        }
    }
};
class HashTable{
    int totSize,currSize; //currSize for ReHashing
    int hashFunction(string key){
        int idx=0;
        for(int i=0;i<key.size();i++)
        {
            idx=idx+ (key[i]*key[i]) % totSize; //to get valid idx within the range of table and to prevent overflow
        }
        return idx % totSize; //to prevent overflow in case of vvvv large values
    }
    void rehash() //O(n) - worst case
    {
        Node** oldTable=table;
        int oldSize=totSize;
        //For new table
        totSize=2*oldSize;
        currSize=0;
        table=new Node*[totSize]; //Creating new table
        for(int i=0;i<totSize;i++)
        {
            table[i]=NULL; //Assigning NULL to all indices of new table
        }
        //Copy old values to new table
        for(int i=0;i<oldSize;i++)
        {
            Node* temp=oldTable[i]; //Get head of oldTable at all indices
            while(temp!=NULL)
            {
                insert(temp->key,temp->val);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }
    public:
    Node** table;
    HashTable(int size=5){
        totSize=size;
        currSize=0;

        table=new Node*[totSize];
        for(int i=0;i<totSize;i++)
        {
            table[i]=NULL;
        }
    }
    void insert(string key,int val){
        int idx=hashFunction(key);
        //create a new node
        Node* newNode=new Node(key,val);
        //Insert this node at the head or Beginning of LL
        //Node* head=table[idx]; //Initially head=NULL as all values of table[idx] were initialized with NULL
        newNode->next=table[idx];
        table[idx]=newNode;
        currSize++;
        //For Rehashing
        double lambda=currSize/(double) totSize;
        if(lambda>1) //Threshold value=1(assume)
        {
            rehash();
        }
    }
    bool exists(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx]; //Get head of LL
        while(temp!=NULL)
        {
            if(temp->key==key) //found
            {
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    int search(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx]; //get head of LL
        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;
    }
    void print(){
        for(int i=0;i<totSize;i++){
            cout<<"idx:"<<i<<"->";
            Node* temp=table[i];
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<")->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    void remove(string key){
        int idx=hashFunction(key);
        Node* temp=table[idx];
        Node* prev=temp;
        while(temp!=NULL){ //O(lambda)
            if(temp->key==key) //found
            {
                if(prev==temp){
                    table[idx]=temp->next;
                }
                else{
                    prev->next=temp->next;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }
};
int main(){
    HashTable ht;
    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",50);
    ht.insert("Nepal",10);
    ht.insert("UK",20);
    if(ht.exists("India")){
        cout<<"\nIndia population:"<<ht.search("India");
    }
    ht.remove("China");
    ht.print();
    cout<<"\n---------";
    ht.remove("UK");
    ht.print();
    return 0;
}