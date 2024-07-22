class Solution {
public:
    string removeKdigits(string num, int k) {
        string result="";
        for(char ch:num){
            while(result.length()>0 && k>0 && result.back()>ch){
                result.pop_back();
                k--;
            }
            if(result.length()>0 || ch!='0'){
                result.push_back(ch);
            }
        }
        while(result.length()>0 && k>0){
            result.pop_back();
            k--;
        }
        return result=="" ? "0" : result;
    }
};