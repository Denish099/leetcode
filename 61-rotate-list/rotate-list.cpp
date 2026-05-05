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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> ref;

        ListNode* temp = head;

        while (temp) {
            ref.push_back(temp->val);
            temp = temp->next;
        }

        int n = ref.size();
        if (n == 0)
            return head;

        k = k % n;

        reverse(ref.begin(), ref.end());
        reverse(ref.begin(), ref.begin() + k);
        reverse(ref.begin() + k, ref.end());

        temp = head;
        int i = 0;
        while (temp) {
            temp->val = ref[i++];
            temp = temp->next;
        }

        return head;
    }
};