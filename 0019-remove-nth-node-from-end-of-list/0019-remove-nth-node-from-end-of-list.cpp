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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL && n==1) ){
            return NULL;
        }
        head=reverse(head);
        ListNode* temp=head;
        if(n==1){
            head=head->next;
            temp->next=NULL;
            head=reverse(head);
            return head;
        }
        int count=0;
        while(count<n-2){
            temp=temp->next;
            count++;
        }
        ListNode* a=temp->next;
        temp->next=temp->next->next;
        delete a;
        head=reverse(head);
        return head;
    }
};