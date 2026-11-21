#include <iostream>
#include <vector>

using namespace std;


void DFS(int node,vector<vector<int>>& adj,vector<bool>& visited) 
{

    visited[node]=true;
    cout<<char('A'+node) <<" ";

    for (int neighbor:adj[node]) 
    {
        if(!visited[neighbor]) 
        {
            DFS(neighbor,adj, visited);
        }
    }
}
