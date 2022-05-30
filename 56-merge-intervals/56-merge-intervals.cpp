class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        stack<int> st1;
        st1.push(intervals[0][0]);
        stack<int> st2;
        st2.push(intervals[0][1]);
        
        
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] <= st2.top() and intervals[i][0] >=st1.top())
            {
                
                int top1=st1.top();
                st1.pop();
                st1.push(min(top1,intervals[i][0]));
                
                int top2=st2.top();
                st2.pop();
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
            vector<int> temp;
            temp.push_back(st1.top());
            temp.push_back(st2.top());
            st1.pop();
            st2.pop();
            ans.push_back(temp);
            temp.clear();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};