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
 
 //problem URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        ListNode *tmp = nullptr;
        ListNode *cur = head;
        
        int last_num    = -1000;
        unordered_set<int> dup;
        
        while(cur != nullptr){
            if (last_num == cur->val){
                dup.insert(cur->val); 
            }
            last_num = cur->val;
            cur = cur->next;
        }
        
        cur = head;
        while(cur != nullptr){
            tmp = cur->next;
            while(tmp != nullptr && dup.find(tmp->val) != dup.end()){
                tmp = tmp->next;
            }
            cur->next = tmp;
            if (dup.find(head->val) != dup.end()){
                head = tmp;
            }
            cur = cur->next;
        }
        
        return head;
    }
};
