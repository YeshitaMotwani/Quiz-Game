#include<iostream>
#include<string>
using namespace std;

bool validAnagram(string str1, string str2)
{
    if(str1.length()!=str2.length())
    {
    cout<<"\nInvalid Anagram";
    return false;
    }
    int freq[26];
    for(int i=0;i<str1.length();i++)
    {
        int idx=str1[i]-'a';
        freq[idx]++;
    }
    for(int i=0;i<str2.length();i++)
    {
        int idx=str2.length()-'a';
        if(freq[idx]==0)
        {
            cout<<"\nInvalid Anagram";
            return false;
        }
        freq[idx]--;
    }
    cout<<"\nValid Anagram";
    return true;
}
int main()
{
    string str1,str2;
    cout<<"\nEnter string 1:";
    cin>>str1;
    cout<<"\nEnter string 2:";
    cin>>str2;
    cout<<validAnagram(str1,str2)<<endl;
    return 0;
}