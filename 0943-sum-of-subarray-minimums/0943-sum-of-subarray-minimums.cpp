class Solution {
public:
    vector<int> getNSER(vector<int>&arr,int n){
        vector<int>result(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;
            }
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                result[i]=st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<int> getNSEL(vector<int>&arr,int n){
        vector<int>result(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            if(st.empty()){
                result[i]=-1;
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i]){   // here we write = because of duplicates
                    st.pop();
                }
                result[i]=st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>NSEL=getNSEL(arr,n);
        vector<int>NSER=getNSER(arr,n);
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            long long ls=i-NSEL[i];
            long long rs=NSER[i]-i;
            long long totalWays=ls*rs;
            long long totalSum=arr[i]*totalWays;
            sum=(sum+totalSum)%mod;
        }
        return sum;
    }
};