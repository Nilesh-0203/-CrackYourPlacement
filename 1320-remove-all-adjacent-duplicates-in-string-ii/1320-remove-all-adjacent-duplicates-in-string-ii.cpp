class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        st.push({s[0],1});
        for(int i=1;i<s.length();i++){
            if(!st.empty() && st.top().first==s[i]){
                pair<char,int>front=st.top();
                st.pop();
                int cnt=front.second+1;
                if(cnt!=k){
                    st.push({s[i],cnt});
                }
            }
            else{
                st.push({s[i],1});
            }
        }
        string ans="";
        while(!st.empty()){
            int freq=st.top().second;
            char ch=st.top().first;
            ans=string(freq,ch)+ans;
            st.pop();
        }
        return ans;
    }
};