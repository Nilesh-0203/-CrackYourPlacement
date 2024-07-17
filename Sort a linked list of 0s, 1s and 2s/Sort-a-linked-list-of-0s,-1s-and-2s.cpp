void insertAtTail(Node* &head,Node* &tail,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* segregate(Node *head) {
        
        // Add code here
        
        Node* zeroHead=new Node(-1);
        Node* zeroTail=zeroHead;
        
        Node* oneHead=new Node(-1);
        Node* oneTail=oneHead;
        
        Node* twoHead=new Node(-1);
        Node* twoTail=twoHead;
        
        Node* temp=head;
        while(temp){
            if(temp->data==0){
                insertAtTail(zeroHead,zeroTail,temp->data);
            }
            else if(temp->data==1){
                insertAtTail(oneHead,oneTail,temp->data);
            }
            else if(temp->data==2){
                insertAtTail(twoHead,twoTail,temp->data);
            }
            temp=temp->next;
        }
        if(oneHead->next!=NULL){
            zeroTail->next=oneHead->next;
        }
        else{
            zeroTail->next=twoHead->next;
        }
        oneTail->next=twoHead->next;
        twoTail->next=NULL;
        
        head=zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
    
        return head;
    }
