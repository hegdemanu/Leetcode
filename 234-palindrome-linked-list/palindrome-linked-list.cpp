class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        stack<int> st1;

        // Push the first half of the list into the stack
        while (fast != nullptr && fast->next != nullptr) {
            st1.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip the middle element for odd-length lists
        if (fast != nullptr) {
            slow = slow->next;
        }

        // Compare the second half with the stack
        while (slow != nullptr) {
            if (st1.top() != slow->val) {
                return false;  // Mismatch found, not a palindrome
            }
            st1.pop();
            slow = slow->next;
        }

        return true;  // All values matched, it's a palindrome
    }
};
