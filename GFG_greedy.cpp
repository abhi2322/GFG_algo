#include<bits/stdc++.h>

using namespace std;

struct mycmp{

bool operator()(pair<int,int>&p1,pair<int,int>&p2)
{
    return p1.second<p2.second;
}
};

//function to solve activity selection problem
int activity_selection(vector<pair<int,int>>act)
{
    sort(act.begin(),act.end(),mycmp());
    int res=1;
    int last=act[0].second;
    for(auto x=act.begin()+1;x<act.end();x++)
    {
        if(x->first>=last)
        {
            last=x->second;
            res++;
        }
    }
    return res;
}

//function to solve Fractional Knapsack
bool my(pair<int,int>&p1,pair<int,int>&p2)
{
    double a1=(double)p1.second/p1.first;
    double a2=(double)p2.second/p2.first;
    return a1>a2;
}

int knapsack(vector<pair<int,int>>act,int n,int load)
{
   sort(act.begin(),act.end(),my);
    int res=0;
    for(int i=0;i<n;i++)
    {

        if(act[i].first<=load)
        {
            res+=act[i].second;

            load=load-act[i].first;
        }
        else
        {
            res+=act[i].second*load/act[i].first;
            break;
        }
    }
    return res;


}

int main()
{
    vector<pair<int,int>>act;
    int arr1[]={50,20,30};
    int arr2[]={1000,500,400};
    for(int i=0;i<3;i++)
    {
        pair<int,int>p1;
        p1.first=arr1[i];
        p1.second=arr2[i];
        act.push_back(p1);
    }
    cout<<knapsack(act,3,50);



}
