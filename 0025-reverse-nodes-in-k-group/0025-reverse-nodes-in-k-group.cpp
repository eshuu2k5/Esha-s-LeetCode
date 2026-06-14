class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (true) {
            ListNode* node = prev;

            for (int i = 0; i < k && node; i++) {
                node = node->next;
            }

            if (!node) break;

            ListNode* curr = prev->next;
            ListNode* nxt = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }

            prev = curr;
        }

        return dummy.next;
    }
};