#include<iostream>
#include<string>
using namespace std;

bool stringSwap(string s1,string s2)
{
    if(s1.length()!=s2.length())
    return false;

    int firstDiffIndex=-1,secondDiffIndex=-1;
    for(int i=0;i<s1.length();++i)
    {
        if(s1[i]!=s2[i])
        {
            if(firstDiffIndex==-1)
            firstDiffIndex=i;
            else if(secondDiffIndex=-1)
            secondDiffIndex=i;
            else
            return false;
        }
    }
    return (firstDiffIndex!=-1 && secondDiffIndex!=-1 && s1[firstDiffIndex]==s2[secondDiffIndex] && 
    s1[secondDiffIndex]==s2[firstDiffIndex]);
}
int main()
{
    string s1,s2;
    cout<<"\nEnter string 1:";
    cin>>s1;
    cout<<"\nEnter string 2:";
    cin>>s2;
    cout<<"\n"<<stringSwap(s1,s2);
    return 0;
}