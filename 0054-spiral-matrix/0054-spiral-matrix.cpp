class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int cnt=0;

        int rowStartIndex=0;
        int rowEndIndex=row-1;
        int colStartIndex=0;
        int colEndIndex=col-1;

        while(cnt<total){
            for(int i=colStartIndex;cnt<total && i<=colEndIndex;i++){
                ans.push_back(matrix[rowStartIndex][i]);
                cnt++;
            }
            rowStartIndex++;
            for(int i=rowStartIndex;cnt<total && i<=rowEndIndex;i++){
                ans.push_back(matrix[i][colEndIndex]);
                cnt++;
            }
            colEndIndex--;
            for(int i=colEndIndex;cnt<total && i>=colStartIndex;i--){
                ans.push_back(matrix[rowEndIndex][i]);
                cnt++;
            }
            rowEndIndex--;
            for(int i=rowEndIndex;cnt<total && i>=rowStartIndex;i--){
                ans.push_back(matrix[i][colStartIndex]);
                cnt++;
            }
            colStartIndex++;
        }
        return ans;
    }
};