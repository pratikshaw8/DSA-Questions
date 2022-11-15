class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int left= 1,right=1,n=nums.size();
        int ans=INT_MIN;
        
        for(int i=0;i<n ; i++)
        {
            left*=nums[i];
            right*=nums[n-i-1];

            ans=max({ans,left,right,nums[i]});
            if(left==0) left=1;
            if(right == 0) right=1;
        }
        
        return ans;
    }
};