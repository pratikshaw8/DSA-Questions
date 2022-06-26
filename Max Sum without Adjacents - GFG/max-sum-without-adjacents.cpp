// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here

	    int prev2=0;
	    int prev1=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        int inc=prev2+ arr[i];
	        int exc=prev1;
	        int ans=max(inc,exc);
	        prev2=prev1;
	        prev1=ans;
	    }
	    return prev1;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends