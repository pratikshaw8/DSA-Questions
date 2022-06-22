// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	static bool cmp(const vector<int> &a,const vector<int> &b)
	{
	    return a[2] < b[2];
	}
	int findParent(vector<int>& parent, int node)
	{
	    if(parent[node]==node)
	    return node;
	    return parent[node]=findParent(parent,parent[node]);
	}
	void unionSet(int u, int v,vector<int>& parent, vector<int>& rank)
	{
	    u=findParent(parent, u);
        v=findParent(parent,v);
    
	    if(rank[u] <rank[v])
            parent[u]=v;
        else if(rank[v]<rank[u])
            parent[v]=u;
        else
        {
            parent[v]=u;
            rank[u]++;
        }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        /*PRIMS ALGORITHM
        
        vector<bool>mst(V,false);
        vector<int> parent(V,-1);
        vector<int>key(V,INT_MAX);
        
        parent[0]=-1;
        key[0]=0;
        int weight=0;
        
        for(int i=0;i<V;i++)
        {
            int mini=INT_MAX;
            int u;
            for(int x=0;x<V;x++)
            {
                if(mst[x]==false and mini > key[x])
                {
                    u=x;
                    mini=key[x];
                }
            }
            mst[u]=true;
            
            for(auto x:adj[u])
            {
                int v=x[0];
                int wt=x[1];
                
                if(mst[v]==false and key[v] > wt)
                {
                    key[v]=wt;
                    parent[v]=u;
                }
            }
        }
        for(int i=0;i<V;i++)
        weight+=key[i];
        
        return weight;
        */
        
        //KRUSKALS ALGORITHM
        vector<vector<int>> list;
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                list.push_back({i,j[0],j[1]});
            }
        }
        sort(list.begin(),list.end(),cmp);
        vector<int>parent(V);
        vector<int> rank(V,0);
        
        for(int i=0;i<V;i++)
        parent[i]=i;
        
        int weight=0;
        
        for(auto edge:list)
        {
            int u=findParent(parent,edge[0]);
            int v=findParent(parent,edge[1]);
            int wt=edge[2];
            
            if(u!=v)
            {
                weight+=wt;
                unionSet(u,v,parent,rank);
            }
        }
        return weight;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends