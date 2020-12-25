class Solution {
public:
    
    void flood(int sr, int sc, int pCol, int nCol, int r, int c,
               vector<vector<int>>& vis, vector<vector<int>>& image) //pass by reference
    {
        if(sr < 0 || sr >= r || sc < 0 || sc >= c)
            return;
        
        else if(image[sr][sc] != pCol) //this cell cannot be flooded as the color is diff
            return;
        
        else if(vis[sr][sc] == 1) //if already visited
            return;
        
        else
        {
            vis[sr][sc] = 1; //mark visited
            image[sr][sc] = nCol;
            
            //Add children
            flood(sr+1, sc, pCol, nCol, r, c, vis, image); //Down call
            flood(sr-1, sc, pCol, nCol, r, c, vis, image); //Up call
            flood(sr, sc+1, pCol, nCol, r, c, vis, image); //Right call
            flood(sr, sc-1, pCol, nCol, r, c, vis, image); //Left call
            
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        //DFS - color the starting pixel and check 4 neighburing pixels for validity 
        
        int row = image.size();
        int col = image[0].size();
        
        int prevColor = image[sr][sc]; //color of current cell - fill this color everywhere
        
        vector<vector<int>> vis(row); //visited matrix
        
        for(int i=0; i<row; i++)
            vis[i] = vector<int>(col, 0);
        
        
        flood(sr, sc, prevColor, newColor, row, col, vis, image);
        
        return image;
    }
};