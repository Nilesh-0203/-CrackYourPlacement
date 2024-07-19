vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
        vector<long long int>output(n);
        long long int prod=1;
        for(int i=0;i<n;i++){
            output[i]=prod;
            prod*=nums[i];
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            output[i]*=prod;
            prod*=nums[i];
        }
        return output;
    }
