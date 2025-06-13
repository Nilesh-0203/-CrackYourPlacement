class Solution {
public:
    bool solve(vector<int>&nums,int mid,int p){
        int count=0;
        for(int i=0;i<nums.size()-1 && count<p;){
            if(nums[i+1]-nums[i] <=mid){
                count++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        int start=0,end=nums.back()-nums.front();
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(solve(nums,mid,p)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};