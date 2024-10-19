#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;
void printItinerary(unordered_map<string,string> tickets)
{
       //Starting point
       unordered_set<string> to;
       for(pair<string,string> ticket : tickets) //from,to
       {
            to.insert(ticket.second);
       }
       string start="";
       for(pair<string,string> ticket : tickets)
       {
        if(to.find(ticket.first) == to.end()) //found != / not found -(from occur but, to - does not occur))=> ==
            //Starting point
            start=ticket.first;
       }
       //Plan print
    cout<<start<<"->";
    while(tickets.count(start)) //start exists in map(tickets)
    {
        cout<<tickets[start]<<"->";
        start=tickets[start];
    }
    cout<<"Destination\n";
}
int main(){
    unordered_map<string,string> tickets;
    tickets["Chennai"]="Bengaluru";
    tickets["Mumbai"]="Delhi";
    tickets["Goa"]="Chennai";
    tickets["Delhi"]="Chennai";
    printItinerary(tickets);
    return 0;
}
