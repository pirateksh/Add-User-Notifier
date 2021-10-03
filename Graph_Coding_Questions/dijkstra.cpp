//Question---> Shortest path from source vertex to all other vertices. Dijsktra's Algortihm.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);

    for(int i=0;i<m;i++)
    {
       int x,y,w;
       cin>>x>>y>>w;
       adj[x].push_back({w,y});
       adj[y].push_back({w,x});
    }
    vector<bool>visited(n+1,false);
    vector<int>dist(n+1,INT_MAX);

   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
   pq.push({0,1});
   dist[1]=0;

   while(!pq.empty())
   {
       pair<int,int>p=pq.top();
       pq.pop();
       int u=p.second;
       
       if(visited[u])
       continue;

       visited[u]=true;

       for(auto i:adj[u])
       {
           int v=i.second;
           int weight=i.first;
           if(dist[u]+weight<dist[v])
           {
               dist[v]=dist[u]+weight;
               pq.push({dist[v],v});
           }
       }
   }
   for(int i=2;i<=n;i++)
   {
       cout<<dist[i]<<" ";
   }
return 0;

}
