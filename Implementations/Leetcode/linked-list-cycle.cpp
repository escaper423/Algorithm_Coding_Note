//problem URL: https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        
        ListNode* t = head;
        ListNode* h= nullptr;
        if (head->next){
            h = head->next;
        }
        
        while(t != nullptr && h != nullptr){
            if (t == h){
                return true;
            }
            t = t->next;
            if (h->next)
                h = h->next->next;
            else
                h = nullptr;
        }
        return false;
    }
};
