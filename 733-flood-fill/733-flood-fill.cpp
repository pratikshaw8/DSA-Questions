class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int startColour)
    {
        if(sr <0 or sc<0 or sr>=image.size() or sc>=image[0].size() 
           or image[sr][sc]==color or image[sr][sc]!=startColour)
            return;
        
        image[sr][sc]=color;
        
        dfs(image,sr+1,sc,color,startColour);
        dfs(image,sr-1,sc,color,startColour);
        dfs(image,sr,sc+1,color,startColour);
        dfs(image,sr,sc-1,color,startColour);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
        
    }
};