// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    static bool mycmp(int a,int b)
    {
        return (a/1000) < (b/1000);
    }
    
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        
        int m=1000;
        
        for(int i=0;i<n;i++)
        {
            price[i] =(price[i]*m) +i+1;
        }
        
        sort(price,price+n,mycmp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=price[i]/m;
            int maxStock=price[i]%m;
            
            if(x*maxStock >=k)
            {
                int bought=k/x;
                ans+= bought;
                k-= x*bought;
                continue;
                
            }
            ans+=maxStock;
            k-= x*maxStock;
            
        }
        return ans;
    }
};












// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends