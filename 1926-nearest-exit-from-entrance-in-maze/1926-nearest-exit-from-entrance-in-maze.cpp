class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        
        queue<pair<int,int>> q;
        
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int move=0;
        
        while(!q.empty())
        {
            move++;
            int size=q.size();
            for(int k=0;k<size;k++)
            {
                pair<int,int> front=q.front();
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int newx=front.first + dir[i].first;
                    int newy=front.second + dir[i].second;

                    if( (newx<0 or newx>=m or newy<0 or newy>=n) or maze[newx][newy]=='+')
                        continue;

                    if(newx==0 or newx==m-1 or newy==0 or newy==n-1)
                        return move;

                    maze[newx][newy]='+';
                    q.push({newx,newy});

                }
            }
            
        }
        return -1;
                
        
    }
};