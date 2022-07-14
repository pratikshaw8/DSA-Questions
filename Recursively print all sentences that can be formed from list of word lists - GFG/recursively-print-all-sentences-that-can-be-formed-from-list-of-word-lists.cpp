// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    void solve(vector<vector<string>>&list ,vector<vector<string>>& ans ,
                int st,int n, vector<string> s)
    {
        if(st >=n)
        {
            ans.push_back(s);
            return;
        }
        vector<string> str=list[st];
        for(int i=0;i<str.size() ;i++)
        {
            s.push_back(str[i]);
            
            solve(list,ans,st+1,n,s);
            s.pop_back();
        }
    }
    vector<vector<string>> sentences(vector<vector<string>>&list){
        //Write your code here
        vector<vector<string>> ans;
        vector<string> s;
        int n=list.size();
        solve(list,ans,0,n,s);
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}
  // } Driver Code Ends