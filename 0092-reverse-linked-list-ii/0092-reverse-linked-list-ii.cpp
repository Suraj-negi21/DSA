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

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == nullptr || left == right)
            return head;

        ListNode* listprev = nullptr;
        ListNode* lefti = head;

        int idx = 1;

        while(idx < left)
        {
            listprev = lefti;
            lefti = lefti->next;
            idx++;
        }

        ListNode* cur = lefti;
        ListNode* prev = nullptr;

        while(idx <= right)
        {
            ListNode* next = cur->next;

            cur->next = prev;

            prev = cur;
            cur = next;

            idx++;
        }

        if(listprev != nullptr)
            listprev->next = prev;
        else
            head = prev;

        lefti->next = cur;

        return head;
    }
};