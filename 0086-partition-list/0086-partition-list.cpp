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
    ListNode* partition(ListNode* head, int x) {
        auto dummy1=new ListNode(-1);
        auto tail1=dummy1;
        
        auto dummy2=new ListNode(-1);
        auto tail2=dummy2;

        auto ptr=head;
        while(ptr!=nullptr){
            if(ptr->val<x){
                tail1->next=ptr;
                tail1=ptr;

            }

            else{
                tail2->next=ptr;
                tail2=ptr;
            }
            ptr=ptr->next;
        }
        tail1->next=NULL;
        tail2->next=NULL;
        tail1->next=dummy2->next;

        return dummy1->next;
        }
    
};