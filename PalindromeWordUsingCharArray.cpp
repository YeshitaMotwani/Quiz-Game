#include<iostream>
#include <string.h>
using namespace std;

bool isPalindrome(char str[],int n)
{
    int start=0,end=n-1;
    while(start<end)
    {
        if(str[start++]!=str[end--])
        {
            cout<<"\nNot valid Palindrome";
            return false;
        }
    }
    return true;
}
int main()
{
    char str[50];
    cout<<"\nEnter a word:";
    cin>>str;
    cout<<isPalindrome(str,strlen(str));
}