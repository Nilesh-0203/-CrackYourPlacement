class Solution {
public:
    typedef pair<int,pair<int,int>> PP;
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        int water=0;
        priority_queue<PP,vector<PP>,greater<PP>>boundaryCells;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int row=0;row<m;row++){
            for(int col:{0,n-1}){
                boundaryCells.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }

        for(int col=0;col<n;col++){
            for(int row:{0,m-1}){
                boundaryCells.push({heightMap[row][col],{row,col}});
                visited[row][col]=true;
            }
        }

        while(!boundaryCells.empty()){
            PP p=boundaryCells.top();
            boundaryCells.pop();

            int height=p.first;
            int i=p.second.first;
            int j=p.second.second;

            for(vector<int>&dir:directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];

                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && !visited[new_i][new_j]){
                    water+=max(height-heightMap[new_i][new_j],0);
                    boundaryCells.push({max(height,heightMap[new_i][new_j]),{new_i,new_j}});
                    visited[new_i][new_j]=true;
                }
            }
        }
        return water;
    }
};