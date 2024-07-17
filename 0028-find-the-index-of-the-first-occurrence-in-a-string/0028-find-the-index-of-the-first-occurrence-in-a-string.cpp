class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++){
            if(needle[0]==haystack[i]){
                int j=0;int k=i;
                while(j<needle.size()){
                    if(needle[j]==haystack[k]){
                        j++;
                        k++;
                    }
                    else{
                        break;
                    }
                }
                if(j==needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};