class Solution {
public:
    int m,n;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    void solve(vector<vector<int>>& image, int i, int j,int val, int color){
        if(i<0 || j<0 || i>=m || j>=n || image[i][j]!=val ||  image[i][j]==color){
            return;
        }
        image[i][j]=color;
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            solve(image,new_i,new_j,val,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        int val=image[sr][sc];
        solve(image,sr,sc,val,color);     
        return image; 
    }
};