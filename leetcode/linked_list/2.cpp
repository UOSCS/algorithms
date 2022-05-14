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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode();
        ListNode* prev = head;
        int carry = 0;

        while (l1 || l2 || carry) {
            
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            
            ListNode* node = new ListNode(sum % 10);
            prev->next = node;
            prev = node;
            carry = sum / 10;
            
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        
        return head->next;
    }
};
