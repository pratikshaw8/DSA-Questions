// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        // Your code goes here
        stack<long long>st;
        vector<long long>ans(n);
        st.push(-1);
        
        for(long long i=n-1;i>=0;i--)
        {
            
            
            while(st.top()!=-1 and st.top() <= arr[i])
            {
                
                st.pop();
            }https://media.geeksforgeeks.org/img-practice/play-1596780125.svg
            ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends