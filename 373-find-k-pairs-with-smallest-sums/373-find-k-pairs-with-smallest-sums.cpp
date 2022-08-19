
class Solution {
public:
    class comp{
    public:
        bool operator()(pair <int,int> p1,pair <int,int> p2){
            return p1.first + p1.second < p2.first + p2.second;
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int n=nums1.size(),m=nums2.size();
        
        
        priority_queue <pair<int,int>,vector <pair<int,int>>,comp> pq;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { 
                int sum =nums1[i] + nums2[j];
                if(pq.size() < k)
                {
                    pq.push({nums1[i] , nums2[j]});
                }
                else if(pq.top().first + pq.top().second > sum){
                    pq.push({nums1[i],nums2[j]});
                    pq.pop();
                }
                else
                    break; 
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            int a=pq.top().first;
            int b=pq.top().second;
            ans.push_back({a,b});
            pq.pop();
        }
        return ans;
    }
};