int findPair(int n, int x, vector<int> &arr) {
        // code here
        int i=0,j=1;
        sort(arr.begin(),arr.end());
        while(j<n){
            int m=abs(arr[j]-arr[i]);
            if(m==x && i!=j){
                return 1;
            }
            else if(m<x){
                j++;
            }
            else{
                i++;
            }
            
            if(i==j){
                j++;
            }
        }
        return -1;
    }
