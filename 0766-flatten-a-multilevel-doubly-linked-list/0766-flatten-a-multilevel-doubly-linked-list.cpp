/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten_rec(Node* head){
        Node* curr=head;
        Node* tail=head;
        while(curr!=NULL){
            Node* child=curr->child;
            Node* next=curr->next;
            if(child!=NULL){
                Node* _tail=flatten_rec(child);
                _tail->next=next;
                if(next!=NULL){
                    next->prev=_tail;
                }
                curr->next=child;
                child->prev=curr;
                curr->child=NULL;
                curr=tail;
            }
            else{
                curr=next;
            }
            if(curr){
                tail=curr;
            }
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if(head){
            flatten_rec(head);
        }
        return head;
    }
};