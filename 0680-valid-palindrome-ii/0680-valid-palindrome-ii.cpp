class Solution {
public:
    bool validPalindrome(string s) {
        int cnt=1;
        int i=0,j=s.length()-1;
        int match1=true,match2=true;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else if(cnt>0){
                i++;
                cnt--;
            }
            else{
                match1=false;
                break;
            }
        }
        i=0,j=s.length()-1;
        cnt=1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else if(cnt>0){
                j--;
                cnt--;
            }
            else{
                match2=false;
                break;
            }
        }
        return (match1 || match2);
    }
};