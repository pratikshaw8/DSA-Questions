// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int minSum=0;
        int maxSum=0;
        
        int i=0,j=0;
        
        while(i+j <N)
        {
            minSum+=candies[i];
            maxSum+=candies[N-i-1];
            
            i++;
            j+=K;
        }
        vector<int> ans;
        ans.push_back(minSum);
        ans.push_back(maxSum);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends