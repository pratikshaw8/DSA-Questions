class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited,
             int i, int j)
    {
        int n = grid.size(), m = grid[0].size();
        
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j] == '0' or visited[i][j] == true) 
            return;
        
        visited[i][j] = true;
        
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i-1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int c= 0;
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j] == false and grid[i][j] == '1')
                {
                    c++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return c;
    }
};