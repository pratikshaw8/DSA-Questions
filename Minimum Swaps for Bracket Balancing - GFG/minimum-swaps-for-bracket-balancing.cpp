// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int bracket=0;
        int cnt=0;
        
        for(int i=0; i<S.length() ; i++)
        {
            bracket += (S[i]=='[') ? -1 : 1;
            
            if(bracket >0 and S[i]==']' )
            cnt+=bracket;
            
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends