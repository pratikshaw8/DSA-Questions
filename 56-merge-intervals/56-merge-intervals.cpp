class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;

        stack<int> st1;
        stack<int> st2;
        
        st1.push(intervals[0][0]);
        st2.push(intervals[0][1]);
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] <= st2.top() and intervals[i][0] >= st1.top())
            {
                int top1=st1.top(),top2=st2.top();
                st1.pop();
                st2.pop();
                
                st1.push(min(top1,intervals[i][0]));
                st2.push(max(top2,intervals[i][1]));
            }
            else
            {
                st1.push(intervals[i][0]);
                st2.push(intervals[i][1]);
            }
        }
        
        while(!st1.empty())
        {
            ans.push_back({st1.top(),st2.top()});
            st1.pop();
            st2.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};