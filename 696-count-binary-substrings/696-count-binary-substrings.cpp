class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int result=0;
        int prevGroup=0;
        int currGroup=1;
        
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
                currGroup++;
            else
            {
                result+= min(prevGroup,currGroup);
                prevGroup=currGroup;
                currGroup=1;
            }
        }
        result+= min(prevGroup,currGroup);
        return result;
        
    }
};