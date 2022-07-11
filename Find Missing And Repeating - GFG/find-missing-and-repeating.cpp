// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        
        
        long long int len=n;
        long long int sum =(len * (len+1))/2;
        long long int sqSum =(len * (len+1) * (2 * len+1))/6;
        
        for(int i=0;i<n;i++)
        {
            sum -= (long long)arr[i];
            sqSum -= (long long)arr[i] * (long long)arr[i];
        }
        int missing = (sum + sqSum/sum)/2;
        int repeating = missing - sum;
        
        int *ans = new int[2];
        ans[0] = repeating;
        ans[1] = missing;
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends