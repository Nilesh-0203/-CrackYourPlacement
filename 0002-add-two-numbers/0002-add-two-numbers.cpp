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
    void insertatEnd(ListNode* &ansHead,ListNode* &ansTail,int data){
        ListNode* newNode=new ListNode(data);
        if(ansHead==NULL){
            ansHead=newNode;
            ansTail=newNode;
            return;
        }
        ansTail->next=newNode;
        ansTail=newNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ansHead=NULL;
        ListNode* ansTail=NULL;

        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL || carry!=0){
            int val1=0;
            if(temp1){
                val1=temp1->val;
            }
            int val2=0;
            if(temp2){
                val2=temp2->val;
            }
            int sum=val1+val2+carry;
            int digit=sum%10;
            carry=sum/10;
            insertatEnd(ansHead,ansTail,digit);
            if(temp1){
                temp1=temp1->next;
            }
            if(temp2){
                temp2=temp2->next;
            }
        }
        return ansHead;
    }
};