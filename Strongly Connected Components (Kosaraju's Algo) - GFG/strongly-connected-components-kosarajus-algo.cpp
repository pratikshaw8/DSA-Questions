// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void TopoSort(vector<int>& vis, int node, vector<int> adj[],
              stack<int>& st)
    {
        vis[node]=1;
        
        for(auto i:adj[node])
        {
            if(!vis[i])
                TopoSort(vis,i,adj,st);
        }
        st.push(node);
    }
    void dfs(vector<int>& vis, vector<int> adj[], int node)
    {
        vis[node]=1;
        for(auto x: adj[node])
        {
            if(!vis[x])
                dfs(vis,adj,x);
        }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                TopoSort(vis,i,adj,st);
            }
        }
        vector<int> transpose[v];
        for(int i=0;i<v;i++)
        {
            vis[i]=0;
            for(auto nbr: adj[i])
            {
                transpose[nbr].push_back(i);
            }
        }
        int count=0;
    
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            if(!vis[top])
            {
                count++;
                dfs(vis,transpose,top);
            }
            
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends