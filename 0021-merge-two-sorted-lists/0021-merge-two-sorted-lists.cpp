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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dummy=new ListNode(-101);
        auto tail=dummy;
        auto ptr=list1;
        auto ptr2=list2;
        while(ptr!=NULL && ptr2!=NULL){
            if(ptr->val<ptr2->val){
                tail->next=ptr;
                tail=ptr;
                ptr=ptr->next;
                
            }
            else{
                tail->next=ptr2;
                tail=ptr2;
                ptr2=ptr2->next;

            }

        }
       
        while(ptr!=NULL)
        {
            tail->next=ptr;
            tail=ptr;
            ptr=ptr->next;



        }

        while(ptr2!=NULL){
             tail->next=ptr2;
                tail=ptr2;
                ptr2=ptr2->next;

        }
         tail->next=NULL;
        return dummy->next;
    }
};