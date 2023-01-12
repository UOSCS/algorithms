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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        vector<ListNode*> v;
        ListNode* answer, *p = head;

        while (p) {
            v.push_back(p);
            p = p->next;
        }

        ListNode* node = v[v.size() - n];

        if (v.size() == n) {
            answer = node->next;
        } else {
            ListNode* prev_node = v[v.size() - n - 1];
            prev_node->next = node->next;
            answer = head;
        }

        return answer;
    }
};
