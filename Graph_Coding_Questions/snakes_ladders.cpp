//Question---> Snakes and ladders. The number on the dice is controlled by us. Find the minimum number of moves to reach 100.
/* Algorithm-> Time Complexity = O(N).
1) We can apply BFS.
2) Push 1 into the queue, for all possibilities in the dice:
Check if the next position is ladder, snake or empty.
Mark the square a visited and push into queue.
3) Stop the traversal, when you reached 100. */

#include<bits/stdc++.h>
using namespace std;
int main()
{
     int ladders,snakes;
     cin>>ladders;
     map<int,int>lad;
     map<int,int>snak;
     for(int i=0;i<ladders;i++)
     {
         int u,v;
         cin>>u>>v;
         lad[u]=v;
     }
     cin>>snakes;
     for(int i=0;i<snakes;i++)
     {
         int u,v;
         cin>>u>>v;
         snak[u]=v;
     }
     int moves=0;
     queue<int>q;
     q.push(1);
     bool found=false;
     vector<int>vis(101,0);
     vis[1]=1;
     while(!q.empty()&&!found)
     {
         int sz=q.size();
        while(sz--)
        {
            int t=q.front();
            q.pop();
            for(int die=1;die<=6;die++)
            {
                if(t+die==100)
                found=true;
                if(t+die<=100 && lad[t+die] && !vis[lad[t+die]])
                {
                    vis[lad[t+die]]=true;
                    if(lad[t+die]==100)
                    {
                        found=true;
                    }
                    q.push(lad[t+die]);
                }
                else if(t+die<=100 && snak[t+die] && !vis[snak[t+die]])
                {
                    vis[snak[t+die]]=true;
                    if(snak[t+die]==100)
                    found=true;

                    q.push(snak[t+die]);
                }
                else if(t+die<=100 &&!vis[t+die] && !snak[t+die] && !lad[t+die])
                {
                  vis[t+die]=true;
                  q.push(t+die);
                }

            }
           
        }
         moves++;
     }
        if(found)
        cout<<moves<<endl;
        else
        cout<<"-1"<<endl;

     return 0;

}
