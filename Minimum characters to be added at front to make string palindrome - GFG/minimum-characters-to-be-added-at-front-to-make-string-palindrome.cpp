// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        //Write your code here
        int n=str.length();
        int left=0,right=n-1;
        int c=0;
        while(left<right)
        {
            if(str[left]!=str[right])
            {
                if(left==0)
                right--;
                else
                left=0;
                c=0;
            }
            else
            {
                left++;
                right--;
                c+=2;
            }
        }
        if(left==right)
        c++;
        return n-c;
        
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends