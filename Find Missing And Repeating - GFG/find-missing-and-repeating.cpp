// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int repeat;
        int missing;
        for(int i=0;i<n;i++)
        {
            int idx=abs(arr[i]) - 1;
            if(arr[idx] <0)
            {
                repeat=arr[i];
            }
            else
                arr[idx]=-arr[idx];
            
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i] >0)
            {
                missing=i+1;
                break;
            }
        }
        int *ans=new int[2];
        ans[0]=abs(repeat);
        ans[1]=missing;
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