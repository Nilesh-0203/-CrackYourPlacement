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
    ListNode* find(ListNode* head,int k){
        int cnt=1;
        ListNode* temp=head;
        while(cnt!=k){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int len=1;
        ListNode* temp=head;
        while(temp->next){
            len++;
            temp=temp->next;
        }
        if(k%len==0){
            return head;
        }
        k=k%len;
        temp->next=head;
        ListNode* lastNode=find(head,len-k);
        head=lastNode->next;
        lastNode->next=NULL;
        return head;
    }
};