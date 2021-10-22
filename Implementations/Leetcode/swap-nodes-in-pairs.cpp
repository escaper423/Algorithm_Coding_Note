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
 //problem URL: https://leetcode.com/problems/swap-nodes-in-pairs/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode* n1 = head;
        ListNode* n2 = n1->next;
        
        ListNode* ret = n2;
        
        if (n1 && n2){
            ListNode* tmp = n1->next;
            n1->next = n2->next;
            n2->next = n1;    
            
            n1->next = swapPairs(n1->next);
            return ret;
        }
        else
            return n1;
    }
};
