class Solution {
public:
    
    vector<int> nextSmallerElement(vector<int> heights,int n)
    {
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);

        for(int i=n-1;i>=0;i--)
        {

            while(st.top()!=-1 and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int>heights,int n)
    {
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);

        for(int i=0;i<n;i++)
        {

            while(st.top()!=-1 and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        
        // Your code goes here
        int n=heights.size();
        vector<int>next(n);
        next=nextSmallerElement(heights,n);
        vector<int>prev(n);
        prev=prevSmallerElement(heights,n);
        
        int area=INT_MIN;
        
        for(int i=n-1;i>=0;i--)
        {
            
            int l=heights[i];
            
            
            if(next[i]==-1)
                next[i]=n;
            
            int b=next[i]-prev[i]-1;
            
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
        
    }
};