    int mod=1e9+7;
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long a=0,b=0;
        Node* temp1=first;
        Node* temp2=second;
        while(temp1){
            a=(a*10)%mod+temp1->data;
            temp1=temp1->next;
        }
        while(temp2){
            b=(b*10)%mod+temp2->data;
            temp2=temp2->next;
        }
        long long ans=(a*b)%mod;
        return ans;
    }
