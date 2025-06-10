class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int maxOdd=0,minEven=INT_MAX;
        for(auto i:mp){
            if(i.second%2==0){
                minEven=min(minEven,i.second);
            }
            else{
                maxOdd=max(maxOdd,i.second);
            }
        }
        return maxOdd-minEven;
    }
};