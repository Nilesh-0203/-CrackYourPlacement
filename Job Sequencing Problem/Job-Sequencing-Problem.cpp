bool static compare(Job a, Job b){
       return (a.profit > b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n){ 
        
      sort(arr, arr+n, compare);
      int maxDedline=arr[0].dead;
    
        for(int i=1; i<n; i++) maxDedline = max(maxDedline, arr[i].dead);
        vector<int> slot(maxDedline + 1, -1);
        
        int maxProfit=0, totalProfit=0;
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead; j>0; j--){
                if(slot[j]==-1){
                    slot[j]=i;
                    totalProfit++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
     
     return {totalProfit, maxProfit};
    }  
