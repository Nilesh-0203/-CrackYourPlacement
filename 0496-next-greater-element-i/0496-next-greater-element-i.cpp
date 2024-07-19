class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        map<int,int>mp;
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty()){
                if(nums2[i] < st.top()){
                    mp[nums2[i]] = st.top();
                    break;
                }
                else st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]==0){
                mp[nums1[i]]=-1;
            }
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};