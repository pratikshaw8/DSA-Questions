// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    
   queue<int> q;
   int i=0,j=0;
   
   vector<long long> ans;
   
   for(long long int i=0;i<K;i++)
   {
       if(A[i]<0)
        q.push(A[i]);
       
   }
   j=K-1;
   while(j<N)
   {
        if(q.empty())
            ans.push_back(0);
        else
        {
            ans.push_back(q.front());
        }
        
        if(A[i] < 0)
            q.pop();
            
        if(A[j+1] and A[j+1]<0)
            q.push(A[j+1]);
            
        j++;
        i++;
        

   }
    return ans;
                                                 
 }