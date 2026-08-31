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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next->next==NULL){
            return {-1,-1};
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* temp=curr->next;
        vector<int>v;
        int i=2;
        while(temp!=NULL){
            if((curr->val>prev->val && curr->val>temp->val) || (curr->val<prev->val && curr->val<temp->val)){
                v.push_back(i);
            }
            prev=curr;
            curr=temp;
            temp=temp->next;
            i++;
        }
        int n=v.size();
        if(n<2){
            return {-1,-1};
        }
        int maxi=v[n-1]-v[0];
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            mini=min(mini,v[i]-v[i-1]);
        }
        return {mini,maxi};
    }
};