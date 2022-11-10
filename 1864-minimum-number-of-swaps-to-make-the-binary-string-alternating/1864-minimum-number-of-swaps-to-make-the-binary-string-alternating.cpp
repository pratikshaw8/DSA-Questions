class Solution {
public:
    int minSwaps(string s) {
        int ones=0,zeros=0;
        int mismatch=0;
        for(int i=0;i<s.length() ;i++)
        {
            if(s[i] == '0')
                zeros++;
            else
                ones++;
        }
        
        if(abs(zeros - ones) >1) 
            return -1;
        
        if(zeros > ones)
        {
            for(int i=0;i<s.length();i++)
            {
                if(i%2==0 and s[i] != '0')
                    mismatch++;
                else if(i%2==1 and s[i] != '1')
                {
                    mismatch++;
                }

            }
        }
        else if(ones > zeros)
        {
            for(int i=0;i<s.length();i++)
            {
                if(i%2==0 and s[i] != '1')
                    mismatch++;
                else if(i%2==1 and s[i] != '0')
                {
                    mismatch++;
                }
            }
        }
        else
        {
            int mismatch2=0;
            for(int i=0;i<s.length();i++)
            {
                if(i%2==0 and s[i] != '1')
                    mismatch++;
                else if(i%2==1 and s[i] != '0')
                {
                    mismatch++;
                }
            }
            
            for(int i=0;i<s.length();i++)
            {
                if(i%2==0 and s[i] != '0')
                    mismatch2++;
                else if(i%2==1 and s[i] != '1')
                {
                    mismatch2++;
                }
            }
            mismatch = min(mismatch,mismatch2);
        }
        return mismatch/2;
        
        
        
    }
};