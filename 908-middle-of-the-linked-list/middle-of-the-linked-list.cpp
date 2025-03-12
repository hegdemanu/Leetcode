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
    ListNode* middleNode(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) return head;
        int cnt = 1;
        ListNode* temp = head;
     while(temp){
        temp = temp->next;
        cnt++;
     }   
     temp = head;
     int cnt2 = 1;
     while(temp){
        temp = temp->next;
        cnt2 ++;
        if(cnt2 == ((cnt+1)/2)) break;
        
     } 
     return temp;
    }
};