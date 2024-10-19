#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Job{
    public:
    int idx,deadline,profit;
    Job(int idx,int deadline,int profit)
    {
        this->idx=idx;
        this->deadline=deadline;
        this->profit=profit;
    }
};
int maxProfit(vector<pair<int,int>> pairs)
{
    int n=pairs.size();
    vector<Job> jobs; //vector of objects
    for(int i=0;i<n;i++){
        jobs.emplace_back(i,pairs[i].first,pairs[i].second); //idx,deadline,profit
    }
    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b)
    {
        return a.profit > b.profit;
    }); //lambda function => descending order on the basis of profit(second)
    cout<<"\nSelecting job"<<jobs[0].idx;
    int profit=jobs[0].profit;
    int safeDeadline=2; // 1 job has already been completed
    for(int i=1;i<n;i++)
    {
        if(jobs[i].deadline >= safeDeadline) //non-overlapping
        {
            cout<<"\nSelecting job"<<jobs[i].idx;
            profit+=jobs[i].profit;
            safeDeadline++;
        }
    }
    return profit;
}
int main(){
    int n=4;
    vector<pair<int,int>> pairs(n);

    pairs[0]=make_pair(4,20);
    pairs[1]=make_pair(1,10);
    pairs[2]=make_pair(1,40);
    pairs[3]=make_pair(1,30);
    cout<<"\nMaximum profit:"<<maxProfit(pairs);
    return 0;
}