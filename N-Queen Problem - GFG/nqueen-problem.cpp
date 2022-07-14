// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int row, int col, int n, vector<vector<int>>& board)
    {
        for(int i=0;i<col;i++)
        {
            if(board[row][i] == 1)
            return false;
        }
        int x=row,y=col;
        
        while(x>=0 and y>=0)
        {
            if(board[x][y] ==1)
            return false;
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x<n and y>=0)
        {
            if(board[x][y] == 1)
            return false;
            x++;
            y--;
        }
        return true;
    }
    void solve(vector<vector<int>> &ans, int n, vector<vector<int>> &board,
                int col , vector<int> stor)
    {
        if(stor.size() == n)
        {
            ans.push_back(stor);
            stor.clear();
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n,board))
            {
                stor.push_back(row+1);
                board[row][col]= 1;
                
                solve(ans,n,board,col+1,stor);
                
                board[row][col]=0;
                stor.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> board(n,vector<int>(n,0));
        
        vector<int> stor;
        solve(ans,n,board,0, stor);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends