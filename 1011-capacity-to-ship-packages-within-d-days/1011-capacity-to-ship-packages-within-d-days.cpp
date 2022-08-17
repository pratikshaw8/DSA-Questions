class Solution {
public:
    bool check(vector<int> &weights, int days, int mid)
    {
        int sum=0;
        int cntDays=1;
        
        for(int i=0;i<weights.size();i++)
        {
            if(sum + weights[i] <= mid)
                sum +=weights[i];
            else
            {
                cntDays++;
                if(cntDays> days or mid < weights[i])
                    return false;
                else
                    sum=weights[i];
            }
        }
        return true;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0,e=0;
        for(int i = 0; i<weights.size(); i++){
            e += weights[i];
        }

        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(check(weights,days,mid)){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};