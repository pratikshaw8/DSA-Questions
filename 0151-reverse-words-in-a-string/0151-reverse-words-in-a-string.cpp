class Solution {
public:
    string reverseWords(string s) {
        string ans="" ,word="";
        s = ' ' +s;
        for(int i=s.length() - 1 ; i >= 0 ; i--)
        {
             if(s[i] == ' ')
             {
                 if(word =="") continue;
                ans = ans + word + " ";
                 word="";
             }
             else
             {
                 word = s[i] + word;
             }
        }
        ans.pop_back();
        return ans;
        
    }
}; 