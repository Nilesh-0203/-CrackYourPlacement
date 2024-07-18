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
    int getlen(ListNode* head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int count=0;
        if(getlen(head)>=k){
            ListNode* curr=head;
            ListNode* next=NULL;
            ListNode* prev=NULL;
            while(curr!=NULL && count<k){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                count++;
            }
            if(next!=NULL){
                head->next=reverseKGroup(next,k);
            }
            return prev;
        }
        else{
            return head;
        }
        return NULL;
    }
};