class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>v;
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            mini=min(mini,arr[i+1]-arr[i]);
        }
        for(int i=0;i<arr.size()-1;i++){
            if(mini==(arr[i+1]-arr[i])){
                v.push_back({arr[i],arr[i+1]});
            }
        }
        return v;
    }
};