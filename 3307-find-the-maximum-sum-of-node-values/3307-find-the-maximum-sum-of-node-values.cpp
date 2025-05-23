class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum=0;
        int count=0;
        int minimumNuksan=INT_MAX;
        for(ll num : nums){
            if(num < (num^k)){
                count++;
                sum+=(num^k);
            }
            else{
                sum+=num;
            }
            minimumNuksan=min((long long)minimumNuksan,abs(num-(num^k)));
        }
        if(count%2==0){
            return sum;
        }
        return sum-minimumNuksan;
    }
};