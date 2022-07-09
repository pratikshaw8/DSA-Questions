class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if(str.size() ==1 ) return str[0];
        
        string ans="";

        string mn=*min_element(str.begin(),str.end()) , mx=*max_element(str.begin(),str.end());
        int i=0;
        
        while(i< mn.length())
        {
            if(mn[i] == mx[i])
                ans+= mn[i];
            else
                break;
            i++;
        }
        return ans;
    }
};