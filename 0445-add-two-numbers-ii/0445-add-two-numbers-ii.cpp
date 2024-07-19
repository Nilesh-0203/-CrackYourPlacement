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

    void insertatTail(ListNode* &head,ListNode* &tail,int val){
        ListNode* newNode=new ListNode(val);

        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    ListNode* add(ListNode* l1, ListNode* l2){
            int carry=0;
            ListNode* resulthead=NULL;
            ListNode* resultTail=NULL;
            while(l1!=NULL || l2!=NULL || carry!=0){
                int val1=0;
                if(l1!=NULL){
                    val1=l1->val;
                }
                
                int val2=0;
                if(l2!=NULL){
                    val2=l2->val;
                }

                int sum=val1+val2+carry;
                int digit=sum%10;
                carry=sum/10;
    
                insertatTail(resulthead,resultTail,digit);

                if(l1!=NULL){
                    l1=l1->next;
                }

                if(l2!=NULL){
                    l2=l2->next;
                }
            }
            return resulthead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);

        ListNode* ans=add(l1,l2);
        ans=reverse(ans);
        return ans;
    }
};