class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>&board){
        return (i>=0 && i<board.size() && j>=0 && j<board[0].size());
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<int>dirx={0,0,1,-1,1,-1,1,-1};
        vector<int>diry={-1,1,0,0,1,-1,-1,1};
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                int cnt=0;
                for(int i=0;i<8;i++){
                    int new_i=row+dirx[i];
                    int new_j=col+diry[i];
                    if(isValid(new_i,new_j,board) && abs(board[new_i][new_j])==1){
                        cnt++;
                    }
                }
                if(board[row][col]==1 && (cnt<2 || cnt>3)){
                    board[row][col]=-1;
                }
                if(board[row][col]==0 && cnt==3){
                    board[row][col]=2;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]>=1){
                    board[i][j]=1;
                }
                else{
                    board[i][j]=0;
                }
            }
        }
    }
};