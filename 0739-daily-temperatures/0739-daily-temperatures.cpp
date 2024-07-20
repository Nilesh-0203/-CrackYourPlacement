class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(temperatures[i]<temperatures[st.top()]){
                    ans[i]=st.top()-i;
                    break;
                }
                else{
                    st.pop();
                }
            }
            st.push(i);
        }
        return ans;
    }
};