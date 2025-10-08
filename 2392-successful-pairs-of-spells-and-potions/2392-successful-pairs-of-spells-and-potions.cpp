class Solution {
public:
    int solve(int spell,vector<int>&potions,long long success){
        int left=0,right=potions.size()-1;
        int ans=-1;
        while(left<=right){
            int mid=left+ (right-left)/2;
            if((long long)spell*potions[mid]>=success){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>v;
        int n=potions.size();
        sort(potions.begin(),potions.end());
        for(int spell:spells){
            int cnt=0;
            int index=solve(spell,potions,success);
            if(index!=-1){
                cnt+=(n-index);
            }
            v.push_back(cnt);
        }
        return v;
    }
};