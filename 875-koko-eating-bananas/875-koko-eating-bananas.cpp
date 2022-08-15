#define ll long long
class Solution {
public:
    bool check(vector<int> piles,ll h,ll i)
    {
        ll hrs=0;
        for(auto ele: piles)
        {
            if(ele %i ==0)
                hrs += ele/i;
            else
                hrs += ele/i+1;
        }
        if(hrs<=h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll l=1,hi=0,res=0;
        for(auto x : piles) hi=max(hi,(ll)x);
        
        while(l<=hi)
        {
            int m=(l+hi)/2;
            if(check(piles,h,m))
            {
                hi=m-1;
                res=m;
            }
            else
            {
                l=m+1;
            }
        }
        return res;
    }
};