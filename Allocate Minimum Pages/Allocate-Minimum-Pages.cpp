bool isPossible(int nums[],int n,int k,long long mid){
        int studentCount=1;
        int pageSum=0;
        for(int i=0;i<n;i++){
            if(pageSum+nums[i]<=mid){
                pageSum+=nums[i];
            }
            else{
                studentCount++;
                if(studentCount>k || nums[i]>mid){
                    return false;
                }
                pageSum=nums[i];
            }
        }
        return true;
    }
    long long findPages(int n, int nums[], int k) {
        // code here
        if(n<k){
            return -1;
        }
        long long sum=accumulate(nums,nums+n,0);
        long long start=0;
        long long end=sum;
        long long ans=-1;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(isPossible(nums,n,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
