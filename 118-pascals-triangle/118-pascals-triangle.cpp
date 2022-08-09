class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        
        int n=0;
        for(int i=1;i<numRows ;i++)
        {
            vector<int> temp;
            for(int k=0; k<=ans[n].size() ;k++)
            {
                if(k==0 or k==ans[n].size())
                    temp.push_back(1);
                else
                    temp.push_back(ans[n][k] + ans[n][k-1]);
            }
            ans.push_back(temp);
            n++;
        }
        return ans;
    }
};