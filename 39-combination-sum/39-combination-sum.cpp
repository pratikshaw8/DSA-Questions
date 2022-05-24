class Solution {
public:
    
    void solve( vector<vector<int>>& ans, vector<int>& candidates,vector<int>temp, int target,int sum)
    {
        if(sum==target)
        {
            sort(temp.begin(),temp.end());
            if( find(ans.begin(), ans.end(), temp) == ans.end() )
                ans.push_back(temp);
           
            return;
        }
        
        for(int i=0;i<candidates.size();i++)
        {
          
            if( candidates[i] +sum <=target )
            {
                sum+=candidates[i];
                temp.push_back(candidates[i]);
                solve(ans,candidates,temp,target,sum);
                sum-=candidates[i];
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        
        solve(ans,candidates,temp,target,0);
        
        return ans;
    }
};