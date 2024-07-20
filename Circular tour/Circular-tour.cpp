int tour(petrolPump petrol[],int n)
    {
       //Your code here
       int s=0;
       int balance=0, extra=0;
       for(int i=0;i<n;i++){
           balance+=(petrol[i].petrol-petrol[i].distance);
           if(balance<0){
               s=i+1;
               extra+=balance;
               balance=0;
           }
       }
       return (balance+extra>=0)? s:-1;
    }
