//Question---> Finding MST by Kruskal's Algorithm.
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
vector<int>parent(N);
vector<int>size(N);
void make_set(int i)
{
    parent[i]=i;
    size[i]=1;
}
int find_set(int v)
{
    if(v==parent[v])
    return v;
    return parent[v]=find_set(parent[v]);
}
void union_sets(int u,int v)
{
    u=find_set(u);
    v=find_set(v);
    if(u!=v)
    {
        if(size[u]<size[v])
             swap(u,v);
        parent[v]=u;
        size[u]+=size[v];
    } }

int main()
{
    for(int i=0;i<N;i++)
        make_set(i);
    int n,m,cost=0;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++)
    {
        int w,u,v;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    for(auto i:edges)
    {
        int w=i[0],u=i[1],v=i[2];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y)
        continue;
        else
        {
          cost+=w;
          cout<<u<<" "<<v<<endl;
          union_sets(u,v);
        }
    }
    cout<<cost<<endl;
    return 0;
}
