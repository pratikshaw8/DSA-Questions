class Solution {
public:
    int mySqrt(int x) {
        int mod=1e9+7;
        int i=0,j=x;
        long mid=0;
        int ans=0;
        while(i<=j)
        {
            mid= i + (j-i)/2;
            long long sq= (mid*mid);
            if(sq ==x)
                return mid;
            else if(sq> x)
                j=mid-1;
            else
            {
                ans=mid;
                i=mid+1;
            }
        }
        return ans;
    }
};