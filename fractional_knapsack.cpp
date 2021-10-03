//Greedy ---->Fractional Knapsack


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int value,weight;
        cin>>value>>weight;
        v.push_back({value,weight});
    }
    
    sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
        double v1=(double)a.first/(double)a.second;
        double v2=(double)b.first/(double)b.second;
        return v1>v2;
    });
    
    int w;
    cin>>w;
   double ans=0;
 
    for(int i=0;i<n;i++)
    {
        if(w>=v[i].second)
        {
            ans+=v[i].first;
            w-=v[i].second;
            
        }
        else
        {
            double s=(double)v[i].first/(double)v[i].second;
            ans+=s*w;
            w=0;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
    
}
