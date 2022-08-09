class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<m;i++)
        {
            nums2.push_back(nums1[i]);
        }
        
        int i=0,j=n;
         
        int idx=0;
        while(i<n and j<m+n)
        {
            if(nums2[i] <=nums2[j])
            {
                nums1[idx++] = nums2[i++];
            }
            else
                nums1[idx++] = nums2[j++];
        }
        while(i<n )
        {
            nums1[idx++] = nums2[i++];
        }
        while(j<m+n )
        {
            nums1[idx++] = nums2[j++];
        }
    }
};