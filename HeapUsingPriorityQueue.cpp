#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Heap{
    vector<int> vec;
    public:
    void push(int val){
    //Step 1: Push at vec last idx
    vec.push_back(val); 
    //Step 2: fix heap
    int x=vec.size()-1;
    int parI=(x-1)/2;
    while(parI>=0 && vec[x]>vec[parI]) //Max Heap
    //For Min heap => vec[x] < vec[parI]
    {
        swap(vec[x],vec[parI]);
        x=parI;
        parI=(x-1)/2;
    }
    }
    void heapify(int i) //i=parI
    {
       if(i>=vec.size())
            return;
        int l=2*i+1;
        int r=2*i+2;
        int maxI=i;

        if(l<vec.size() && vec[l]>vec[maxI]) //Max heap
        //Min heap => vec[l] < vec[minI]
        {
            maxI=l;
        }
         if(r<vec.size() && vec[r]>vec[maxI])
         //Min heap => vec[l] < vec[minI]
        {
            maxI=r;
        }
        swap(vec[i],vec[maxI]);
        if(maxI!=i) //Swapping with child node
        {
            heapify(maxI);
        }
    }
    void pop(){
        //Step 1: Swap Root and last node
        swap(vec[0],vec[vec.size()-1]);
        //step 2: pop back
        vec.pop_back();
        //Step3 : heapify
        heapify(0); //O(log n)

    }
    int top(){
        return vec[0];
    }
    bool isEmpty(){
        return vec.size()==0;
    }
};
int main(){
    Heap heap;
    heap.push(9);
    heap.push(4);
    heap.push(8);
    heap.push(1);
    heap.push(2);
    heap.push(5);
    while(!heap.isEmpty())
    {
        cout<<"\nTop:"<<heap.top();
        heap.pop();
    }
    return 0;
}
