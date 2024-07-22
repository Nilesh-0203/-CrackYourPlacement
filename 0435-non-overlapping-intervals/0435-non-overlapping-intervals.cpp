class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int i=0,j=1;
        int count=0;
        while(j<n){
            if(intervals[i][1]<=intervals[j][0]){
                i=j;
                j++;
            }
            else if(intervals[i][1]>intervals[j][1]){
                i=j;
                j++;
                count++;
            }
            else{
                j++;
                count++;
            }
        }
        return count;
    }
};