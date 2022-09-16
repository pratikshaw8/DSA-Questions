class Solution {
public:
    bool checkPalin(string s)
    {
        string rev=s;
        reverse(rev.begin(),rev.end());
        return rev == s;
    }
    void solve(string s, int i, vector<vector<string>> &ans, vector<string> & temp, string curr)
    {
        if(i == s.length() )
        {
            if(curr=="" and checkPalin(curr))
            ans.push_back(temp);
            return;
        }
        curr.push_back(s[i]);
        
        if(checkPalin(curr))
        {
            temp.push_back(curr);
            solve(s,i+1,ans,temp,"");
            temp.pop_back();
            
        }
        solve(s,i+1,ans,temp,curr);        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(s,0,ans,temp,"");
        return ans;
    }
};