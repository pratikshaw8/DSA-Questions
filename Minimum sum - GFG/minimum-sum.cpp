// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        string ans;
        sort(arr,arr+n);
        
        string sum1="";
        string sum2="";
        
        for(int i=0;i<n ;i+=2)
        {
            if(arr[i]!=0)
            sum1=sum1+to_string(arr[i]);
            
        }
        for(int i=1;i<n ;i+=2)
        {
            if(arr[i]!=0)
            sum2=sum2+to_string(arr[i]);
            
        }
        
        if(sum1.length() > sum2.length())
        sum2= "0" +sum2;
        else if(sum1.length() < sum2.length())
        sum1= "0" +sum1;
        
        
        
        int carry=0;
        int sum=0;
        int i=sum1.length()-1;
        char ch;;
        while(i>=0)
        {
            int a=sum1[i]-'0';
            int b=sum2[i]-'0' ;   
            sum=a+b+carry;
            carry=sum/10;
            ch=(sum%10)+'0';
            
            ans= ch + ans;
            i--;
        }
        
        if(carry)
        ans="1" +ans;
        
        if(ans[0]=='0')
        ans.erase(ans.begin());
        if(ans[0]=='0')
        ans.erase(ans.begin());
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
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends