class Solution {
public:
    vector<vector<int>>v;
    void twoSum(vector<int>&nums,int target,int i,int j){
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum<target){
                i++;
            }
            else if(sum>target){
                j--;
            }
            else if(sum==target){
                while(i<j && nums[i]==nums[i+1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }
                v.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return {};
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int num1=nums[i];
            int target=-num1;
            twoSum(nums,target,i+1,n-1);
        }
        return v;
    }
};