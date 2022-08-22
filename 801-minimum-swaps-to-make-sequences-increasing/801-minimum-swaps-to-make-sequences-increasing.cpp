class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int idx,bool swapped, vector<vector<int>>& dp)
    {
        if(idx == nums1.size())
            return 0;
        if(dp[idx][swapped]!=-1) return dp[idx][swapped];
        
        int prev1=nums1[idx-1],prev2=nums2[idx-1];
        
        if(swapped)
            swap(prev1,prev2);
        int ans=INT_MAX;
        
        //noswap
        if(nums1[idx] > prev1 and nums2[idx] > prev2) 
            ans= solve(nums1,nums2,idx+1,0,dp);
        
        if(nums1[idx] > prev2 and nums2[idx] > prev1)
            ans= min(ans, 1 + solve(nums1,nums2,idx+1,1,dp) );
            
        return  dp[idx][swapped] = ans;
    }
    int tabulation(vector<int>& nums1, vector<int>& nums2)
    {
        int n=nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int idx = n-1; idx>=1;idx--)
        {
            for(int swapped=1; swapped>=0 ;swapped--)
            {
                int prev1=nums1[idx-1],prev2=nums2[idx-1];
        
                if(swapped)
                    swap(prev1,prev2);

                int ans=INT_MAX;

                //noswap
                if(nums1[idx] > prev1 and nums2[idx] > prev2){ 
                    ans= dp[idx+1][0];
                }

                if(nums1[idx] > prev2 and nums2[idx] > prev1){
                    ans= min(ans, 1 + dp[idx+1][1]);
                }

                dp[idx][swapped] = ans;
            }
            
        }
        return dp[1][0];
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        return tabulation(nums1,nums2);
//         vector<vector<int>> dp(n,vector<int>(2,-1));
        
//         int count = solve(nums1,nums2,1,0,dp);
//         return count;
    }
};