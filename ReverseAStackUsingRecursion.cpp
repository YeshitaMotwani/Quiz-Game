#include<iostream>
#include<stack>
using namespace std;
void pushAtBottom(stack<int> &s, int val) {
    if (s.empty()) {
        s.push(val); // Empty stack => top = bottom
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s, val); // Recursion
    s.push(temp); // Backtracking
}

void reverseAStack(stack<int> &s)
{
    if(s.empty())
        return;
    int temp=s.top();
    s.pop();
    reverseAStack(s);
    pushAtBottom(s,temp);
}
void printStack(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);
    reverseAStack(s);
    printStack(s);
    return 0;
}