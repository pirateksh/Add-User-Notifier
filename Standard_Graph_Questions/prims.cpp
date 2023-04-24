//Question---> Find the minimum spanning spanning tree using Prims Algorithm.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<bool>visited(n+1,false);
    for(int i=0;i<m;i++)
    {
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({w,v});
      adj[v].push_back({w,u});
    }
    int cost=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int x=p.second;
        if(visited[x]==true)
        continue;

        cost+=p.first;
        visited[x]=true;

        for(auto i:adj[x])
        {
            int y=i.second;
            if(!visited[y])
            {
                pq.push(i);

            }
        }
    }
    cout<<cost<<endl;
    return 0;
}