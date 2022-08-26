class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
     
        vector<int> ans;
        int n = arr.size();
        
        for(int i=0 ; i< n ; i++)
        {
            int idx = arr[i] % (n+1) ;
            arr[idx - 1] += (n+1);
        }
        
        for(int i=0 ; i < n ; i++)
        {
            if( (arr[i] / (n+1) ) >= 2)
            ans.push_back(i+1);
        }
        return ans;
    }
};