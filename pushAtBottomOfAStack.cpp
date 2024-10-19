#include<iostream>
#include<stack>
using namespace std;
void pushAtBottom(stack<int> &s,int val)
{
    if(s.empty())
    {
        s.push(val); //Empty stack => top = bottom
        return;
    }
    int temp=s.top();
    s.pop();
    pushAtBottom(s,val); //Recursion
    s.push(temp); //Backtracking
}
int main()
{
    stack<int> s;
    int val=4;
    s.push(3);
    s.push(2);
    s.push(1);
    pushAtBottom(s,val);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}