class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n){
            return "";
        }
        int requiredCount=t.length();
        unordered_map<char,int>mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int i=0,j=0;
        int start_i=0;
        int minLen=INT_MAX;
        while(j<n){
            char ch=s[j];
            if(mp[ch]>0){
                requiredCount--;
            }
            mp[ch]--;
            while(requiredCount==0){
                int currLen=j-i+1;
                if(minLen>currLen){
                    minLen=currLen;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        return minLen==INT_MAX ? "" : s.substr(start_i,minLen);
    }
};