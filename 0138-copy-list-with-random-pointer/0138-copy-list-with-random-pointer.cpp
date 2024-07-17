/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &cloneHead,Node* &cloneTail,int data){
        Node* newNode=new Node(data);
        if(cloneHead==NULL){
            cloneHead=newNode;
            cloneTail=newNode;
            return;
        }
        cloneTail->next=newNode;
        cloneTail=newNode;
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        Node* originalNode=head;
        Node* cloneNode=cloneHead;

        unordered_map<Node*,Node*>mapi;
        while(originalNode!=NULL){
            mapi[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        originalNode=head;
        cloneNode=cloneHead;

        while(originalNode!=NULL){
            cloneNode->random=mapi[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};