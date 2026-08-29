class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end());

        int groupNum=0;
        unordered_map<int,int>numToGroup;
        numToGroup[v[0]]=groupNum;

        unordered_map<int,list<int>>groupToList;
        groupToList[groupNum].push_back(v[0]);

        for(int i=1;i<n;i++){
            if(abs(v[i]-v[i-1])>limit){
                groupNum+=1;
            }
            numToGroup[v[i]]=groupNum;
            groupToList[groupNum].push_back(v[i]);
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int group=numToGroup[nums[i]];
            ans[i]=groupToList[group].front();
            groupToList[group].pop_front();
        }
        return ans;
    }
};