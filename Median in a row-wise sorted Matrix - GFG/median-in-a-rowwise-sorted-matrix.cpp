// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &m, int r, int c){
        // code here
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(int i=0;i<r;i++)
        {
            mini=min(mini,m[i][0]);
            maxi=max(maxi,m[i][c-1]);
        }
        int half= (r*c+1)/2;
        
        while( mini <= maxi)
        {
            int mid=mini+ (maxi-mini)/2;
            
            int count=0;
            for(int i=0;i< r; i++)
                count += upper_bound(m[i].begin(), m[i].end() , mid) -m[i].begin();
            if(count<half)
            mini=mid+1;
            else
            maxi=mid-1;
        }
        return mini;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends