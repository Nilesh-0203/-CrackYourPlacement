class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        vector<int> res;
        
        for(int i=nums.size()-1;i>=0;i--){
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            res.push_back(index);    
            
            if(index==ans.size()){
                ans.push_back(nums[i]);
            }
            else{
                ans.insert(ans.begin()+index,nums[i]);
            }
            
        }
        reverse(res.begin(),res.end());
        return(res);
    }
};