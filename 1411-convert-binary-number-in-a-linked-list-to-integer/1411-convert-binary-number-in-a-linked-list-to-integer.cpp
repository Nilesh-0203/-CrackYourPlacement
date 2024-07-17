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
        ListNode* next=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        if(head==NULL){
            return 0;
        }
        head=reverse(head);
        int num=0;
        int i=0;
        ListNode* temp=head;
        while(temp){
            num+=(temp->val)*pow(2,i);
            i++;
            temp=temp->next;
        }
        return num;
    }
};