class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size(), n=matrix[0].size();
        
        int rowStart=0,colStart=0,rowEnd=m-1,colEnd=n-1;
        
        
        while(rowStart<=rowEnd and colStart<=colEnd)
        {
            for(int c=colStart; c<=colEnd ;c++)
            {
                ans.push_back(matrix[rowStart][c]);
            }
            rowStart++;
            for(int r=rowStart ; r<=rowEnd ;r++)
            {
                ans.push_back(matrix[r][colEnd]);
            }
            colEnd--;
            
            if(colStart > colEnd || rowStart > rowEnd) break;
            
            for(int c = colEnd ; c>=colStart; c--)
                ans.push_back(matrix[rowEnd][c]);
            rowEnd--;
            for(int r=rowEnd ; r>=rowStart ; r--)
                ans.push_back(matrix[r][colStart]);
            colStart++;
        }
        return ans;
    }
};