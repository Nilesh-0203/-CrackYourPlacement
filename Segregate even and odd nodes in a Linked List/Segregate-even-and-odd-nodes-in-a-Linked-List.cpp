Node* divide(int N, Node *head){
        // code here
        Node *h = new Node(-1);
        Node *t = head;
        
        Node *ans = h;
        Node *temp = new Node(-1);
        temp->next = head;
        head = temp;
        Node *prev = head;
        
        while(t != nullptr)
        {
            if(t->data%2 == 0)    
            {
                h->next = t;
                h = t;
                t = t->next;
                
                h->next = nullptr;
                prev->next = t;
            }
            else
            {
                prev->next = t;
                prev = t;
                t = t->next;
            }
        }
        h->next = head->next;
        return ans->next;
    }
