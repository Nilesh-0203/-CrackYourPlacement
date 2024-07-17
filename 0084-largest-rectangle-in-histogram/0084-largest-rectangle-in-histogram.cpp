class Solution {
public:
    int n;
    vector<int> NSRF(vector<int>&heights){
        stack<int>st;
        st.push(n);
        vector<int>v(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n && heights[st.top()]>=heights[i]){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> NSLF(vector<int>&heights){
        stack<int>st;
        st.push(-1);
        vector<int>v(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        n=heights.size();
        vector<int>NSR=NSRF(heights);
        vector<int>NSL=NSLF(heights);
        vector<int>width(n);
        for(int i=0;i<n;i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            area=max(area,heights[i]*width[i]);
        }
        return area;
    }
};