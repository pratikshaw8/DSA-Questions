class Solution {
public:
    int merge(vector<int> &nums,int l, int mid, int r)
    {
        vector<int> left(nums.begin() + l, nums.begin() + mid + 1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + r + 1);
        
        int count=0;
        
        
        int i=0,j=0;
        
        for(int k=l ; k<r+1 ; k++)
        {
            if(j == right.size() || (i < left.size() && left[i] <= right[j])){
         
                nums[k] = left[i++];
            }
            else
                nums[k] = right[j++];
        }
            
                
        
        
        i=0;
        j=0;
        while (i < left.size() && j < right.size()) {
            if (ceil(double(left[i]) / 2) > right[j]) {
                count += (left.size() - i);
                j++;
            }
            else {
                i++;
            }
        }
        
        return count;
    }
    int mergeSort(vector<int> &nums,int l, int r)
    {
        if(l<r)
        {
            int ans=0;
            int mid = l + (r-l)/2;
            
            ans+=mergeSort(nums,l,mid);
            ans+=mergeSort(nums,mid+1,r);
            ans+=merge(nums,l,mid,r);
            
            return ans;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums,0,nums.size()-1);
        
        
    }
};