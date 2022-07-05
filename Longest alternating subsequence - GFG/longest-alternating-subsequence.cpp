// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int diff=0,pdiff=0;
		    int ans=0;
		    int i=0;
		    while(i<nums.size()-1)
		    {
		        diff=nums[i+1]-nums[i];
		        if((diff>0 and pdiff<=0) or(diff<0 and pdiff>=0))
		        {
		            ans++;
		            pdiff=diff;
		        }
		        i++;

		    }
		    return ans+1;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends