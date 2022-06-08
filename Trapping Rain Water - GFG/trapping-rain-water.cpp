// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long rain=0;
        
        int maxi=0;
        vector<int> left(n);
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]);
            left[i]=maxi;
        }
        
        vector<int> right(n);
        maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,arr[i]);
            right[i]=maxi;
        }
        
        for(int i=0;i<n;i++)
        {
            if(right[i] > arr[i])
            {
                int a=min(right[i],left[i]);
            
                rain =rain + (a-arr[i]);
            }
            
            
        }
        return rain;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends