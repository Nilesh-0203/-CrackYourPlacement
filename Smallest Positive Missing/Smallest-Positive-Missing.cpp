int missingNumber(int arr[], int n) 
    { 
        // Your code here
        sort(arr,arr+n);
        int k=1;
        for(int i=0;i<n;i++){
            if(arr[i]==k){
                k++;
            }
        }
        return k;
    } 
