class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If one of the lists is empty, return the other
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        // Create a dummy node to simplify merging
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Pointers for both lists
        ListNode* a = list1;
        ListNode* b = list2;

        // Merge lists while both are not empty
        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                current->next = a;
                a = a->next;
            } else {
                current->next = b;
                b = b->next;
            }
            current = current->next;
        }

        // Attach the remaining part of the non-empty list
        if (a != nullptr) {
            current->next = a;
        } else {
            current->next = b;
        }

        // Return merged list, skipping the dummy node
        return dummy->next;
    }
};
