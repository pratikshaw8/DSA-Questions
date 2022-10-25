class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int,int>> q;
        int ans=-1;
        int n=grid.size() , m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                    q.push_back({i,j});
            }
        }
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop_front();

                bool g=false;
                if(j-1 >=0 and grid[i][j-1] == 1)
                {
                    grid[i][j-1] = 2;
                    q.push_back({i,j-1});
                }

                if(i-1>=0  and grid[i-1][j] == 1)
                {
                    grid[i-1][j] = 2;
                    q.push_back({i-1,j});
                }

                if(j+1 < m and grid[i][j+1] == 1)
                {
                    grid[i][j+1] = 2;
                    q.push_back({i,j+1});
                }

                if(i+1<n and grid[i+1][j] == 1)
                {
                    grid[i+1][j] = 2;
                    q.push_back({i+1,j});
                }
            }
            ans++;            
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        if(ans==-1) return 0;
        return ans;
    }
};