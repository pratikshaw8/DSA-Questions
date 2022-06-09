// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    	void solve(string s, vector<string>& ans,int index)
    	{
    	    if(index>=s.length())
    	    {
    	        if(find(ans.begin(),ans.end(),s) ==ans.end())
    	        ans.push_back(s);
    	        return;
    	    }
    	    
    	    for(int i=index;i<s.length();i++)
    	    {
    	        swap(s[i],s[index]);
    	        solve(s,ans,index+1);
    	        
    	        //backtrack
    	        swap(s[i],s[index]);
    	    }
    	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(),S.end());
		    vector<string> ans;
		    
		    
		    solve(S,ans,0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends