class Solution {
public:
    void dfs(vector<int> graph[], vector<bool>& visited,int node)
    {
        visited[node]=true;
        
        for(auto x: graph[node])
        {
            if(!visited[x])
            {
                
                dfs(graph,visited,x);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)
            return -1;
        
        vector<int> graph[n];
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(graph,visited,i);
                
            }
        }
        return count-1;
    }
    
};