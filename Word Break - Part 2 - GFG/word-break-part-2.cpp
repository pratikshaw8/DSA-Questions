// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve( int n, unordered_set<string>& st, vector<string> &ans,
                    string s,string temp)
    {
        if(s.size() ==0)
        {
            ans.push_back(temp);
            return;
        }
        string output="";
        for(int i=0;i<s.size() ;i++)
        {
            output+=s[i];
            if(st.find(output) != st.end() )
            {
                if(!temp.size())
                {
                    solve(n,st,ans,s.substr(i+1), output);
                }
                else
                {
                    solve(n,st,ans,s.substr(i+1), temp + " " + output);
                }
            }
        }
        
         
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        unordered_set<string> st;
        for(int i=0;i<dict.size() ;i++)
        {
            st.insert(dict[i]);
        }
        
        vector<string> ans;
        string temp="";
        solve(n,st,ans,s,temp);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends