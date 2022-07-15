class Solution {
public:
    bool hasPath(vector<vector<int>>& adj, vector<bool>& visited,int src,int dest)
    {
        if(src==dest)
            return true;
        
        visited[src]=true;
        
        for(auto j: adj[src])
        {
            if(!visited[j])
            {
                visited[j]=true;
                if(hasPath(adj,visited,j,dest))
                    return true;
               
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size() ;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        
        return hasPath(adj,visited,source, destination);
    }
};