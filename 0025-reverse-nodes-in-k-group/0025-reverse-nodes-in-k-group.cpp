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
        ListNode* reverselist(ListNode* head){
       ListNode* cur=head;
       
       ListNode* prev=NULL;
       while(cur!=NULL){
           ListNode* next=cur->next;
           cur->next=prev;
           prev=cur;
           cur=next;

       }
       return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;

        ListNode* ptr=head;
        while(ptr!=NULL){
            ListNode* end=ptr;
            for(int i=1;i<=k-1;i++){
                end=end->next;
                if(end==NULL){
                    tail->next=ptr;
                    return dummy->next;
                }
            }

            ListNode* nextstart=end->next;
            end->next=NULL;
            ListNode* newhead = reverselist(ptr);
            tail->next = newhead;
            tail=ptr;
            ptr=nextstart;
            
        }return dummy->next;
    }
};