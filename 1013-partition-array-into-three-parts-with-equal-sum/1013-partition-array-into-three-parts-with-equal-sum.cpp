class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(auto i: arr)
            sum += i;
        if(sum%3!=0)
            return false;
        
        int s=sum/3,count=0;;
        sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum == s){
                count++;
                sum=0;
            }
            
        }
        if(count >= 3)
            return true;
        return false;
        
    }
};