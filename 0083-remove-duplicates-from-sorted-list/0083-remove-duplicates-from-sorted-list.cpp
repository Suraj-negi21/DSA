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
    ListNode* deleteDuplicates(ListNode* head) {
      auto dummy=new ListNode(-101);
      auto tail=dummy;
      auto ptr=head;
      while(ptr!=NULL){
        if(tail->val!=ptr->val){
            tail->next=ptr;
            tail=ptr;
            ptr=ptr->next;
        }
        else{
            auto temp=ptr->next;
            delete ptr;
            ptr=temp;
        }
      }tail->next=NULL;
      return dummy->next;

    
    }
};