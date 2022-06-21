// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
      void dfs(vector<vector<char>>& grid,int i,int j,int n,int m)
        {
            if(i<0 or i>=n or j<0 or j>=m or grid[i][j]=='0')
            return;
            
            grid[i][j]='0';
            dfs(grid,i+1,j,n,m);
            dfs(grid,i,j+1,n,m);
            dfs(grid,i-1,j,n,m);
            dfs(grid,i,j-1,n,m);
            dfs(grid,i+1,j+1,n,m);
            dfs(grid,i-1,j-1,n,m);
            dfs(grid,i-1,j+1,n,m);
            dfs(grid,i+1,j-1,n,m);
        }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int island=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!='0')
                {
                    island++;
                    dfs(grid,i,j,n,m);
                }
                
            }
        }
        return island;
    }
    

};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends