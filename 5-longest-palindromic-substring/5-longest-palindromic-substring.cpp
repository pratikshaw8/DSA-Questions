class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int count=0;
        
        for(int gap=0;gap <n;gap++)
        {
            for(int start=0 ,end =gap; end <n;start++,end++)
            {
                if(gap==0)
                {
                    dp[start][end]=true;
                    
                }
                else if(gap==1){
                    dp[start][end]= s[start]==s[end];
                }
                else
                {
                    dp[start][end] = (s[start]==s[end] and dp[start+1][end-1]==true);
                    
                }
                if(dp[start][end]){
                    if(ans.length() < end-start+1)
                    {
                        ans=s.substr(start,end-start+1);
                    }
                }
                    
            }
        }
        return ans;
    }
};