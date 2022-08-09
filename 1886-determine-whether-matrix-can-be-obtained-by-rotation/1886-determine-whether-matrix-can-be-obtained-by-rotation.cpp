class Solution {
public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        int n = matrix.size();
        int i=1;
        while(i<=4)
        {
            for(int i=0;i<n; i++)
            {
                for(int j=i; j< n;j++)
                {
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }

            for(int i=0;i<n;i++)
            {
                for(int j=0,k=n-1; j<k ;j++,k--)
                {
                    swap(matrix[i][j],matrix[i][k]);
                }
            }
            
            if(matrix == target)
                return true;
            
            i++;
        }
        return false;
        
        
        
    }
};