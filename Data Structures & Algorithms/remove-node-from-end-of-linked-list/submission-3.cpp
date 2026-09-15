class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = head;
        ListNode* right = head;

        for (int i = 0; i < n; i++)
            right = right->next;

        // right ran off the end => the node to remove is head
        if (right == nullptr)
            return head->next;

        while (right->next != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return head;
    }
};