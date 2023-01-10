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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
                
        if (!list1) {
            return list2;
        } 
        else if (!list2) {
            return list1;
        } else {
            if (list1->val < list2->val) {
                list1->next = mergeTwoLists(list1->next, list2);
                
                return list1;
            } else {
                list2->next = mergeTwoLists(list2->next, list1);

                return list2;
            }
        }
    }
};
