class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int> curr(col+1,0);
        vector<int> prev(col+1,0);
        int res=0;
        
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(mat[i-1][j-1]=='0')
                    curr[j]=0;
                else
                {
                    int a=prev[j];
                    int b=curr[j-1];
                    int c=prev[j-1];
                    
                    curr[j]=1 + min(a,min(b,c));
                    res=max(curr[j],res);
                    
                }
            }
            prev=curr;
        }
        return res*res;
    }
};