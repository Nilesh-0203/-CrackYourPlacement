class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;

        vector<int> pre(n);
        pre[0] = arr[0];
        // cout<<pre[0]<<" ";

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] ^ arr[i];
            // cout<<pre[i]<<" ";
        }
        // cout<<endl;

        for(auto& val:queries){
            int l = val[0];
            int r = val[1];

            if(l==0){
                ans.push_back(pre[r]);
                continue;
            }

            int calc = pre[r]^pre[l-1];
            ans.push_back(calc);
        }

        return ans;
    }
};