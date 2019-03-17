#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph,int* visited,int start)
{
    if(visited[start]==1)
    return ;// if it is visited again means there is a cycle
    visited[start]=1;
    // treverse the graph and call the dfs on the neighbours of the start
    for(int i=0;i<graph[start].size();i++)
    if(visited[graph[start][i]]==0)
    {dfs(graph,visited,graph[start][i]);}
}

int main()
{
    int v,e;
    cin>>v>>e;
    // we will use adjency list to show the graph
    vector<vector<int>> vertices(10001);
    // since it is tree and tree has n-1 edges for n nodes
    int s,end;
    for(int i=1;i<=e;i++)
    {
        cin>>s>>end;
        vertices[s].push_back(end);    
    }
    // now the graph has been made
    int *visited=new int[v+1];
    // making the visited array
    for(int i=1;i<=v;i++)
    visited[i]=0;
    
    dfs(vertices,visited,1);
    if(e==v-1)
    {
        int count=0;
        for(int i=1;i<=v;i++)
        count+=visited[i];
        if(count!=v)
        cout<<"NO";
        else
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}