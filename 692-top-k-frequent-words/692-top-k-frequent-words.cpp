class Solution {
public:
    struct myComp {     //Comparator object
        bool operator () (const pair<string, int>& p1, const pair<string, int>& p2) {
            if(p1.second!=p2.second)
                return p1.second<p2.second;
            else {
                return !lexicographical_compare(p1.first.begin(), p1.first.end(), p2.first.begin(),         p2.first.end());
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(const string &word:words)
        {
            mp[word]++;
        }
        priority_queue<pair<string, int>, deque<pair<string, int>>, myComp> pq(mp.begin(), mp.end());
        vector<string> ans;
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};