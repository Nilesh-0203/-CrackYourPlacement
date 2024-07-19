#include <bits/stdc++.h>
bool isPossible(vector<int>&stalls,int n,int k,int mid){
        int cowCount=1;
        int lastPos=stalls[0];
        for(int i=0;i<n;i++){
            if(stalls[i]-lastPos>=mid){
                cowCount++;
                if(cowCount==k){
                    return true;
                }
                lastPos=stalls[i];
            }
        }
        return false;
    }
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        if(n<k){
            return -1;
        }
        int start=0;
        int end=*max_element(stalls.begin(),stalls.end());
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(stalls,n,k,mid)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
}
