class Solution {
public:
    
    void solve(vector<string>& ans, string res, int n,int open, int close)
    {
        if(res.length()==n*2)
        {
            ans.push_back(res);
            res="";
            return;
        }
        
        
        
        if(open<n)
        {
            res+='(';
            solve(ans,res,n,open+1,close);
            res.pop_back();
        }
        
        
        if(close<n and close<open)
        {
            res+=')';
            solve(ans,res,n,open,close+1);
            res.pop_back();
        }
        
            
            
    
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        
        vector<string> ans;
        
        
        solve(ans,"",n,0,0);
        
        return ans;
        
    }
};