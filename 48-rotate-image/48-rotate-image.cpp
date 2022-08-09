class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int k=0;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=n-1;j>=0;j--)
            {
                temp.push_back(matrix[j][i]);
            }
            ans.push_back(temp);
        }
        matrix=ans;
    }
};