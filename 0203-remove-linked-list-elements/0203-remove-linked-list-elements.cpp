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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        while(head!=NULL && head->val==val){
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
        if(head==NULL){
            return NULL;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            if(temp->val==val){
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};