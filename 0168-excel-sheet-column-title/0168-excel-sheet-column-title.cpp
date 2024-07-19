class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s="";
        while(columnNumber>0){
            columnNumber--;
            int rem=(columnNumber%26)+'A';
            s+=(char)rem; 
            columnNumber=columnNumber/26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};