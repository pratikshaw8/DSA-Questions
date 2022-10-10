class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp (s.length()+1,false);
        unordered_set<string> st(wordDict.begin() , wordDict.end());
        int n=s.length();
        dp[s.length()] = true;
        
        for(int i = n-1 ; i >=0 ; i--)
        {
            for(int j = i ; j <n ; j++)
            {
                string w = s.substr(i , j - i + 1);
                if(st.find(w) != st.end() and dp[j+1])
                {
                    dp[i] = true;
                    break;
                }
            }
            
        }
        
        return dp[0] ;
    }
};