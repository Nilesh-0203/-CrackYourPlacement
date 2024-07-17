class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxi=INT_MIN;
        while(i<j){
            int len=j-i;
            int wid=min(height[i],height[j]);
            maxi=max(maxi,len*wid);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};