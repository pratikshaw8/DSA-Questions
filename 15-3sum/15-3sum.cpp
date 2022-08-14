class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        vector<vector<int>> result; 
        sort(nums.begin(), nums.end());
    
        for(auto itr = nums.begin(); itr != nums.end() -2; )
        {
            if(*itr > 0  ) break;
            int target = - (*itr);

            auto first = (itr +1);
            auto last = (nums.end() -1); 
            while(first < last)
            {
                int sum = *first + *last;
                if( sum > target) --last;
                else if( sum < target) ++first;
                else
                {
                    result.push_back({*itr, *first, *last});

                    while ((first < last) && (*(first + 1) == *first)) {
                        ++first;
                    }
                    ++first;

                    while ((first < last) && (*(last - 1) == *last)) {
                        --last;
                    }
                    --last;
                }
            }
            itr = upper_bound(itr, nums.end()-2,*itr );   
        }
        
        return result;   
    }
};