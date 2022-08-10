class Solution {
public:
    bool checkArr(vector<int> &b)
    {
        for(int i=0;i<b.size() ;i++)
        {
            if(b[i]!=0)
                return true;
        }
        return false;
    }
        
    int superPow(int a, vector<int>& b) {
        int mod=1337;
        int size=b.size();
        int ans=1;
        a=a%mod;
        
        while(checkArr(b))
        {
            if(b[size-1] & 1 ==1)
                ans = (ans* a)%mod;
            a = (a*a)%mod;
            
            int carry=0;
            for(int i=0;i<size;i++)
            {
                int temp= carry*10 + b[i];
                b[i] = temp/2;
                carry= temp%2;
            }
        }
        return ans%mod;
    }
};