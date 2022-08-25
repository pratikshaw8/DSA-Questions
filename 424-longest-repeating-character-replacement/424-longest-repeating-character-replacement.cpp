class Solution {
public:
    int characterReplacement(string s, int k) {
        if(k==s.length())
            return k;
        
        unordered_map<char,int> mp;
        int i=0,j=0;
        int maxLen=0,ans=0;
        
        while(j<s.length())
        {
            mp[s[j]]++;
            maxLen=max(maxLen,mp[s[j]]);
            
            if(j-i+1-maxLen <= k)
                ans=max(ans,j-i+1);
            else
            {
                while(k < j-i+1-maxLen)
                {
                    mp[s[i]]--;
                    i++;
                }
            }
            j++;

        }
        return ans;
    }
};