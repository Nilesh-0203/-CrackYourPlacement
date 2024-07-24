class Solution {
public:
    int n;
    vector<int> NSRF(vector<int>&height){
        stack<int>st;
        st.push(n);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n && height[st.top()]>=height[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> NSLF(vector<int>&height){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && height[st.top()]>=height[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int findMaxArea(vector<int>&height){
        vector<int>NSR=NSRF(height);
        vector<int>NSL=NSLF(height);
        vector<int>width(n);
        for(int i=0;i<n;i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int newArea=height[i]*width[i];
            area=max(area,newArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        n=matrix[0].size();
        vector<int>height(n);
        //Add the first row in the height -1D
        for(int i=0;i<n;i++){
            height[i]=(matrix[0][i]=='1') ? 1 : 0;
        }
        int maxArea=findMaxArea(height);
        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
                if(matrix[row][col]=='0'){
                    height[col]=0;
                }
                else{
                    height[col]+=1;
                }
            }
            maxArea=max(maxArea,findMaxArea(height));
        }
        return maxArea;
    }
};