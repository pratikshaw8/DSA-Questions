//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int A[],int N, int M, int mid)
    {
        int student=1;
        int pages=mid;
        
        for(int i=0;i<N;)
        {
            if(student > M)
            return false;
            
            if(pages < A[i])
            {
                pages=mid;
                student++;
            }
            else
            {
                pages-=A[i++];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int mx=0,sum=0;
        for(int i=0;i<N;i++)
        {
            mx=max(mx,A[i]);
            sum+=A[i];
        }
        if(N < M) return -1;
        int low=mx, high=sum;
        int ans=-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isPossible(A,N,M,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends