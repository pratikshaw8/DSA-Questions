class Solution {
public:
    struct myComp
    {
        bool operator()(const pair<int,int> &a, const pair<int,int> &b)
        {
            return a.second < b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int a:nums)
        {
            mp[a]++;
        }
        priority_queue<pair<int,int> ,vector<pair<int,int>> , myComp> pq(mp.begin(),mp.end());
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};