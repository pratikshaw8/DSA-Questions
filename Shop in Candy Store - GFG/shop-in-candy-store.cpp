// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    static bool mycmp(int a,int b)
    {
        return a>b;
    }
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        int temp[N];
        
        copy_n(candies, N, temp);
        
        
        int minAmount=0;
        sort(temp,temp+N);
        
        int i=0,j=N-1;
        while(i<=j and j>=0)
        {
            minAmount+=temp[i];
            j=j-K;
            i++;
            
        }
        
        copy_n(candies, N, temp);
        int maxAmount=0;
        sort(temp,temp+N,mycmp);
        
        i=0;
        j=N-1;
        while(i<=j and j>=0)
        {
            maxAmount+=temp[i];
            j=j-K;
            i++;
            
        }
        vector<int> ans;
        ans.push_back(minAmount);
        ans.push_back(maxAmount);
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