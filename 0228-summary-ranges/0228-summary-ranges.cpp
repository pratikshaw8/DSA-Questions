class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        
        vector<string> ans;
        
        if(nums.size() == 0)
            return ans;
        if(nums.size() == 1)
        {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int32_t i=nums[0];
        string word="";
        word = to_string(i);
        word=word + "->";
        int32_t prev=i;
        
        for(int32_t j=1;j<nums.size() ; j++)
        {
            if(i+1 == nums[j])
            {
                i=nums[j];
            }
            else
            {
                if(prev != i)
                {
                    word += to_string(i);
                    ans.push_back(word);
                }else
                {
                    word.pop_back();
                    word.pop_back();
                    ans.push_back(word);
                }
                
                word.erase();
                i=nums[j];
                prev=i;
                word = to_string(i) +"->";
            }
        }
        
        if(prev != i)
        {
            word += to_string(i);
            ans.push_back(word);
        }else
        {
            word.pop_back();
            word.pop_back();
            ans.push_back(word);
        }
        
        return ans;
    }
};