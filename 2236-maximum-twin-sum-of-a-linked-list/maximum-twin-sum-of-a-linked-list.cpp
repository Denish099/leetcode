class Solution {
public:
    int pairSum(ListNode* head) {

        int sum = 0;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow;
        ListNode* p = nullptr;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = p;
            p = curr;
            curr = nxt;
        }

        ListNode* second = p;

        while (second) {
            sum = max(sum, head->val + second->val);
            head = head->next;
            second = second->next;
        }

        return sum;
    }
};