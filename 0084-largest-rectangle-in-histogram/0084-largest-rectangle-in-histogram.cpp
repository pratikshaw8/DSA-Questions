class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &heights,int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!=-1 and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> &heights,int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            while(st.top()!=-1 and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next,prev;
        next = nextSmallerElement(heights,n);
        prev = prevSmallerElement(heights,n);
        
        int area= 0;
        
        for(int i=0;i<n;i++)
        {
            int l = heights[i];
            
            if(next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            area = max(area, l*b);
        }
        return area;
    }
};