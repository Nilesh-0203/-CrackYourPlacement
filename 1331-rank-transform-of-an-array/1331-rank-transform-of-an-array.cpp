class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        map<int,int>mp;
        int k=1;
        for(int i=0;i<temp.size();i++){
            if(mp[temp[i]]>0){
                continue;
            }
            else{
                mp[temp[i]]=k;
                k++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};