class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>> pq;
        for(int i=0;i<k;i++)
        {
            int x=points[i][0],y=points[i][1];
            int dist=x*x+y*y;
            pq.push({dist,x,y});
        }
        
        for(int i=k;i<points.size();i++)
        {
            int x=points[i][0],y=points[i][1];
            int dist = x*x +y*y;
            
            int D=pq.top()[0] , X=pq.top()[1] , Y=pq.top()[2];
            
            if(D> dist)
            {
                pq.pop();
                pq.push({dist,x,y});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> temp=pq.top();
            int x=temp[1],y=temp[2];
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};