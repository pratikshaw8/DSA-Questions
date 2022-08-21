class Solution {
public:
    void merge(vector<pair<int,int>>&nums, int s,int mid, int r, vector<int>&ans)
    {
        int l=mid, e=r;
        while(l>=s and e>mid)
        {
            if(nums[l].first > nums[e].first){
                ans[nums[l].second] +=(e-mid);
                l--;
            }
            else
                e--;
        }
        sort(nums.begin()+s,nums.begin()+r+1);
    }
    void mergeSort(vector<pair<int,int>> &nums, int s, int r, vector<int> &ans)
    {
        if(s>=r)
            return ;
        int mid= s + (r-s)/2;
        mergeSort(nums,s,mid,ans);
        mergeSort(nums,mid+1,r,ans);
        merge(nums,s,mid,r,ans);
    }
    vector<int> countSmaller(vector<int>& v) {
        int n=v.size();
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++)
            nums.push_back({v[i],i});
        vector<int> ans(n,0);
        mergeSort(nums,0,n-1,ans);
        return ans;
    }
};