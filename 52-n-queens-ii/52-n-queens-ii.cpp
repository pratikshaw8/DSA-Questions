class Solution {
public:
    bool isSafe(vector<string>& board,int row,int col,int n)
    {
        int x=row,y=col;
        
        for(int i=0;i<col;i++)
        {
            if(board[x][i] == 'Q')
                return false;         
        }
        
        x=row; y=col;
        
        while(x>=0 and y>=0)
        {
            if(board[x][y] =='Q')
                return false; 
            x--;
            y--;
        }
        
        x=row;y=col;
        
        while(x<n and y>=0)
        {
            if(board[x][y] == 'Q')
                return false; 
            x++;
            y--;
        }
        return true;
        
    }
    
    void solve(vector<vector<string>>& ans,int n,vector<string>& board,int col,int& c)
    {
        
        if(n==col)
        {
            ans.push_back(board);
            c++;
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(board,row,col,n)){
                
                board[row][col]='Q';
                solve(ans,n,board,col+1,c);
                
                //backtrack;
                board[row][col]='.';
            }
                
        }
    }
    
    
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        int c=0;
        solve(ans,n,board,0,c);
        return c;
    }
};