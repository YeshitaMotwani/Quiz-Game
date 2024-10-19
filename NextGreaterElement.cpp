#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void nextGreater(vector<int> arr,vector<int> ans)
{
    stack<int> s;
    int idx=arr.size()-1;
    ans[idx]=-1; //No next greater element exists for last element in arr
    s.push(arr[idx]);
    for(idx=idx-1;idx>=0;idx--) //Traverse in opp. direction
    {
        int curr=arr[idx];
        while(!s.empty() && curr >= s.top()) //top element is less than current element => pop the top element from stack
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[idx]=-1; // No next greater element exists when stack is empty
        }
        else{
            ans[idx]=s.top();
        }
        s.push(curr);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr={8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    vector<int> ans={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    nextGreater(arr,ans);
    return 0;
}