#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class Student{
    public:
    string name;
    int marks;
    Student(string name, int marks)
    {
        this->name = name;
        this->marks = marks;
    }
};

struct ComparePair{
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2)
    {
        return p1.second < p2.second;
    }
};

int main(){
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;
    pq.push(make_pair("Yeshita", 100));
    pq.push(make_pair("Daivik", 98));
    pq.push(make_pair("Krish", 94));
    pq.push(make_pair("Dvit", 97));
    
    while(!pq.empty())
    {
        cout << "\nName: " << pq.top().first << ", Marks: " << pq.top().second;
        pq.pop();
    }
    
    return 0;
}
