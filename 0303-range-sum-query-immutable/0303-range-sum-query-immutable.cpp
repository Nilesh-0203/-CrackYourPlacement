class NumArray {
public:
    vector<int>nums;
    NumArray(vector<int>& nums) {
        this->nums=nums;
    }
    
    int sumRange(int left, int right) {
        long long x=0;
        for(int i=left;i<=right;i++){
            x+=nums[i];
        }
        return x;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */