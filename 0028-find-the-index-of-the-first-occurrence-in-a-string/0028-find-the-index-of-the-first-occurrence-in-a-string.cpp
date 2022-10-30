class Solution {
public:
    vector<int> computeLPS(string needle)
    {
        int m=needle.length();
        vector<int> lps(m,0);
        
        int len=0,i=1;
        while(i<m)
        {
            if(needle[len] == needle[i])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len!=0)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        
        vector<int> lps= computeLPS(needle);
        int i=0,j=0;
        
        while(i<haystack.length())
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0)
                    j=lps[j-1];
                else
                    i++;
            }
            
            if(j==needle.length())
            {
                return i-j;
            }
        }
        return -1;
    }
};