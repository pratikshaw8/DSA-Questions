class Solution {
public:
    int nextGreaterElement(int n) {
        
        int i,j;
        string s=to_string(n);
        int len=s.length();
        for(i=len-1;i>=1;i--)
        {
            if(s[i-1] < s[i])
                break;
        }
        if(i==0)
            return -1;
        reverse(s.begin()+i , s.end());
        j=i-1;
        
        
        while(i<len)
        {
            if(s[j] < s[i])
            {
                swap(s[j],s[i]);
                break;
            }
            i++;
        }
        double ans=stod(s);
        if(ans >INT_MAX)
            return -1;
        return (int)ans;
    }
};