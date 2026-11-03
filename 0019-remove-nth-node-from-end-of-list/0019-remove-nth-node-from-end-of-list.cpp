class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        auto slow = dummy;
        auto fast = dummy;

        for(int i = 1; i <= n; i++) {
            fast = fast->next;
        }

        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummy->next;
    }
};