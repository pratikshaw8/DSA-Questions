class Solution {
public:
    static bool  mycmp(vector<int> &a, vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin() , envelopes.end() , mycmp);
        vector<int> ans;
        vector<int> heights;
        for(int i=0;i<envelopes.size();i++)
        {
            heights.push_back(envelopes[i][1]);
        }
        
        ans.push_back(heights[0]);
        
        for(int i=1;i<heights.size() ;i++)
        {
            
            if(ans.back() < heights[i]  )
                ans.push_back(heights[i]);
            else
            {
                int idx= lower_bound(ans.begin() ,ans.end() , heights[i]) - ans.begin();
                ans[idx] =heights[i];
            }
        }
        return ans.size();
    }
};