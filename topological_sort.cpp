//Question ---> Topological Sort.
//Algorithm ---> Maintain a queue and if indegree of any node ==0, then only we will push into the queue.

#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>in(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        in[y]++;
    }

    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(in[i]==0)
        q.push(i);
    }
    
    int count=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(auto i=adj[x].begin();i!=adj[x].end();i++)
        {
           in[*i]--;
           if(in[*i]==0)
           q.push(*i);
        }
    }
    return 0;
}
