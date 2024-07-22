class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);
        for(char ch:s){
            v[ch-'a']++;
        }
        int result=0;
        unordered_set<int>st;
        for(int i=0;i<26;i++){
            while(v[i]>0 && st.find(v[i])!=st.end()){
                v[i]=v[i]-1;
                result++;
            }
            st.insert(v[i]);
        }
        return result;
    }
};