class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y)
    {
        char temp = board[x][y];
        board[x][y] = '.';
        for(int i=0;i<9;i++)
        {
            if(board[x][i] == temp) return false;
            if(board[i][y] == temp) return false;
            if(board[3*(x/3) + i/3][3*(y/3) + i%3] == temp) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j;
        
        for(i=0;i<9 ;i++)
        {
            for( j =0; j<9 ;j++ )
            {
                if(board[i][j] != '.' and !isValid(board,i,j))
                    return false;
            }
        }
        return true;
    }
};