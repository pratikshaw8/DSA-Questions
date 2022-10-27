//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> leftSmaller(int arr[], int n)
    {
        stack<int> st;
        vector<int> ans(n);
        
        st.push(0);
        ans[0]=-1;
        
        for(int i=1;i<n;i++)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
            st.pop();
            
            ans[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> rightSmaller(int arr[], int n)
    {
        stack<int> st;
        vector<int> ans(n);
        
        st.push(n-1);
        ans[n-1]= n;
        
        for(int i=n-2 ; i >= 0 ; i--)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
            st.pop();
            
            ans[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> left,right;
        left = leftSmaller(arr,n);
        right = rightSmaller(arr,n);
        
        vector<int> ans(n,INT_MIN);
        for(int i=0;i<n;i++)
        {
            int pos = right[i] - left[i] -1;
            ans[pos-1] =max(ans[pos-1] , arr[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            ans[i] = max(ans[i],ans[i+1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends