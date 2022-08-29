class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,res=0;
        
        for(int x:nums)
        {
            if(x == 0)
            {
                res = max(res,c);
                c=0;
            }
            else
                c++;
        }
        res= max(res,c);
        return res;
    }
};