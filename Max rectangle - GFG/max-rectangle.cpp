// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> nextSmallerElement(int heights[],int n)
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
    
    vector<int> prevSmallerElement(int heights[],int n)
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
    int largestRectangleArea(int heights[],int n) {
        
        
        // Your code goes here
        
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
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        int area=largestRectangleArea(M[0],m);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]!=0)
                    M[i][j] += M[i-1][j];
                
                
            }
            
            int newArea=largestRectangleArea(M[i],m);
            area=max(area,newArea);
        }
        
        return area;
    }
};












// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends