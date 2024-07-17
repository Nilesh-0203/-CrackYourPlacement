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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        if(l1->val<=l2->val){
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partation(vector<ListNode*>&lists,int i,int j){
        if(i==j){
            return lists[i];
        }
        if(i>j){
            return NULL;
        }
        int mid=i+(j-i)/2;
        ListNode* l1=partation(lists,i,mid);
        ListNode* l2=partation(lists,mid+1,j);

        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i=0,j=lists.size();
        if(j==0){
            return NULL;
        }
        return partation(lists,i,j-1);
    }
};