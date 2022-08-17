class Solution {
public:
    string minRemoveToMakeValid(string s) {
            
        string res="",sb="";
        
        int open=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] =='(')
                open++;
            else if(s[i]==')')
            {
                if(open==0)
                    continue;
                open--;
            }
            sb+=s[i];
        }

        for(int i=sb.size()-1;i>=0;i--)
        {
            if(sb[i] == '(' && open-- >0 ) continue;
            res +=sb[i];
        }
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};