class Solution {
public:
    int totalMoney(int n) {
        int sum=0,count=1;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=i+6;j++){
                sum=sum+j;
                if(count==n){
                    return sum;
                }
                count++;
            }
        }
        return sum;
    }
};