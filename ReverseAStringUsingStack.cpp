#include<iostream>
#include<stack>
#include<string>
using namespace std;
string reverseAString(string str)
{
    stack<char> s;
    string ans;
    for(int i=0;i<str.size();i++)
    {
        s.push(str[i]);
    }
    while(!s.empty())
    {
        char top=s.top();
        ans+=top;
        s.pop();
    }
    return ans;
}
int main(){
    string str="Yeshita";
    cout<<"\nReversed string:"<<reverseAString(str)<<endl;
    return 0;
}