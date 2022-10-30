class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int len= needle.length();
        string w = haystack.substr(0,len);
        
        int i=len;
        while(i<haystack.length())
        {
            if(w == needle)
                return i-len;
            w= w.substr(1);
            w.push_back(haystack[i]);
            i++;
        }
        if(w == needle)
                return i-len;
        return -1;
    }
};