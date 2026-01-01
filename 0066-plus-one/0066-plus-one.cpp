class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>v(n+1);
        int carry=1;
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
                carry=1;
            }
            else{
                digits[i]=digits[i]+carry;
                carry=digits[i]%10;
                return digits;
            }
        }
        if(carry!=0){
            v[0]=1;
            for(int i=1;i<digits.size();i++){
                v[i]=digits[i];
            }
        }
        return v;
    }
};