
class Solution {
public:
    static bool myComp(string &a,string &b){
        return a+b>b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for(auto x:nums)
        {
            res.push_back(to_string(x));
        }
        
        sort(res.begin(),res.end(),myComp);
        
        string ans="";
        for(auto x:res)
            ans+=x;
         if(ans[0]=='0')return "0";
        
        return ans;
    }
};