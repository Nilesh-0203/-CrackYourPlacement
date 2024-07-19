class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.length();
        int blen=b.length();
        int i=alen-1,j=blen-1;
        string ans="";
        int carry=0;
        while(i>=0 || j>=0 || carry!=0){
            int x=0;
            if(i>=0 && a[i]=='1'){
                x=1;
            }
            int y=0;
            if(j>=0 && b[j]=='1'){
                y=1;
            }
            int sum=x+y+carry;
            int digit=sum%2;
            carry=sum/2;
            ans+=to_string(digit);
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};