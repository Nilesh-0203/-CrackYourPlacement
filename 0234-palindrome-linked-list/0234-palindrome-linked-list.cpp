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

    ListNode* mid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* middle=mid(head);
        middle->next=reverse(middle->next);

        ListNode* head1=head;
        ListNode* head2=middle->next;
        while(head2!=NULL){
            if(head1->val !=head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        middle=reverse(middle);
        return true;
    }
};