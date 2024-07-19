/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insertAtEnd(ListNode* &tail,int data){
        ListNode* newNode=new ListNode(data);
        tail->next=newNode;
        tail=newNode;
    }
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return NULL;
        }
        ListNode* smallHead=new ListNode(-1);
        ListNode* smallTail=smallHead;
        ListNode* largeHead=new ListNode(-1);
        ListNode* largeTail=largeHead;

        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                insertAtEnd(smallTail,temp->val);
            }
            else{
                insertAtEnd(largeTail,temp->val);
            }
            temp=temp->next;
        }
        smallTail->next=largeHead->next;
        return smallHead->next;
    }
};