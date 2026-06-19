class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prev=0;
        int maxi=0;
        for(int i=0;i<gain.size();i++){
            prev+=gain[i];
            maxi=max(maxi,prev);
        }
        return maxi;
    }
};