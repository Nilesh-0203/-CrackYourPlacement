class Solution {
public:
    int n,q;
    bool check(vector<int>&nums,vector<vector<int>>& queries,int k){
        vector<int>diff(n,0);
        for(int i=0;i<=k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            diff[l]+=1;
            if(r+1<n){
                diff[r+1]-=1;
            }
        }
        int cummSum=0;
        for(int i=0;i<n;i++){
            cummSum+=diff[i];
            diff[i]=cummSum;

            if(nums[i]-diff[i] > 0){
                return false;
            }
        }
        return true;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size();
        q=queries.size();
        auto lambda = [] (int x) {
            return x==0;
        };
        if(all_of(nums.begin(),nums.end(),lambda)){
            return true;
        }
        int l=0,r=q-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(nums,queries,mid)){
                return true;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
};