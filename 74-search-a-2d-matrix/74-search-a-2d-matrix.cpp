class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r=matrix.size();
        int c=matrix[0].size();
        
        int i=0,j=c-1;
        
        while(i < r and j > -1)
        {
            int curr=matrix[i][j];
            if(curr==target)
                return true;
            else if( curr < target)
            {
                i++;
            }
            else
                j--;
        }
        return false;
    }
};