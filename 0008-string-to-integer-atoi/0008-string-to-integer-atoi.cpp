class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.length() and s[i] ==' ') i++;
        int sign=1;
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-')
                sign=-1;
            i++;
        }
        
        int64_t ans=0;
        while(s[i] >= '0' and s[i] <='9')
        {
            ans  =ans *10 + (s[i] - '0');
            if(ans > INT_MAX)
            {
                if(sign == -1) return INT_MIN;
                return INT_MAX;
            }
            i++;    
        }
        
        
        return sign * (int32_t)ans;
    }
};