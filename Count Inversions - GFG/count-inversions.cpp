// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    
    long long merge(long long arr[],int l, int mid, int r)
    {
        int n1=mid-l+1;
        int n2=r-mid;
        long long count=0;
        vector<long long> left(n1);
        vector<long long> right(n2);
        
        
        for(int i=0;i<n1;i++)
        left[i]=arr[l+i];
        
        for(int i=0;i<n2;i++)
        right[i]=arr[mid+i+1];
        
        int i=0,j=0,k=l;
        
        while(i<n1 and j<n2)
        {
            if(left[i] <= right[j])
            {
                arr[k]=left[i];
                i++;
            }
            else
            {
                count+= left.size() -i;
                arr[k]=right[j];
                j++;
            }
            k++;
        }
        while(i < n1){
           arr[k] = left[i];
           i++;
           k++;
        }
        while(j < n2){
           arr[k] = right[j];
           j++;
           k++;
        }
        return count;
        
    }
    long long mergeSort(long long arr[],int l,int r)
    {
        long long count=0;
        if(l<r)
        {
            int mid= l+ (r-l)/2;
            count+=mergeSort(arr,l,mid);
            count+=mergeSort(arr,mid+1,r);
            count+=merge(arr,l,mid,r);
        }
        return count;
    }
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long res=mergeSort(arr,0,N-1);
        return res;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends