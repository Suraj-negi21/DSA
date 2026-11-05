class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = nullptr;
        }
    };

    ListNode* head;
    int s;

    MyLinkedList() {
        head = nullptr;
        s = 0;
    }

    int get(int index) {
        if(index < 0 || index >= s)
            return -1;

        ListNode* cur = head;

        for(int i = 0; i < index; i++)
            cur = cur->next;

        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);

        node->next = head;
        head = node;
        s++;
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);

        if(head == nullptr)
            head = node;
        else {
            ListNode* cur = head;

            while(cur->next)
                cur = cur->next;

            cur->next = node;
        }

        s++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > s)
            return;

        if(index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* cur = head;

        for(int i = 0; i < index - 1; i++)
            cur = cur->next;

        ListNode* node = new ListNode(val);

        node->next = cur->next;
        cur->next = node;
        s++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= s)
            return;

        if(index == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            s--;
            return;
        }

        ListNode* cur = head;

        for(int i = 0; i < index - 1; i++)
            cur = cur->next;

        ListNode* temp = cur->next;

        cur->next = temp->next;

        delete temp;
        s--;
    }
};