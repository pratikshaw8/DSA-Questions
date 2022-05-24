class Solution {
public:
    
    bool isSafe(vector<vector<char>>& board, char val, int x, int y)
    {
        for(int i=0;i<9;i++)
        {
            
            if(board[i][y] == val) return false;
            if(board[x][i] == val) return false;
            if(board[3*(x/3) +i/3][3*(y/3) +i%3] == val) return false;
        }
        
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board)
    {
        int i,j;
        
        for(int i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1';k<='9';k++)
                    {
                        if(isSafe(board,k,i,j))
                        {
                            board[i][j]=k;
                            bool possibleSolution= solve(board);
                            if(possibleSolution)
                                return true;
                            else
                                board[i][j]='.';
                                
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }
};