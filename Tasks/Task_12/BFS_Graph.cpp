
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>>& adj) 
{
    vector<bool> visited(adj.size(),false);
    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()) 
    {
        int node=q.front();
        q.pop();

        cout<<char('A'+node) <<" ";

        for (int neighbor:adj[node]) 
        {
            if(!visited[neighbor]) 
            {
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
}
