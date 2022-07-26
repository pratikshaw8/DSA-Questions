class Solution {
public:
    
    int numRollsToTarget(int n, int k, int target) {
        
        int mod=1e9+7;
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);        
        //analyze base case
        prev[0] = 1;
        
        
        for(int dices =1 ; dices <=n ; dices++)
        {
            for(int x = 1; x<=target ; x++)
            {
                int ans=0;
                
                for(int i=1; i<=k;i++)
                {
                    if(x-i >=0)
                    ans = (ans+ prev[x-i])%mod;
                }
                
                curr[x] = ans;
            }
            prev=curr;
        }
        return curr[target];
    }
};