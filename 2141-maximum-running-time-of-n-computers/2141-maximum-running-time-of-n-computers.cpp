class Solution {
public:
    bool ispossible(int n,vector<int>batteries,long long mid){
       long long time=0;
       for(int t : batteries) {
            time =time + min((long long)t,mid);
       }
       return mid*n<=time;
    }
  
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        for(int i=0;i<batteries.size();i++){
            sum+=batteries[i];
        }

        long long start=0,end=sum;
        long long ans=0;
        while(start<=end){
            long long mid=start+(end-start)/2;

            if(ispossible(n,batteries,mid)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};