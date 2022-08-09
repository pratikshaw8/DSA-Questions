class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int x,y;
        
        set<int> row;
        set<int> col;
        
        for(int i=0;i<matrix.size() ;i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for(auto x: row)
        {
            for(int i=0;i<matrix[x].size() ; i++)
            {
                matrix[x][i]=0;
            }
        }
        for(auto x: col)
        {
            for(int i=0;i<matrix.size() ; i++)
            {
                matrix[i][x]=0;
            }
        }
        
    }
};