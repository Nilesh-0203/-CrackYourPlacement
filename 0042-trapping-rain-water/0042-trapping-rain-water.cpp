class Solution {
public:
    int n;
    vector<int> left(vector<int>&height){
        vector<int>v(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]);
            v[i]=maxi;
        }
        return v;
    }
    vector<int> right(vector<int>&height){
        vector<int>v(n);
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            v[i]=maxi;
        }
        return v;
    }
    int trap(vector<int>& height) {
        n=height.size();
        vector<int>leftMax=left(height);
        vector<int>rightMax=right(height);

        int water=0;
        for(int i=0;i<n;i++){
            water+=min(leftMax[i],rightMax[i])-height[i];
        }
        return water;
    }
};