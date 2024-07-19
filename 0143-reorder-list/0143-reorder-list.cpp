//Upvote and Comment
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

    ListNode* mid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return ;
        }
        ListNode* middle=mid(head);
        ListNode* rev=reverse(middle);
        
        ListNode* curr=head;

        while(rev->next!=NULL){
            ListNode* tempCurr=curr->next;
            curr->next=rev;

            ListNode* temprev=rev->next;
            rev->next=tempCurr;

            curr=tempCurr;
            rev=temprev;
        }
    }
};